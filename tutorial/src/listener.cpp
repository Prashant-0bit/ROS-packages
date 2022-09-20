#include <ros/ros.h>
#include <tutorial/StringWithHeader.h>

void chatterCallback(const tutorial::StringWithHeaderConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "listener");

ros::NodeHandle n;
  
ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
 
ros::spin();
return 0;
}
