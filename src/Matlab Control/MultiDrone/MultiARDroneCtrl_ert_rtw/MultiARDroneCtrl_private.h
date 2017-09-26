//
// File: MultiARDroneCtrl_private.h
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
#ifndef RTW_HEADER_MultiARDroneCtrl_private_h_
#define RTW_HEADER_MultiARDroneCtrl_private_h_
#include "rtwtypes.h"
#include "MultiARDroneCtrl.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void MultiARDro_Waypointmanager_Init(DW_Waypointmanager_MultiARDro_T
  *localDW);
extern void MultiARDroneCtr_Waypointmanager(const real_T rtu_waypoint[20],
  real_T rtu_X_e, real_T rtu_Y_e, real_T rtu_Z_e, real_T rtu_time,
  B_Waypointmanager_MultiARDron_T *localB, DW_Waypointmanager_MultiARDro_T
  *localDW);
extern void Coordinatetrnasformationfromine(real_T rtu_Vec_i, real_T rtu_Vec_i_m,
  real_T rtu_psi, B_Coordinatetrnasformationfro_T *localB);
extern void MultiARDroneCtrl_MATLABFunction(const real_T rtu_u[2], real_T rtu_a,
  B_MATLABFunction_MultiARDrone_T *localB);
extern void MultiARDroneCtrl_pose_Init(B_pose_MultiARDroneCtrl_T *localB,
  P_pose_MultiARDroneCtrl_T *localP);
extern void MultiARDroneCtrl_pose(boolean_T rtu_Enable, const
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped *rtu_In1,
  B_pose_MultiARDroneCtrl_T *localB);
extern void MultiARDroneCtrl_vel_Init(B_vel_MultiARDroneCtrl_T *localB,
  P_vel_MultiARDroneCtrl_T *localP);
extern void MultiARDroneCtrl_vel(boolean_T rtu_Enable, const
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped *rtu_In1,
  B_vel_MultiARDroneCtrl_T *localB);

#endif                                 // RTW_HEADER_MultiARDroneCtrl_private_h_ 

//
// File trailer for generated code.
//
// [EOF]
//
