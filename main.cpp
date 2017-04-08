#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>


#include <cv.h>
#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>


// header files aby mi fungovali filesystem calls na directory
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;


DIR *dp;
struct dirent *dirp;
struct stat filestat;
string filepath, dir;
ifstream fin;
int num;
/// Global variables

int threshold_value = 0;
int const max_value = 255;

int threshold_value2 = 255;
int const max_value2 = 255;

int threshold_type = 3;
int const max_type = 4;

int const max_BINARY_value = 255;

Mat image, converted, thresholded;
char* window_name = "Threshold Demo";

char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
char* trackbar_value = "Minimalna vzdialenost";
char* trackbar_value2 = "Maximalna vzdialenost";

/// Function headers
void Threshold_Demo( int, void* );


void Threshold_Demo( int, void* )
{
  /*printf("0: Binary\n"); 
   printf("1: Binary Inverted\n");   
   printf("2: Threshold Truncated\n");   
   printf("3: Threshold to Zero\n");   
    printf("4: Threshold to Zero Inverted\n");  
*/
   
    std::cout << "Threshold_Demo!" << std::endl;
  if(! converted.empty()){
     
     threshold( converted, thresholded, threshold_value, max_BINARY_value,3);
     threshold( thresholded, thresholded, threshold_value2, max_BINARY_value,4);

     imshow( window_name, thresholded );
     std::cout << "Image display!" << threshold_value << std::endl;

  }
 
}

/**
 * @function main
 */
int main( int argc, char** argv )
{
 
  cout << "Vyber si, aké gesto chceš vidieť:"<< endl;
  cout << "1:Gesto STOP"<< endl;
  cout << "2:Gesto OK"<< endl;
  cout << "3:Gesto VICTORY"<< endl;
    
  int typ_gesta ;
  cin >> typ_gesta;

  switch(typ_gesta) {
    
    case 1 :
      cout << "Vybral si si gesto STOP" << endl; 
      
      dir = "dataset/depth/Stop";
      dp = opendir(dir.c_str());
        
        if (dp == NULL) {
          cout << "Error(" << errno << ") opening " << endl;
        return errno;
        }

      namedWindow(window_name, CV_WINDOW_AUTOSIZE );
      createTrackbar( trackbar_value,window_name, &threshold_value, max_value, Threshold_Demo);
      createTrackbar( trackbar_value2, window_name, &threshold_value2, max_value2, Threshold_Demo);

      while ((dirp = readdir( dp ))) {
        filepath = dir + "/" + dirp->d_name;

      // If the file is a directory (or is in some way invalid) we'll skip it 
        if (stat( filepath.c_str(), &filestat )) continue;
        if (S_ISDIR( filestat.st_mode ))         continue;

      std::cout << dir + "/" + dirp->d_name << std::endl;
      image = imread(dir + "/" + dirp->d_name, cv::IMREAD_UNCHANGED);
    
      if(!image.data ){
        printf( " No image data \n " );
      return -1;
      }

      image.convertTo(converted, CV_8UC1, 255.0/2048.0);
    
      threshold( converted, thresholded, threshold_value, max_BINARY_value,3);
      threshold( thresholded, thresholded, threshold_value2, max_BINARY_value,4);

      imshow( window_name, thresholded );
    // waitKey(1);
      waitKey(0);

      std::cout << dirp->d_name  <<std::endl;
  }
  
    closedir( dp );
    waitKey(0);

  break;
   
  case 2 :
    cout << "Vybral si si gesto OK"<< endl;
    dir = "dataset/depth/Ok";
    dp = opendir(dir.c_str());

      if (dp == NULL) {
        cout << "Error(" << errno << ") opening " << endl;
      return errno;
      }

    namedWindow(window_name, CV_WINDOW_AUTOSIZE );
    createTrackbar( trackbar_value,window_name, &threshold_value, max_value, Threshold_Demo);
    createTrackbar( trackbar_value2, window_name, &threshold_value2, max_value2, Threshold_Demo);
  // Threshold_Demo( 0, 0 );

    while ((dirp = readdir( dp ))) {
      filepath = dir + "/" + dirp->d_name;

    // If the file is a directory (or is in some way invalid) we'll skip it 
      if (stat( filepath.c_str(), &filestat )) continue;
      if (S_ISDIR( filestat.st_mode ))         continue;

      std::cout << dir + "/" + dirp->d_name << std::endl;
      image = imread(dir + "/" + dirp->d_name, cv::IMREAD_UNCHANGED);
    
      if(!image.data ){
        printf( " No image data \n " );
      return -1;
      }

    image.convertTo(converted, CV_8UC1, 255.0/2048.0);
    
    threshold( converted, thresholded, threshold_value, max_BINARY_value,3);
    threshold( thresholded, thresholded, threshold_value2, max_BINARY_value,4);

    imshow( window_name, thresholded );
    // waitKey(0);
    waitKey(0);

    std::cout << dirp->d_name  <<std::endl;
  }
  
  closedir( dp );
  waitKey(0);

  break;

  case 3 :
    cout << "Vybral si si gesto VICTORY" << endl;
    dir = "dataset/depth/Victory";
    dp = opendir(dir.c_str());
  
      if (dp == NULL) {
        cout << "Error(" << errno << ") opening " << endl;
      return errno;
      }

    namedWindow(window_name, CV_WINDOW_AUTOSIZE );
    createTrackbar( trackbar_value,window_name, &threshold_value, max_value, Threshold_Demo);
    createTrackbar( trackbar_value2, window_name, &threshold_value2, max_value2, Threshold_Demo);
  // Threshold_Demo( 0, 0 );

    while ((dirp = readdir( dp ))) {
      filepath = dir + "/" + dirp->d_name;

    // If the file is a directory (or is in some way invalid) we'll skip it 
      if (stat( filepath.c_str(), &filestat )) continue;
      if (S_ISDIR( filestat.st_mode ))         continue;

      std::cout << dir + "/" + dirp->d_name << std::endl;
      image = imread(dir + "/" + dirp->d_name, cv::IMREAD_UNCHANGED);
    
      if(!image.data ){
        printf( " No image data \n " );
      return -1;
      }

    image.convertTo(converted, CV_8UC1, 255.0/2048.0);
    
    threshold( converted, thresholded, threshold_value, max_BINARY_value,3);
    threshold( thresholded, thresholded, threshold_value2, max_BINARY_value,4);

    imshow( window_name, thresholded );
    // waitKey(0);
    waitKey(0);

    std::cout << dirp->d_name  <<std::endl;
  }
  
    closedir( dp );
    waitKey(0);

  break;
      
  default :
        cout << "Zly vstup" << endl;
   }
	

  
 return 0;
}

