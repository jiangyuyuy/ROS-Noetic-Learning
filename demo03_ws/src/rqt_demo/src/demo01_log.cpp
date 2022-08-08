#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "log_demo");
    ros::NodeHandle nh;

    ros::Rate r(0.3);
    while(ros::ok())
    {
        ROS_DEBUG("DEBUG...");
        ROS_INFO("INFO...");
        ROS_WARN("WARN...");
        ROS_ERROR("ERROR...");
        ROS_FATAL("FATAL...");

        r.sleep();
    }
}