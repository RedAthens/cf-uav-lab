%%%%%%%%%%%%%%%%%%%%%%%%
%  cleaning workspace
clear;
close all;
clc

sampleTime = 0.025; 
k_p_xy = 0.18;
k_d_xy = 0.1;
k_p_z = 0.18;
k_d_z = 0.1;
k_p_yaw = 0.18;
limit_cmd_xy = 0.3;

%%%%%%%%%%%%%%%%%%%%%%%%
waypoints = getWaypoints();
uav_cmd;
SingleARDroneCtrl; 