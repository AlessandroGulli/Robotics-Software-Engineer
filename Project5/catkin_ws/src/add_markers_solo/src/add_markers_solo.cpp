#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include <cmath>

#define PICKUP     0
#define HIDING     1   
#define DROP       2
#define DONE       3

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers_alone");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  uint32_t shape = visualization_msgs::Marker::CUBE;

  int state = PICKUP;
 
  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    marker.ns = "basic_shapes";
    marker.id = 0;

    marker.type = shape;

    marker.action = visualization_msgs::Marker::ADD;

    marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;

    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    switch (state)
    {
      case PICKUP:
        marker.action = visualization_msgs::Marker::ADD;
        marker.pose.position.x = 2;
        marker.pose.position.y = 2;
        marker_pub.publish(marker);
        ROS_INFO("Picking up ... ");
        sleep(5);
        ROS_INFO("Picked up ... ");
        state = HIDING;
        break;
      
      case HIDING:
        ROS_INFO("Hiding ...");
        marker.action = visualization_msgs::Marker::DELETE;
        marker_pub.publish(marker);
        ROS_INFO("Hided ...");
        sleep(5);
        state = DROP;
        break;
      
      case DROP:
        marker.action = visualization_msgs::Marker::ADD;
        marker.pose.position.x = 4;
        marker.pose.position.y = 2;
        marker_pub.publish(marker);
        ROS_INFO("Droping out ...");
        sleep(5);
        ROS_INFO("Dropped out ...");
        state = DONE;
        break;

      default:
        break;
    }
  }

  return 0;
}