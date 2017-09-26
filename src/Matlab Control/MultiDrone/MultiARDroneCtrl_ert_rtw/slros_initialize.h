#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block MultiARDroneCtrl/navigation data 1/subscribe pose
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped> Sub_MultiARDroneCtrl_313;

// For Block MultiARDroneCtrl/navigation data 1/subscribe vel
extern SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped> Sub_MultiARDroneCtrl_314;

// For Block MultiARDroneCtrl/navigation data 2/subscribe pose
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped> Sub_MultiARDroneCtrl_458;

// For Block MultiARDroneCtrl/navigation data 2/subscribe vel
extern SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped> Sub_MultiARDroneCtrl_459;

// For Block MultiARDroneCtrl/navigation data 3/subscribe pose
extern SimulinkSubscriber<geometry_msgs::PoseStamped, SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped> Sub_MultiARDroneCtrl_413;

// For Block MultiARDroneCtrl/navigation data 3/subscribe vel
extern SimulinkSubscriber<geometry_msgs::PointStamped, SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped> Sub_MultiARDroneCtrl_414;

// For Block MultiARDroneCtrl/Send Command 1/publish cmd
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist> Pub_MultiARDroneCtrl_268;

// For Block MultiARDroneCtrl/Send Command 2/publish cmd
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist> Pub_MultiARDroneCtrl_448;

// For Block MultiARDroneCtrl/Send Command 3/publish cmd
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist> Pub_MultiARDroneCtrl_403;

void slros_node_init(int argc, char** argv);

#endif
