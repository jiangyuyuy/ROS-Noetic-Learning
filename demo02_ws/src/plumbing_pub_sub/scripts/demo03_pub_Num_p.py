#! /usr/bin/env python
"""
    发布方:
        循环发送消息

"""
import rospy
from plumbing_pub_sub.msg import Num

if __name__ == "__main__":
    #1.初始化 ROS 节点
    rospy.init_node("Num_node_pub")
    #2.创建发布者对象
    pub = rospy.Publisher("Num_topic", Num, queue_size=10)
    #3.组织消息
    p = Num()
    p.last_name = "Yu"
    p.first_name = "Jiang"
    p.age = 24
    p.score = 398

    name = p.first_name + p.last_name

    #4.编写消息发布逻辑
    rate = rospy.Rate(2)
    
    while not rospy.is_shutdown():
        pub.publish(p)  #发布消息
        rate.sleep()  #休眠
        rospy.loginfo(f"姓名: {name}, 年龄: {p.age}, 分数: {p.score}")
        p.age += 1
        p.score += 1
