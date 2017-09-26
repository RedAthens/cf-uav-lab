%%%%%%%%%%%%%%%%%%%%%%%%
%  cleaning workspace
clear;
close all;
clc

sampleTime = 0.025; 
k_p_xy = 0.2;
k_d_xy = 0.1;
k_p_z = 0.8;
k_d_z = 0.1;
k_p_yaw = 0.5;
limit_cmd_xy = 0.3;

%%%%%%%%%%%%%%%%%%%%%%%%
waypoints1 = getWaypoints1();
waypoints2 = getWaypoints2();
waypoints3 = getWaypoints3();
ardrone_control;
MultiARDroneCtrl; 
