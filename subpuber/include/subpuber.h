#ifndef SUBPUBER_NODE_H
#define SUBPUBER_NODE_H

#include "ros/ros.h"
#include "sensor_msgs/CompressedImage.h"
#include "sensor_msgs/image_encodings.h"
#include <geometry_msgs/Twist.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <iostream>

class SubPuber
{
private:

  ros::NodeHandle nodeHandle;

  ros::Subscriber topicSuber0;
  ros::Publisher topicPuber0;
  ros::Subscriber topicSuber1;
  ros::Publisher topicPuber1;

  std::string subTopic0;
  std::string pubTopic0;
  std::string subTopic1;
  std::string pubTopic1;

public:

  SubPuber(){
    ros::param::get("SubTopic0", subTopic0);
    ros::param::get("PubTopic0", pubTopic0);
    ros::param::get("SubTopic1", subTopic1);
    ros::param::get("PubTopic1", pubTopic1);

    topicSuber0 = nodeHandle.subscribe(subTopic0, 1, &SubPuber::Callback0, this);
    topicPuber0 = nodeHandle.advertise<sensor_msgs::Image>(pubTopic0, 1);
    topicSuber1 = nodeHandle.subscribe(subTopic1, 1, &SubPuber::Callback1, this);
    topicPuber1 = nodeHandle.advertise<geometry_msgs::Twist>(pubTopic1, 1);
  }

  void Callback0(const sensor_msgs::ImageConstPtr &cameraImage);
  void Callback1(const geometry_msgs::Twist &cmdVel);
};

#endif