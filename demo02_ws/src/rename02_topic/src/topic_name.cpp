#include "ros/ros.h"
#include "std_msgs/String.h" //普通文本类型的消息

int main(int argc, char  *argv[])
{   
    //设置编码
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"talker");

    ros::NodeHandle nh("~");//该类封装了 ROS 中的一些常用功能

    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",10);
    ros::Publisher pub = nh.advertise<std_msgs::String>("yyy/chatter",10);
    //节点不死
    while (ros::ok()){
        ROS_INFO("starting ...");
    }
    return 0;
}
