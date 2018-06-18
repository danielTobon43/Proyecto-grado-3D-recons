//***********************************************
//HEADERS
//***********************************************
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/flann/flann.hpp>
#include <thread>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/surface/poisson.h>
#include <pcl/common/common.h>

//***********************************************
//ALIAS
//***********************************************

using Keypoints = std::vector<cv::KeyPoint>;
using Matching = std::vector<cv::DMatch>;
using Points2f = std::vector<cv::Point2f>;
using Points3f = std::vector<cv::Point3f>;

struct Feature{

    Keypoints	kps;
    Points2f	pt2D;
    cv::Mat	descriptors;

};

struct CameraData{

  cv::Mat K;
  cv::Mat invK;
  cv::Mat distCoef;
  float fx;
  float fy;
  float cx;
  float cy;

};

struct Point3D {

    cv::Point3f pt;    
    std::map<const int,int> idxImage;
    std::map<const int,cv::Point2f> pt2D;

};
