#include <ros/ros.h>
#include "std_msgs/String.h"
#include <stdlib.h> 
#include <sstream>

int main(int argc, char **argv) {
     //Initializes ROS, and sets up a node
     ros::init(argc, argv, "PR_test");
     ros::NodeHandle nh;

     //Ceates the publisher, and tells it to publish
     //to the husky/cmd_vel topic, with a queue size of 100
     ros::Publisher pub=nh.advertise<geometry_msgs::Twist>("sensor/ultra", 100);

     //Sets the loop to publish at a rate of 10Hz
     ros::Rate rate(10);

       while(ros::ok()) {
            //Declares the message to be sent
            std_msgs::String msg;
			
			std::stringstream ss;
			ss << "hello world " << count;
			msg.data = ss.str();

           //Publish the message
           pub.publish(msg);

          //Delays untill it is time to send another message
          rate.sleep();
         }
}