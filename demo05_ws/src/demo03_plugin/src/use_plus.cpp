//类加载器相关的头文件
#include "pluginlib/class_loader.h"
#include "demo03_plugin/dbx_base.h"
#include "ros/ros.h"

int main(int argc, char** argv)
{

  setlocale(LC_ALL,"");
  //类加载器 -- 参数1:基类功能包名称 参数2:基类全限定名称
  pluginlib::ClassLoader<dbx_base_ns::Dbx_Base> loader("demo03_plugin", "dbx_base_ns::Dbx_Base");

  try
  {
    //创建插件类实例 -- 参数:插件类全限定名称
    boost::shared_ptr<dbx_base_ns::Dbx_Base> san = loader.createInstance("dbx_plugins_ns::SanBian");
    san->init(10);
    double length1 = san->getlength();
    ROS_INFO("triangle all length: %.2f", length1);

    boost::shared_ptr<dbx_base_ns::Dbx_Base> si = loader.createInstance("dbx_plugins_ns::SiBian");
    si->init(10);
    double length2 = si->getlength();
    ROS_INFO("triangle all length: %.2f", length2);
  }

  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load for some reason. Error: %s", ex.what());
  }

  return 0;
}
