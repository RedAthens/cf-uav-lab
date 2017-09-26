//
// File: MultiARDroneCtrl.cpp
//
// Code generated for Simulink model 'MultiARDroneCtrl'.
//
// Model version                  : 1.328
// Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
// C/C++ source code generated on : Mon Sep 25 16:12:42 2017
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "MultiARDroneCtrl.h"
#include "MultiARDroneCtrl_private.h"
#define MultiARDroneCtr_MessageQueueLen (1)

// Block signals (auto storage)
B_MultiARDroneCtrl_T MultiARDroneCtrl_B;

// Block states (auto storage)
DW_MultiARDroneCtrl_T MultiARDroneCtrl_DW;

// Real-time model
RT_MODEL_MultiARDroneCtrl_T MultiARDroneCtrl_M_;
RT_MODEL_MultiARDroneCtrl_T *const MultiARDroneCtrl_M = &MultiARDroneCtrl_M_;

//
// System initialize for atomic system:
//    '<S1>/Waypoint manager '
//    '<S2>/Waypoint manager '
//    '<S3>/Waypoint manager '
//
void MultiARDro_Waypointmanager_Init(DW_Waypointmanager_MultiARDro_T *localDW)
{
  // '<S13>:1:7' wpointer = 1;
  localDW->wpointer = 1.0;

  // '<S13>:1:11' t0 = 0;
  localDW->t0 = 0.0;
}

//
// Output and update for atomic system:
//    '<S1>/Waypoint manager '
//    '<S2>/Waypoint manager '
//    '<S3>/Waypoint manager '
//
void MultiARDroneCtr_Waypointmanager(const real_T rtu_waypoint[20], real_T
  rtu_X_e, real_T rtu_Y_e, real_T rtu_Z_e, real_T rtu_time,
  B_Waypointmanager_MultiARDron_T *localB, DW_Waypointmanager_MultiARDro_T
  *localDW)
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  int32_T tmp;

  // MATLAB Function 'Decising Making1/Waypoint manager ': '<S13>:1'
  // '<S13>:1:2' nPoints = size(waypoint, 2) ;
  // '<S13>:1:6' if isempty(wpointer)
  // '<S13>:1:10' if isempty(t0)
  // '<S13>:1:14' if ( norm([X_e,Y_e,Z_e]' - waypoint(1:3, wpointer) )< 0.3)
  tmp = (int32_T)localDW->wpointer;
  scale = 2.2250738585072014E-308;
  absxk = fabs(rtu_X_e - rtu_waypoint[(tmp - 1) * 5]);
  if (absxk > 2.2250738585072014E-308) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 2.2250738585072014E-308;
    y = t * t;
  }

  absxk = fabs(rtu_Y_e - rtu_waypoint[(tmp - 1) * 5 + 1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(rtu_Z_e - rtu_waypoint[(tmp - 1) * 5 + 2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  y = scale * sqrt(y);
  if (y < 0.3) {
    // '<S13>:1:15' yaw_d = waypoint(4, wpointer) ;
    localB->yaw_d = rtu_waypoint[((int32_T)localDW->wpointer - 1) * 5 + 3];

    //  当飞机进入目标航路点时，
    //  开始把当前航路点的期望偏航角赋值给控制器，
    //  控制机头指向下一个航路点
    // '<S13>:1:19' if(wpointer ~= nPoints)
    if (localDW->wpointer != 4.0) {
      // '<S13>:1:20' if (t0 ==0)
      if (localDW->t0 == 0.0) {
        // '<S13>:1:21' t0 = time;
        localDW->t0 = rtu_time;
      } else {
        // '<S13>:1:22' else
        // '<S13>:1:23' if ((time - t0 > waypoint(5, wpointer)))
        if ((rtu_time - localDW->t0 > rtu_waypoint[((int32_T)localDW->wpointer -
              1) * 5 + 4]) && (localDW->wpointer < 4.0)) {
          //  严格来说飞机在当前航路点的悬停时间
          //  应该要足以把偏航角控制到位
          //  或者在判断语句中加入偏航角控制到位的判断
          // '<S13>:1:26' if(wpointer < nPoints)
          // '<S13>:1:27' wpointer = wpointer+ 1;
          localDW->wpointer++;

          // '<S13>:1:28' t0 = 0;
          localDW->t0 = 0.0;
        } else {
          // '<S13>:1:29' else
          // '<S13>:1:30' disp('The flight task is finished!');
          // '<S13>:1:31' disp('The flight task is finished!');
          // '<S13>:1:32' disp('The flight task is finished!');
          // '<S13>:1:33' disp('The flight task is finished!');
          // '<S13>:1:34' disp('The flight task is finished!');
        }
      }
    }
  } else {
    // '<S13>:1:40' else
    //  如果飞机离开当前航路点，飞向下一个航路点，waypoint
    //  应该继续把当前航路点的期望偏航角赋值给控制器，waypoint 
    //  因为飞机需要在飞行过程中继续指向下一个航路点
    // '<S13>:1:43' if(wpointer>1)
    if (localDW->wpointer > 1.0) {
      // '<S13>:1:44' yaw_d = waypoint(4, wpointer-1) ;
      localB->yaw_d = rtu_waypoint[((int32_T)(localDW->wpointer - 1.0) - 1) * 5
        + 3];
    } else {
      // '<S13>:1:45' else
      // '<S13>:1:46' yaw_d = 0;
      localB->yaw_d = 0.0;
    }
  }

  //  Outputs
  // '<S13>:1:50' Z_d =  waypoint(3, wpointer);
  localB->Z_d = rtu_waypoint[((int32_T)localDW->wpointer - 1) * 5 + 2];

  // Z_d = 1.2;
  // '<S13>:1:52' X_d = waypoint(1, wpointer) ;
  localB->X_d = rtu_waypoint[((int32_T)localDW->wpointer - 1) * 5];

  // '<S13>:1:53' Y_d = waypoint(2, wpointer) ;
  localB->Y_d = rtu_waypoint[((int32_T)localDW->wpointer - 1) * 5 + 1];

  // '<S13>:1:54' waypointNumber = wpointer ;
}

//
// Output and update for atomic system:
//    '<S4>/Coordinate trnasformation  from inertial frame to body frame '
//    '<S5>/Coordinate trnasformation  from inertial frame to body frame '
//    '<S6>/Coordinate trnasformation  from inertial frame to body frame '
//
void Coordinatetrnasformationfromine(real_T rtu_Vec_i, real_T rtu_Vec_i_m,
  real_T rtu_psi, B_Coordinatetrnasformationfro_T *localB)
{
  // MATLAB Function 'Position Controller1/Coordinate trnasformation  from inertial frame to body frame ': '<S16>:1' 
  // '<S16>:1:3' T = [cos(psi) sin(psi) ; -sin(psi) cos(psi)] ;
  // '<S16>:1:4' Vec_xy = T*Vec_i(1:2,1);
  localB->Vec_xy[0] = 0.0;

  // SignalConversion: '<S16>/TmpSignal ConversionAt SFunction Inport1'
  localB->Vec_xy[0] += cos(rtu_psi) * rtu_Vec_i;
  localB->Vec_xy[0] += sin(rtu_psi) * rtu_Vec_i_m;
  localB->Vec_xy[1] = 0.0;

  // SignalConversion: '<S16>/TmpSignal ConversionAt SFunction Inport1'
  localB->Vec_xy[1] += -sin(rtu_psi) * rtu_Vec_i;
  localB->Vec_xy[1] += cos(rtu_psi) * rtu_Vec_i_m;
}

//
// Output and update for atomic system:
//    '<S4>/MATLAB Function'
//    '<S5>/MATLAB Function'
//    '<S6>/MATLAB Function'
//
void MultiARDroneCtrl_MATLABFunction(const real_T rtu_u[2], real_T rtu_a,
  B_MATLABFunction_MultiARDrone_T *localB)
{
  real_T temp;
  real_T absx;
  int32_T k;
  boolean_T exitg1;

  // MATLAB Function 'Position Controller1/MATLAB Function': '<S17>:1'
  // '<S17>:1:2' y = satgd(u,a);
  // 'satgd:2' temp = norm(x,Inf);
  temp = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    absx = fabs(rtu_u[k]);
    if (rtIsNaN(absx)) {
      temp = (rtNaN);
      exitg1 = true;
    } else {
      if (absx > temp) {
        temp = absx;
      }

      k++;
    }
  }

  // 'satgd:3' if  temp<=a
  if (temp <= rtu_a) {
    // 'satgd:4' y = x;
    localB->y[0] = rtu_u[0];
    localB->y[1] = rtu_u[1];
  } else {
    // 'satgd:5' else
    // 'satgd:6' y= a*x/temp;
    localB->y[0] = rtu_a * rtu_u[0] / temp;
    localB->y[1] = rtu_a * rtu_u[1] / temp;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2((real_T)u0_0, (real_T)u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

//
// System initialize for enable system:
//    '<S10>/pose'
//    '<S11>/pose'
//    '<S12>/pose'
//
void MultiARDroneCtrl_pose_Init(B_pose_MultiARDroneCtrl_T *localB,
  P_pose_MultiARDroneCtrl_T *localP)
{
  // SystemInitialize for Outport: '<S28>/Out1'
  localB->x = localP->Out1_Y0;
  localB->y = localP->Out1_Y0;
  localB->z = localP->Out1_Y0;
  localB->yaw = localP->Out1_Y0;
}

//
// Output and update for enable system:
//    '<S10>/pose'
//    '<S11>/pose'
//    '<S12>/pose'
//
void MultiARDroneCtrl_pose(boolean_T rtu_Enable, const
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped *rtu_In1,
  B_pose_MultiARDroneCtrl_T *localB)
{
  // Outputs for Enabled SubSystem: '<S10>/pose' incorporates:
  //   EnablePort: '<S28>/Enable'

  if (rtu_Enable) {
    // SignalConversion: '<S28>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
    //   MATLAB Function: '<S28>/ '

    // MATLAB Function 'navigation data 1/pose/ ': '<S32>:1'
    // '<S32>:1:2' x = - mocap_Y;
    // '<S32>:1:3' y = - mocap_X;
    // '<S32>:1:4' z = mocap_Z;
    // MATLAB Function 'navigation data 1/pose/ Function': '<S33>:1'
    // '<S33>:1:2' t0 = -2.0 * (y * y + z * z) + 1.0;
    // '<S33>:1:3' t1 = +2.0 * (x * y + w * z);
    // '<S33>:1:4' t2 = -2.0 * (x * z - w * y);
    // '<S33>:1:5' t3 = +2.0 * (y * z + w * x);
    // '<S33>:1:6' t4 = -2.0 * (x * x + y * y) + 1.0;
    // '<S33>:1:8' roll = -asin(t2);
    // '<S33>:1:9' pitch = -atan2(t3, t4);
    // '<S33>:1:10' yaw= -atan2(t1, t0);
    localB->x = -rtu_In1->Pose.Position.Y;

    // SignalConversion: '<S28>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
    //   MATLAB Function: '<S28>/ '

    localB->y = -rtu_In1->Pose.Position.X;

    // SignalConversion: '<S28>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
    //   MATLAB Function: '<S28>/ '

    localB->z = rtu_In1->Pose.Position.Z;

    // SignalConversion: '<S28>/BusConversion_InsertedFor_Out1_at_inport_0' incorporates:
    //   MATLAB Function: '<S28>/ Function'

    localB->yaw = -rt_atan2d_snf((rtu_In1->Pose.Orientation.X *
      rtu_In1->Pose.Orientation.Y + rtu_In1->Pose.Orientation.W *
      rtu_In1->Pose.Orientation.Z) * 2.0, (rtu_In1->Pose.Orientation.Y *
      rtu_In1->Pose.Orientation.Y + rtu_In1->Pose.Orientation.Z *
      rtu_In1->Pose.Orientation.Z) * -2.0 + 1.0);
  }

  // End of Outputs for SubSystem: '<S10>/pose'
}

//
// System initialize for enable system:
//    '<S10>/vel'
//    '<S11>/vel'
//    '<S12>/vel'
//
void MultiARDroneCtrl_vel_Init(B_vel_MultiARDroneCtrl_T *localB,
  P_vel_MultiARDroneCtrl_T *localP)
{
  // SystemInitialize for Outport: '<S31>/Vel '
  localB->vx = localP->Vel_Y0;
  localB->vy = localP->Vel_Y0;
  localB->vz = localP->Vel_Y0;
}

//
// Output and update for enable system:
//    '<S10>/vel'
//    '<S11>/vel'
//    '<S12>/vel'
//
void MultiARDroneCtrl_vel(boolean_T rtu_Enable, const
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped *rtu_In1,
  B_vel_MultiARDroneCtrl_T *localB)
{
  // Outputs for Enabled SubSystem: '<S10>/vel' incorporates:
  //   EnablePort: '<S31>/Enable'

  if (rtu_Enable) {
    // SignalConversion: '<S31>/BusConversion_InsertedFor_Vel _at_inport_0' incorporates:
    //   MATLAB Function: '<S31>/ '

    // MATLAB Function 'navigation data 1/vel/ ': '<S36>:1'
    // '<S36>:1:2' vx = - mocap_Y;
    // '<S36>:1:3' vy = - mocap_X;
    // '<S36>:1:4' vz = mocap_Z;
    localB->vx = -rtu_In1->Point.Y;

    // SignalConversion: '<S31>/BusConversion_InsertedFor_Vel _at_inport_0' incorporates:
    //   MATLAB Function: '<S31>/ '

    localB->vy = -rtu_In1->Point.X;

    // SignalConversion: '<S31>/BusConversion_InsertedFor_Vel _at_inport_0' incorporates:
    //   MATLAB Function: '<S31>/ '

    localB->vz = rtu_In1->Point.Z;
  }

  // End of Outputs for SubSystem: '<S10>/vel'
}

// Model step function
void MultiARDroneCtrl_step(void)
{
  boolean_T varargout_1;

  // Outputs for Atomic SubSystem: '<S10>/subscribe pose'
  // Start for MATLABSystem: '<S29>/SourceBlock' incorporates:
  //   Inport: '<S34>/In1'
  //   MATLABSystem: '<S29>/SourceBlock'

  varargout_1 = Sub_MultiARDroneCtrl_313.getLatestMessage
    (&MultiARDroneCtrl_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S29>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S34>/Enable'

  if (varargout_1) {
    MultiARDroneCtrl_B.In1_fo = MultiARDroneCtrl_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S29>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S10>/pose'
  MultiARDroneCtrl_pose(varargout_1, &MultiARDroneCtrl_B.In1_fo,
                        &MultiARDroneCtrl_B.pose);

  // End of Start for MATLABSystem: '<S29>/SourceBlock'

  // End of Outputs for SubSystem: '<S10>/pose'

  // End of Outputs for SubSystem: '<S10>/subscribe pose'

  // MATLAB Function: '<S1>/Waypoint manager ' incorporates:
  //   Clock: '<Root>/Clock1'
  //   Constant: '<S1>/Constant5'

  MultiARDroneCtr_Waypointmanager(MultiARDroneCtrl_P.waypoints1,
    MultiARDroneCtrl_B.pose.x, MultiARDroneCtrl_B.pose.y,
    MultiARDroneCtrl_B.pose.z, MultiARDroneCtrl_M->Timing.t[0],
    &MultiARDroneCtrl_B.sf_Waypointmanager,
    &MultiARDroneCtrl_DW.sf_Waypointmanager);

  // Outputs for Atomic SubSystem: '<S10>/subscribe vel'
  // Start for MATLABSystem: '<S30>/SourceBlock' incorporates:
  //   Inport: '<S35>/In1'
  //   MATLABSystem: '<S30>/SourceBlock'

  varargout_1 = Sub_MultiARDroneCtrl_314.getLatestMessage
    (&MultiARDroneCtrl_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S35>/Enable'

  if (varargout_1) {
    MultiARDroneCtrl_B.In1_b = MultiARDroneCtrl_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S30>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S10>/vel'
  MultiARDroneCtrl_vel(varargout_1, &MultiARDroneCtrl_B.In1_b,
                       &MultiARDroneCtrl_B.vel);

  // End of Start for MATLABSystem: '<S30>/SourceBlock'

  // End of Outputs for SubSystem: '<S10>/vel'

  // End of Outputs for SubSystem: '<S10>/subscribe vel'

  // MATLAB Function: '<S4>/Coordinate trnasformation  from inertial frame to body frame ' incorporates:
  //   Gain: '<S4>/Vx-d1'
  //   Gain: '<S4>/Vx-d2'
  //   Gain: '<S4>/kxp1'
  //   Gain: '<S4>/kxp2'
  //   Sum: '<S4>/Sum2'
  //   Sum: '<S4>/Sum4'
  //   Sum: '<S4>/Sum5'
  //   Sum: '<S4>/Sum7'

  Coordinatetrnasformationfromine(MultiARDroneCtrl_P.k_p_xy *
    (MultiARDroneCtrl_B.sf_Waypointmanager.X_d - MultiARDroneCtrl_B.pose.x) -
    MultiARDroneCtrl_P.k_d_xy * MultiARDroneCtrl_B.vel.vx,
    MultiARDroneCtrl_P.k_p_xy * (MultiARDroneCtrl_B.sf_Waypointmanager.Y_d -
    MultiARDroneCtrl_B.pose.y) - MultiARDroneCtrl_P.k_d_xy *
    MultiARDroneCtrl_B.vel.vy, MultiARDroneCtrl_B.pose.yaw,
    &MultiARDroneCtrl_B.sf_Coordinatetrnasformationfrom);

  // MATLAB Function: '<S4>/MATLAB Function' incorporates:
  //   Constant: '<S4>/Constant'

  MultiARDroneCtrl_MATLABFunction
    (MultiARDroneCtrl_B.sf_Coordinatetrnasformationfrom.Vec_xy,
     MultiARDroneCtrl_P.limit_cmd_xy, &MultiARDroneCtrl_B.sf_MATLABFunction);

  // BusAssignment: '<S7>/cmdBus' incorporates:
  //   Constant: '<S7>/Constant1'
  //   Gain: '<S4>/Vx-d3'
  //   Gain: '<S4>/kxp3'
  //   Gain: '<S4>/proportional control gain - yaw'
  //   Gain: '<S7>/K'
  //   Gain: '<S7>/K1'
  //   Sum: '<S4>/Sum1'
  //   Sum: '<S4>/Sum3'
  //   Sum: '<S4>/Sum6'

  MultiARDroneCtrl_B.cmdBus.Linear.X = MultiARDroneCtrl_B.sf_MATLABFunction.y[0];
  MultiARDroneCtrl_B.cmdBus.Linear.Y = MultiARDroneCtrl_P.K_Gain *
    MultiARDroneCtrl_B.sf_MATLABFunction.y[1];
  MultiARDroneCtrl_B.cmdBus.Linear.Z =
    (MultiARDroneCtrl_B.sf_Waypointmanager.Z_d - MultiARDroneCtrl_B.pose.z) *
    MultiARDroneCtrl_P.k_p_z - MultiARDroneCtrl_P.k_d_z *
    MultiARDroneCtrl_B.vel.vz;
  MultiARDroneCtrl_B.cmdBus.Angular.Z =
    (MultiARDroneCtrl_B.sf_Waypointmanager.yaw_d - MultiARDroneCtrl_B.pose.yaw) *
    MultiARDroneCtrl_P.k_p_yaw * MultiARDroneCtrl_P.K1_Gain;
  MultiARDroneCtrl_B.cmdBus.Angular.X = MultiARDroneCtrl_P.Constant1_Value;
  MultiARDroneCtrl_B.cmdBus.Angular.Y = MultiARDroneCtrl_P.Constant1_Value;

  // Outputs for Atomic SubSystem: '<S7>/publish cmd'
  // Start for MATLABSystem: '<S23>/SinkBlock' incorporates:
  //   MATLABSystem: '<S23>/SinkBlock'

  Pub_MultiARDroneCtrl_268.publish(&MultiARDroneCtrl_B.cmdBus);

  // End of Outputs for SubSystem: '<S7>/publish cmd'

  // Outputs for Atomic SubSystem: '<S11>/subscribe pose'
  // Start for MATLABSystem: '<S38>/SourceBlock' incorporates:
  //   Inport: '<S43>/In1'
  //   MATLABSystem: '<S38>/SourceBlock'

  varargout_1 = Sub_MultiARDroneCtrl_458.getLatestMessage
    (&MultiARDroneCtrl_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S38>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S43>/Enable'

  if (varargout_1) {
    MultiARDroneCtrl_B.In1_f = MultiARDroneCtrl_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S38>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S11>/pose'
  MultiARDroneCtrl_pose(varargout_1, &MultiARDroneCtrl_B.In1_f,
                        &MultiARDroneCtrl_B.pose_f);

  // End of Start for MATLABSystem: '<S38>/SourceBlock'

  // End of Outputs for SubSystem: '<S11>/pose'

  // End of Outputs for SubSystem: '<S11>/subscribe pose'

  // MATLAB Function: '<S2>/Waypoint manager ' incorporates:
  //   Clock: '<Root>/Clock2'
  //   Constant: '<S2>/Constant5'

  MultiARDroneCtr_Waypointmanager(MultiARDroneCtrl_P.waypoints2,
    MultiARDroneCtrl_B.pose_f.x, MultiARDroneCtrl_B.pose_f.y,
    MultiARDroneCtrl_B.pose_f.z, MultiARDroneCtrl_M->Timing.t[0],
    &MultiARDroneCtrl_B.sf_Waypointmanager_e,
    &MultiARDroneCtrl_DW.sf_Waypointmanager_e);

  // Outputs for Atomic SubSystem: '<S11>/subscribe vel'
  // Start for MATLABSystem: '<S39>/SourceBlock' incorporates:
  //   Inport: '<S44>/In1'
  //   MATLABSystem: '<S39>/SourceBlock'

  varargout_1 = Sub_MultiARDroneCtrl_459.getLatestMessage
    (&MultiARDroneCtrl_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S39>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S44>/Enable'

  if (varargout_1) {
    MultiARDroneCtrl_B.In1_pg = MultiARDroneCtrl_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S39>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S11>/vel'
  MultiARDroneCtrl_vel(varargout_1, &MultiARDroneCtrl_B.In1_pg,
                       &MultiARDroneCtrl_B.vel_i);

  // End of Start for MATLABSystem: '<S39>/SourceBlock'

  // End of Outputs for SubSystem: '<S11>/vel'

  // End of Outputs for SubSystem: '<S11>/subscribe vel'

  // MATLAB Function: '<S5>/Coordinate trnasformation  from inertial frame to body frame ' incorporates:
  //   Gain: '<S5>/Vx-d1'
  //   Gain: '<S5>/Vx-d2'
  //   Gain: '<S5>/kxp1'
  //   Gain: '<S5>/kxp2'
  //   Sum: '<S5>/Sum2'
  //   Sum: '<S5>/Sum4'
  //   Sum: '<S5>/Sum5'
  //   Sum: '<S5>/Sum7'

  Coordinatetrnasformationfromine(MultiARDroneCtrl_P.k_p_xy *
    (MultiARDroneCtrl_B.sf_Waypointmanager_e.X_d - MultiARDroneCtrl_B.pose_f.x)
    - MultiARDroneCtrl_P.k_d_xy * MultiARDroneCtrl_B.vel_i.vx,
    MultiARDroneCtrl_P.k_p_xy * (MultiARDroneCtrl_B.sf_Waypointmanager_e.Y_d -
    MultiARDroneCtrl_B.pose_f.y) - MultiARDroneCtrl_P.k_d_xy *
    MultiARDroneCtrl_B.vel_i.vy, MultiARDroneCtrl_B.pose_f.yaw,
    &MultiARDroneCtrl_B.sf_Coordinatetrnasformationfr_e);

  // MATLAB Function: '<S5>/MATLAB Function' incorporates:
  //   Constant: '<S5>/Constant'

  MultiARDroneCtrl_MATLABFunction
    (MultiARDroneCtrl_B.sf_Coordinatetrnasformationfr_e.Vec_xy,
     MultiARDroneCtrl_P.limit_cmd_xy, &MultiARDroneCtrl_B.sf_MATLABFunction_f);

  // BusAssignment: '<S8>/cmdBus' incorporates:
  //   Constant: '<S8>/Constant1'
  //   Gain: '<S5>/Vx-d3'
  //   Gain: '<S5>/kxp3'
  //   Gain: '<S5>/proportional control gain - yaw'
  //   Gain: '<S8>/K'
  //   Gain: '<S8>/K1'
  //   Sum: '<S5>/Sum1'
  //   Sum: '<S5>/Sum3'
  //   Sum: '<S5>/Sum6'

  MultiARDroneCtrl_B.cmdBus_d.Linear.X =
    MultiARDroneCtrl_B.sf_MATLABFunction_f.y[0];
  MultiARDroneCtrl_B.cmdBus_d.Linear.Y = MultiARDroneCtrl_P.K_Gain_n *
    MultiARDroneCtrl_B.sf_MATLABFunction_f.y[1];
  MultiARDroneCtrl_B.cmdBus_d.Linear.Z =
    (MultiARDroneCtrl_B.sf_Waypointmanager_e.Z_d - MultiARDroneCtrl_B.pose_f.z) *
    MultiARDroneCtrl_P.k_p_z - MultiARDroneCtrl_P.k_d_z *
    MultiARDroneCtrl_B.vel_i.vz;
  MultiARDroneCtrl_B.cmdBus_d.Angular.Z =
    (MultiARDroneCtrl_B.sf_Waypointmanager_e.yaw_d -
     MultiARDroneCtrl_B.pose_f.yaw) * MultiARDroneCtrl_P.k_p_yaw *
    MultiARDroneCtrl_P.K1_Gain_k;
  MultiARDroneCtrl_B.cmdBus_d.Angular.X = MultiARDroneCtrl_P.Constant1_Value_d;
  MultiARDroneCtrl_B.cmdBus_d.Angular.Y = MultiARDroneCtrl_P.Constant1_Value_d;

  // Outputs for Atomic SubSystem: '<S8>/publish cmd'
  // Start for MATLABSystem: '<S25>/SinkBlock' incorporates:
  //   MATLABSystem: '<S25>/SinkBlock'

  Pub_MultiARDroneCtrl_448.publish(&MultiARDroneCtrl_B.cmdBus_d);

  // End of Outputs for SubSystem: '<S8>/publish cmd'

  // Outputs for Atomic SubSystem: '<S12>/subscribe pose'
  // Start for MATLABSystem: '<S47>/SourceBlock' incorporates:
  //   Inport: '<S52>/In1'
  //   MATLABSystem: '<S47>/SourceBlock'

  varargout_1 = Sub_MultiARDroneCtrl_413.getLatestMessage
    (&MultiARDroneCtrl_B.varargout_2);

  // Outputs for Enabled SubSystem: '<S47>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S52>/Enable'

  if (varargout_1) {
    MultiARDroneCtrl_B.In1 = MultiARDroneCtrl_B.varargout_2;
  }

  // End of Outputs for SubSystem: '<S47>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S12>/pose'
  MultiARDroneCtrl_pose(varargout_1, &MultiARDroneCtrl_B.In1,
                        &MultiARDroneCtrl_B.pose_l);

  // End of Start for MATLABSystem: '<S47>/SourceBlock'

  // End of Outputs for SubSystem: '<S12>/pose'

  // End of Outputs for SubSystem: '<S12>/subscribe pose'

  // MATLAB Function: '<S3>/Waypoint manager ' incorporates:
  //   Clock: '<Root>/Clock3'
  //   Constant: '<S3>/Constant5'

  MultiARDroneCtr_Waypointmanager(MultiARDroneCtrl_P.waypoints3,
    MultiARDroneCtrl_B.pose_l.x, MultiARDroneCtrl_B.pose_l.y,
    MultiARDroneCtrl_B.pose_l.z, MultiARDroneCtrl_M->Timing.t[0],
    &MultiARDroneCtrl_B.sf_Waypointmanager_o,
    &MultiARDroneCtrl_DW.sf_Waypointmanager_o);

  // Outputs for Atomic SubSystem: '<S12>/subscribe vel'
  // Start for MATLABSystem: '<S48>/SourceBlock' incorporates:
  //   Inport: '<S53>/In1'
  //   MATLABSystem: '<S48>/SourceBlock'

  varargout_1 = Sub_MultiARDroneCtrl_414.getLatestMessage
    (&MultiARDroneCtrl_B.varargout_2_m);

  // Outputs for Enabled SubSystem: '<S48>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S53>/Enable'

  if (varargout_1) {
    MultiARDroneCtrl_B.In1_p = MultiARDroneCtrl_B.varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S48>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S12>/vel'
  MultiARDroneCtrl_vel(varargout_1, &MultiARDroneCtrl_B.In1_p,
                       &MultiARDroneCtrl_B.vel_c);

  // End of Start for MATLABSystem: '<S48>/SourceBlock'

  // End of Outputs for SubSystem: '<S12>/vel'

  // End of Outputs for SubSystem: '<S12>/subscribe vel'

  // MATLAB Function: '<S6>/Coordinate trnasformation  from inertial frame to body frame ' incorporates:
  //   Gain: '<S6>/Vx-d1'
  //   Gain: '<S6>/Vx-d2'
  //   Gain: '<S6>/kxp1'
  //   Gain: '<S6>/kxp2'
  //   Sum: '<S6>/Sum2'
  //   Sum: '<S6>/Sum4'
  //   Sum: '<S6>/Sum5'
  //   Sum: '<S6>/Sum7'

  Coordinatetrnasformationfromine(MultiARDroneCtrl_P.k_p_xy *
    (MultiARDroneCtrl_B.sf_Waypointmanager_o.X_d - MultiARDroneCtrl_B.pose_l.x)
    - MultiARDroneCtrl_P.k_d_xy * MultiARDroneCtrl_B.vel_c.vx,
    MultiARDroneCtrl_P.k_p_xy * (MultiARDroneCtrl_B.sf_Waypointmanager_o.Y_d -
    MultiARDroneCtrl_B.pose_l.y) - MultiARDroneCtrl_P.k_d_xy *
    MultiARDroneCtrl_B.vel_c.vy, MultiARDroneCtrl_B.pose_l.yaw,
    &MultiARDroneCtrl_B.sf_Coordinatetrnasformationfr_m);

  // MATLAB Function: '<S6>/MATLAB Function' incorporates:
  //   Constant: '<S6>/Constant'

  MultiARDroneCtrl_MATLABFunction
    (MultiARDroneCtrl_B.sf_Coordinatetrnasformationfr_m.Vec_xy,
     MultiARDroneCtrl_P.limit_cmd_xy, &MultiARDroneCtrl_B.sf_MATLABFunction_i);

  // BusAssignment: '<S9>/cmdBus' incorporates:
  //   Constant: '<S9>/Constant1'
  //   Gain: '<S6>/Vx-d3'
  //   Gain: '<S6>/kxp3'
  //   Gain: '<S6>/proportional control gain - yaw'
  //   Gain: '<S9>/K'
  //   Gain: '<S9>/K1'
  //   Sum: '<S6>/Sum1'
  //   Sum: '<S6>/Sum3'
  //   Sum: '<S6>/Sum6'

  MultiARDroneCtrl_B.cmdBus_f.Linear.X =
    MultiARDroneCtrl_B.sf_MATLABFunction_i.y[0];
  MultiARDroneCtrl_B.cmdBus_f.Linear.Y = MultiARDroneCtrl_P.K_Gain_i *
    MultiARDroneCtrl_B.sf_MATLABFunction_i.y[1];
  MultiARDroneCtrl_B.cmdBus_f.Linear.Z =
    (MultiARDroneCtrl_B.sf_Waypointmanager_o.Z_d - MultiARDroneCtrl_B.pose_l.z) *
    MultiARDroneCtrl_P.k_p_z - MultiARDroneCtrl_P.k_d_z *
    MultiARDroneCtrl_B.vel_c.vz;
  MultiARDroneCtrl_B.cmdBus_f.Angular.Z =
    (MultiARDroneCtrl_B.sf_Waypointmanager_o.yaw_d -
     MultiARDroneCtrl_B.pose_l.yaw) * MultiARDroneCtrl_P.k_p_yaw *
    MultiARDroneCtrl_P.K1_Gain_b;
  MultiARDroneCtrl_B.cmdBus_f.Angular.X = MultiARDroneCtrl_P.Constant1_Value_h;
  MultiARDroneCtrl_B.cmdBus_f.Angular.Y = MultiARDroneCtrl_P.Constant1_Value_h;

  // Outputs for Atomic SubSystem: '<S9>/publish cmd'
  // Start for MATLABSystem: '<S27>/SinkBlock' incorporates:
  //   MATLABSystem: '<S27>/SinkBlock'

  Pub_MultiARDroneCtrl_403.publish(&MultiARDroneCtrl_B.cmdBus_f);

  // End of Outputs for SubSystem: '<S9>/publish cmd'

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  MultiARDroneCtrl_M->Timing.t[0] =
    (++MultiARDroneCtrl_M->Timing.clockTick0) *
    MultiARDroneCtrl_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.025s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.025, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    MultiARDroneCtrl_M->Timing.clockTick1++;
  }
}

// Model initialize function
void MultiARDroneCtrl_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize real-time model
  (void) memset((void *)MultiARDroneCtrl_M, 0,
                sizeof(RT_MODEL_MultiARDroneCtrl_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&MultiARDroneCtrl_M->solverInfo,
                          &MultiARDroneCtrl_M->Timing.simTimeStep);
    rtsiSetTPtr(&MultiARDroneCtrl_M->solverInfo, &rtmGetTPtr(MultiARDroneCtrl_M));
    rtsiSetStepSizePtr(&MultiARDroneCtrl_M->solverInfo,
                       &MultiARDroneCtrl_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&MultiARDroneCtrl_M->solverInfo, (&rtmGetErrorStatus
      (MultiARDroneCtrl_M)));
    rtsiSetRTModelPtr(&MultiARDroneCtrl_M->solverInfo, MultiARDroneCtrl_M);
  }

  rtsiSetSimTimeStep(&MultiARDroneCtrl_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&MultiARDroneCtrl_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(MultiARDroneCtrl_M, &MultiARDroneCtrl_M->Timing.tArray[0]);
  MultiARDroneCtrl_M->Timing.stepSize0 = 0.025;

  // block I/O
  (void) memset(((void *) &MultiARDroneCtrl_B), 0,
                sizeof(B_MultiARDroneCtrl_T));

  // states (dwork)
  (void) memset((void *)&MultiARDroneCtrl_DW, 0,
                sizeof(DW_MultiARDroneCtrl_T));

  {
    static const char_T tmp[8] = { '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[12] = { '/', 'R', 'o', 'b', 'o', 't', '_', '3',
      '/', 'v', 'e', 'l' };

    static const char_T tmp_1[13] = { '/', 'R', 'o', 'b', 'o', 't', '_', '3',
      '/', 'p', 'o', 's', 'e' };

    static const char_T tmp_2[17] = { '/', 'a', 'r', 'd', 'r', 'o', 'n', 'e',
      '3', '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_3[12] = { '/', 'R', 'o', 'b', 'o', 't', '_', '2',
      '/', 'v', 'e', 'l' };

    static const char_T tmp_4[13] = { '/', 'R', 'o', 'b', 'o', 't', '_', '2',
      '/', 'p', 'o', 's', 'e' };

    static const char_T tmp_5[17] = { '/', 'a', 'r', 'd', 'r', 'o', 'n', 'e',
      '1', '/', 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_6[12] = { '/', 'R', 'o', 'b', 'o', 't', '_', '1',
      '/', 'v', 'e', 'l' };

    static const char_T tmp_7[13] = { '/', 'R', 'o', 'b', 'o', 't', '_', '1',
      '/', 'p', 'o', 's', 'e' };

    char_T tmp_8[9];
    char_T tmp_9[18];
    char_T tmp_a[13];
    char_T tmp_b[14];
    int32_T i;

    // Start for Atomic SubSystem: '<S10>/subscribe pose'
    // Start for MATLABSystem: '<S29>/SourceBlock'
    MultiARDroneCtrl_DW.obj_a.isInitialized = 0;
    MultiARDroneCtrl_DW.obj_a.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_b[i] = tmp_7[i];
    }

    tmp_b[13] = '\x00';
    Sub_MultiARDroneCtrl_313.createSubscriber(tmp_b,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S29>/SourceBlock'
    // End of Start for SubSystem: '<S10>/subscribe pose'

    // Start for Atomic SubSystem: '<S10>/subscribe vel'
    // Start for MATLABSystem: '<S30>/SourceBlock'
    MultiARDroneCtrl_DW.obj_bl.isInitialized = 0;
    MultiARDroneCtrl_DW.obj_bl.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_a[i] = tmp_6[i];
    }

    tmp_a[12] = '\x00';
    Sub_MultiARDroneCtrl_314.createSubscriber(tmp_a,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S30>/SourceBlock'
    // End of Start for SubSystem: '<S10>/subscribe vel'

    // Start for Atomic SubSystem: '<S7>/publish cmd'
    // Start for MATLABSystem: '<S23>/SinkBlock'
    MultiARDroneCtrl_DW.obj_b.isInitialized = 0;
    MultiARDroneCtrl_DW.obj_b.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      tmp_9[i] = tmp_5[i];
    }

    tmp_9[17] = '\x00';
    Pub_MultiARDroneCtrl_268.createPublisher(tmp_9,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S23>/SinkBlock'
    // End of Start for SubSystem: '<S7>/publish cmd'

    // Start for Atomic SubSystem: '<S11>/subscribe pose'
    // Start for MATLABSystem: '<S38>/SourceBlock'
    MultiARDroneCtrl_DW.obj_e.isInitialized = 0;
    MultiARDroneCtrl_DW.obj_e.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_b[i] = tmp_4[i];
    }

    tmp_b[13] = '\x00';
    Sub_MultiARDroneCtrl_458.createSubscriber(tmp_b,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S38>/SourceBlock'
    // End of Start for SubSystem: '<S11>/subscribe pose'

    // Start for Atomic SubSystem: '<S11>/subscribe vel'
    // Start for MATLABSystem: '<S39>/SourceBlock'
    MultiARDroneCtrl_DW.obj_j.isInitialized = 0;
    MultiARDroneCtrl_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_a[i] = tmp_3[i];
    }

    tmp_a[12] = '\x00';
    Sub_MultiARDroneCtrl_459.createSubscriber(tmp_a,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S39>/SourceBlock'
    // End of Start for SubSystem: '<S11>/subscribe vel'

    // Start for Atomic SubSystem: '<S8>/publish cmd'
    // Start for MATLABSystem: '<S25>/SinkBlock'
    MultiARDroneCtrl_DW.obj_h.isInitialized = 0;
    MultiARDroneCtrl_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      tmp_9[i] = tmp_2[i];
    }

    tmp_9[17] = '\x00';
    Pub_MultiARDroneCtrl_448.createPublisher(tmp_9,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S25>/SinkBlock'
    // End of Start for SubSystem: '<S8>/publish cmd'

    // Start for Atomic SubSystem: '<S12>/subscribe pose'
    // Start for MATLABSystem: '<S47>/SourceBlock'
    MultiARDroneCtrl_DW.obj_hv.isInitialized = 0;
    MultiARDroneCtrl_DW.obj_hv.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_b[i] = tmp_1[i];
    }

    tmp_b[13] = '\x00';
    Sub_MultiARDroneCtrl_413.createSubscriber(tmp_b,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S47>/SourceBlock'
    // End of Start for SubSystem: '<S12>/subscribe pose'

    // Start for Atomic SubSystem: '<S12>/subscribe vel'
    // Start for MATLABSystem: '<S48>/SourceBlock'
    MultiARDroneCtrl_DW.obj_m.isInitialized = 0;
    MultiARDroneCtrl_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_a[i] = tmp_0[i];
    }

    tmp_a[12] = '\x00';
    Sub_MultiARDroneCtrl_414.createSubscriber(tmp_a,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S48>/SourceBlock'
    // End of Start for SubSystem: '<S12>/subscribe vel'

    // Start for Atomic SubSystem: '<S9>/publish cmd'
    // Start for MATLABSystem: '<S27>/SinkBlock'
    MultiARDroneCtrl_DW.obj.isInitialized = 0;
    MultiARDroneCtrl_DW.obj.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_8[i] = tmp[i];
    }

    tmp_8[8] = '\x00';
    Pub_MultiARDroneCtrl_403.createPublisher(tmp_8,
      MultiARDroneCtr_MessageQueueLen);

    // End of Start for MATLABSystem: '<S27>/SinkBlock'
    // End of Start for SubSystem: '<S9>/publish cmd'

    // SystemInitialize for Atomic SubSystem: '<S10>/subscribe pose'
    // SystemInitialize for Enabled SubSystem: '<S29>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S34>/Out1'
    MultiARDroneCtrl_B.In1_fo = MultiARDroneCtrl_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S29>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S10>/subscribe pose'

    // SystemInitialize for Enabled SubSystem: '<S10>/pose'
    MultiARDroneCtrl_pose_Init(&MultiARDroneCtrl_B.pose,
      (P_pose_MultiARDroneCtrl_T *)&MultiARDroneCtrl_P.pose);

    // End of SystemInitialize for SubSystem: '<S10>/pose'

    // SystemInitialize for MATLAB Function: '<S1>/Waypoint manager '
    MultiARDro_Waypointmanager_Init(&MultiARDroneCtrl_DW.sf_Waypointmanager);

    // SystemInitialize for Atomic SubSystem: '<S10>/subscribe vel'
    // SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S35>/Out1'
    MultiARDroneCtrl_B.In1_b = MultiARDroneCtrl_P.Out1_Y0_j;

    // End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S10>/subscribe vel'

    // SystemInitialize for Enabled SubSystem: '<S10>/vel'
    MultiARDroneCtrl_vel_Init(&MultiARDroneCtrl_B.vel, (P_vel_MultiARDroneCtrl_T
      *)&MultiARDroneCtrl_P.vel);

    // End of SystemInitialize for SubSystem: '<S10>/vel'

    // SystemInitialize for Atomic SubSystem: '<S11>/subscribe pose'
    // SystemInitialize for Enabled SubSystem: '<S38>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S43>/Out1'
    MultiARDroneCtrl_B.In1_f = MultiARDroneCtrl_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S38>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S11>/subscribe pose'

    // SystemInitialize for Enabled SubSystem: '<S11>/pose'
    MultiARDroneCtrl_pose_Init(&MultiARDroneCtrl_B.pose_f,
      (P_pose_MultiARDroneCtrl_T *)&MultiARDroneCtrl_P.pose_f);

    // End of SystemInitialize for SubSystem: '<S11>/pose'

    // SystemInitialize for MATLAB Function: '<S2>/Waypoint manager '
    MultiARDro_Waypointmanager_Init(&MultiARDroneCtrl_DW.sf_Waypointmanager_e);

    // SystemInitialize for Atomic SubSystem: '<S11>/subscribe vel'
    // SystemInitialize for Enabled SubSystem: '<S39>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S44>/Out1'
    MultiARDroneCtrl_B.In1_pg = MultiARDroneCtrl_P.Out1_Y0_b;

    // End of SystemInitialize for SubSystem: '<S39>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S11>/subscribe vel'

    // SystemInitialize for Enabled SubSystem: '<S11>/vel'
    MultiARDroneCtrl_vel_Init(&MultiARDroneCtrl_B.vel_i,
      (P_vel_MultiARDroneCtrl_T *)&MultiARDroneCtrl_P.vel_i);

    // End of SystemInitialize for SubSystem: '<S11>/vel'

    // SystemInitialize for Atomic SubSystem: '<S12>/subscribe pose'
    // SystemInitialize for Enabled SubSystem: '<S47>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S52>/Out1'
    MultiARDroneCtrl_B.In1 = MultiARDroneCtrl_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S47>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S12>/subscribe pose'

    // SystemInitialize for Enabled SubSystem: '<S12>/pose'
    MultiARDroneCtrl_pose_Init(&MultiARDroneCtrl_B.pose_l,
      (P_pose_MultiARDroneCtrl_T *)&MultiARDroneCtrl_P.pose_l);

    // End of SystemInitialize for SubSystem: '<S12>/pose'

    // SystemInitialize for MATLAB Function: '<S3>/Waypoint manager '
    MultiARDro_Waypointmanager_Init(&MultiARDroneCtrl_DW.sf_Waypointmanager_o);

    // SystemInitialize for Atomic SubSystem: '<S12>/subscribe vel'
    // SystemInitialize for Enabled SubSystem: '<S48>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S53>/Out1'
    MultiARDroneCtrl_B.In1_p = MultiARDroneCtrl_P.Out1_Y0_o;

    // End of SystemInitialize for SubSystem: '<S48>/Enabled Subsystem'
    // End of SystemInitialize for SubSystem: '<S12>/subscribe vel'

    // SystemInitialize for Enabled SubSystem: '<S12>/vel'
    MultiARDroneCtrl_vel_Init(&MultiARDroneCtrl_B.vel_c,
      (P_vel_MultiARDroneCtrl_T *)&MultiARDroneCtrl_P.vel_c);

    // End of SystemInitialize for SubSystem: '<S12>/vel'
  }
}

// Model terminate function
void MultiARDroneCtrl_terminate(void)
{
  // Terminate for Atomic SubSystem: '<S10>/subscribe pose'
  // Start for MATLABSystem: '<S29>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S29>/SourceBlock'

  if (MultiARDroneCtrl_DW.obj_a.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj_a.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S29>/SourceBlock'
  // End of Terminate for SubSystem: '<S10>/subscribe pose'

  // Terminate for Atomic SubSystem: '<S10>/subscribe vel'
  // Start for MATLABSystem: '<S30>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S30>/SourceBlock'

  if (MultiARDroneCtrl_DW.obj_bl.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj_bl.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S30>/SourceBlock'
  // End of Terminate for SubSystem: '<S10>/subscribe vel'

  // Terminate for Atomic SubSystem: '<S7>/publish cmd'
  // Start for MATLABSystem: '<S23>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S23>/SinkBlock'

  if (MultiARDroneCtrl_DW.obj_b.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj_b.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S23>/SinkBlock'
  // End of Terminate for SubSystem: '<S7>/publish cmd'

  // Terminate for Atomic SubSystem: '<S11>/subscribe pose'
  // Start for MATLABSystem: '<S38>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S38>/SourceBlock'

  if (MultiARDroneCtrl_DW.obj_e.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj_e.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S38>/SourceBlock'
  // End of Terminate for SubSystem: '<S11>/subscribe pose'

  // Terminate for Atomic SubSystem: '<S11>/subscribe vel'
  // Start for MATLABSystem: '<S39>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S39>/SourceBlock'

  if (MultiARDroneCtrl_DW.obj_j.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj_j.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S39>/SourceBlock'
  // End of Terminate for SubSystem: '<S11>/subscribe vel'

  // Terminate for Atomic SubSystem: '<S8>/publish cmd'
  // Start for MATLABSystem: '<S25>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S25>/SinkBlock'

  if (MultiARDroneCtrl_DW.obj_h.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj_h.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S25>/SinkBlock'
  // End of Terminate for SubSystem: '<S8>/publish cmd'

  // Terminate for Atomic SubSystem: '<S12>/subscribe pose'
  // Start for MATLABSystem: '<S47>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S47>/SourceBlock'

  if (MultiARDroneCtrl_DW.obj_hv.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj_hv.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S47>/SourceBlock'
  // End of Terminate for SubSystem: '<S12>/subscribe pose'

  // Terminate for Atomic SubSystem: '<S12>/subscribe vel'
  // Start for MATLABSystem: '<S48>/SourceBlock' incorporates:
  //   Terminate for MATLABSystem: '<S48>/SourceBlock'

  if (MultiARDroneCtrl_DW.obj_m.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj_m.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S48>/SourceBlock'
  // End of Terminate for SubSystem: '<S12>/subscribe vel'

  // Terminate for Atomic SubSystem: '<S9>/publish cmd'
  // Start for MATLABSystem: '<S27>/SinkBlock' incorporates:
  //   Terminate for MATLABSystem: '<S27>/SinkBlock'

  if (MultiARDroneCtrl_DW.obj.isInitialized == 1) {
    MultiARDroneCtrl_DW.obj.isInitialized = 2;
  }

  // End of Start for MATLABSystem: '<S27>/SinkBlock'
  // End of Terminate for SubSystem: '<S9>/publish cmd'
}

//
// File trailer for generated code.
//
// [EOF]
//
