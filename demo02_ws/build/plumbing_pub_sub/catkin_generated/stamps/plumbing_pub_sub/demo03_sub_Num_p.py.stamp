#! /usr/bin/env python
"""
    订阅方:
        订阅消息

"""
import rospy
from plumbing_pub_sub.msg import Num

def doNum(p):
    rospy.loginfo(f"接收到的信息 --> 姓名: {p.first_name+p.last_name}, 年龄: {p.age}, 分数: {p.score}")


if __name__ == "__main__":
    #1.初始化节点
    rospy.init_node("Num_node_sub")
    #2.创建订阅者对象
    sub = rospy.Subscriber("Num_topic", Num, doNum, queue_size=10)
    rospy.spin() #4.循环
