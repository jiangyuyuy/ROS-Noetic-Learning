#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc,argv,"bag_write");
    ros::NodeHandle nh;

    //创建bag对象
    rosbag::Bag bag;

    //打开
    bag.open("/home/jy/bags/test.bag", rosbag::BagMode::Write);

    ROS_INFO("start writing...");
    //写
    std_msgs::String msg;
    msg.data = "hello world";
    bag.write("/chatter", ros::Time::now(), msg);
    bag.write("/chatter", ros::Time::now(), msg);
    bag.write("/chatter", ros::Time::now(), msg);
    bag.write("/chatter", ros::Time::now(), msg);

    //关闭
    bag.close();
    return 0;
}
