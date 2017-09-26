function [ waypoint ] = getWaypoints1(  )
% Number of waypoints. Edit this value as desired. 
nPoints = 4;
origin_point1 = [-0.3;-1;0;0;0];
waypointsListARDrone = zeros(5,nPoints);

% waypointsListARDrone(:,k) = [ Xe (m), Ye (m), h (m) , yaw,waiting time
waypointsListARDrone(:,1) = origin_point1+[0;0;0.9;0;5] ;
waypointsListARDrone(:,2) = origin_point1+[0;0.5;1.0;0;5] ;
waypointsListARDrone(:,3) = origin_point1+[0;0;1.1;0;5] ;
waypointsListARDrone(:,4) = origin_point1+[0;-0.5;1.3;0;5] ;
% waypointsListARDrone(:,2) =[0.81;0.957;0.9;0;70] ;
% waypointsListARDrone(:,3) = [-0.098;-0.683;0.9;0;70] ; 
% waypointsListARDrone(:,4) =[-0.96;1.059;0.9;0;70] ;
% waypointsListARDrone(:,1) = [-0.901;-0.261;0.9;1.75;70] ;
% waypointsListARDrone(:,2) = [-0.932;1.043;0.9;0;70] ;
%  waypointsListARDrone(:,3) = [0.771;1.152;0.9;0;70] ;
%  waypointsListARDrone(:,4) = [0.8228;-0.257;0.9;0;70] ;
%  waypointsListARDrone(:,5) = [-0.038;0.472;0.9;1.57;70] ;

waypoint = waypointsListARDrone ; 

end


