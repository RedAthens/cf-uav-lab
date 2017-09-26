// ROS includes
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PointStamped.h>

// System includes
#include <string>
using namespace std;

geometry_msgs::PointStamped vel_pub;
geometry_msgs::Point position_sub;
geometry_msgs::Point position_last;
geometry_msgs::Point velocity_last;
double dt = 1.0/120.0;
double low_pass_param;

void GetVelCallBack(const geometry_msgs::PoseStamped::ConstPtr msg);

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "get_vel_node");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");
    double low_pass_param;
    
    pnh.param("low_pass_param", low_pass_param, 0.2);
    ros::Subscriber robot_pos_sub = nh.subscribe("/Robot/pose",1000, GetVelCallBack);
    ros::Publisher  robot_vel_pub = nh.advertise<geometry_msgs::PointStamped>("/Robot/vel",1000);
    ros::Rate loopRate(120);

    position_last.x = 0.0;
    position_last.y = 0.0;
    position_last.z = 0.0;
    velocity_last.x = 0.0;
    velocity_last.y = 0.0;
    velocity_last.z = 0.0;
    
    while(ros::ok())
    {
        robot_vel_pub.publish(vel_pub);
        ros::spinOnce();
        loopRate.sleep();
    }
    return 0;
}


void GetVelCallBack(const geometry_msgs::PoseStamped::ConstPtr msg)
{
    position_sub = msg->pose.position;
    vel_pub.point.x = (position_sub.x -  position_last.x)/dt;
    vel_pub.point.y = (position_sub.y -  position_last.y)/dt;
    vel_pub.point.z = (position_sub.z -  position_last.z)/dt;

    vel_pub.header.frame_id = "robot_vel";
    vel_pub.header.stamp = ros::Time::now();
    vel_pub.point.x = low_pass_param * velocity_last.x + (1- low_pass_param)*vel_pub.point.x;
    vel_pub.point.y = low_pass_param * velocity_last.y + (1- low_pass_param)*vel_pub.point.y;
    vel_pub.point.z = low_pass_param * velocity_last.z + (1- low_pass_param)*vel_pub.point.z;

    position_last = position_sub;
    velocity_last = vel_pub.point;
}