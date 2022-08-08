/*
    控制台输出 HelloVSCode !!!

*/
#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    //执行节点初始化
    ros::init(argc,argv,"HelloVSCode");

    ros::NodeHandle nh;
    ros::Time right_now = ros::Time::now();
    ROS_INFO("The time: %.2f",right_now.toSec());
    ROS_INFO("The time: %d",right_now.sec);

    ros::Time t1(20, 100000000);
    ros::Time t2(100.35);
    ROS_INFO("t1 = %.2f",t1.toSec());
    ROS_INFO("t2 = %.2f",t2.toSec());

    ROS_INFO("shi jian yun suan");
    ros::Time now = ros::Time::now();
    ROS_INFO("kai shi xiu mian: %.2f",now.toSec());
    ros::Duration du(4.5);
    du.sleep();
    ros::Time end = ros::Time::now();
    ROS_INFO("xian zai xiu mian: %.2f",end.toSec());

    //输出日志
    ROS_INFO("  ");
    ROS_INFO("Hello VSCode!!!哈哈哈哈哈哈哈哈哈哈");
    ROS_INFO("  ");
    return 0;
}
