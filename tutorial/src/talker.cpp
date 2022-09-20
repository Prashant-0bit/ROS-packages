#include <ros/ros.h>
#include <iostream>
#include <tutorial/StringWithHeader.h>

int main(int argc, char**argv)
{
  ros::init(argc, argv, "talker");
  
  ros::NodeHandle n;
  
  ros::Publisher chatter_pub = n.advertise<tutorial::StringWithHeader>("chatter", 1000);
  
  ros::Rate loop_rate(10/*10Hz*/);


int count = 0;
while (ros::ok())
{
    tutorial::StringWithHeader msg;
    std::stringstream ss;
    ss << "hello world " << count; 
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    chatter_pub.publish(msg);
    ros::spinOnce();
 
    loop_rate.sleep();
    ++count;
   }

 
   return 0;
 }
