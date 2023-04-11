#include "subpuber.h"

void SubPuber::Callback0(const sensor_msgs::ImageConstPtr &cameraImage)
{
  cv::Mat img = cv_bridge::toCvShare(cameraImage, "bgr8")->image;
  sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", img).toImageMsg();
  topicPuber0.publish(*msg);
}

void SubPuber::Callback1(const geometry_msgs::Twist &cmdVel)
{
  topicPuber1.publish(cmdVel);
}