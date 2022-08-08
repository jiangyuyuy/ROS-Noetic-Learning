#include "plumbing_head_src/haha.h"
#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hahah");
    hello_ns::My my;
    my.run();
    return 0;
}
