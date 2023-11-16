#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "int_puplisher_node");

  ros::NodeHandle n;

  ros::Publisher int_pub = n.advertise<std_msgs::Int32>("int_count", 20);

  ros::Rate loop_rate(20);


  int count = 19;
  while (ros::ok() && count <= 100)
  {
   std_msgs::Int32 int_msg;

   int_msg.data=count;

    int_pub.publish(int_msg);
    ++count;
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
