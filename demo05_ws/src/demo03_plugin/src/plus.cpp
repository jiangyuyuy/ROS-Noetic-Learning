//pluginlib 宏，可以注册插件类
#include "pluginlib/class_list_macros.h"
#include "demo03_plugin/dbx_base.h"
#include "demo03_plugin/dbx_plugins.h"

//参数1:衍生类 参数2:基类
PLUGINLIB_EXPORT_CLASS(dbx_plugins_ns::SanBian, dbx_base_ns::Dbx_Base)
PLUGINLIB_EXPORT_CLASS(dbx_plugins_ns::SiBian, dbx_base_ns::Dbx_Base)
