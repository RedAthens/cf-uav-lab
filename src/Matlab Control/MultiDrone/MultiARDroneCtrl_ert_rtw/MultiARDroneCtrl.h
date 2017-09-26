//
// File: MultiARDroneCtrl.h
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
#ifndef RTW_HEADER_MultiARDroneCtrl_h_
#define RTW_HEADER_MultiARDroneCtrl_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef MultiARDroneCtrl_COMMON_INCLUDES_
# define MultiARDroneCtrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#endif                                 // MultiARDroneCtrl_COMMON_INCLUDES_

#include "MultiARDroneCtrl_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

// Block signals for system '<S1>/Waypoint manager '
typedef struct {
  real_T yaw_d;                        // '<S1>/Waypoint manager '
  real_T Z_d;                          // '<S1>/Waypoint manager '
  real_T X_d;                          // '<S1>/Waypoint manager '
  real_T Y_d;                          // '<S1>/Waypoint manager '
} B_Waypointmanager_MultiARDron_T;

// Block states (auto storage) for system '<S1>/Waypoint manager '
typedef struct {
  real_T wpointer;                     // '<S1>/Waypoint manager '
  real_T t0;                           // '<S1>/Waypoint manager '
} DW_Waypointmanager_MultiARDro_T;

// Block signals for system '<S4>/Coordinate trnasformation  from inertial frame to body frame ' 
typedef struct {
  real_T Vec_xy[2];                    // '<S4>/Coordinate trnasformation  from inertial frame to body frame ' 
} B_Coordinatetrnasformationfro_T;

// Block signals for system '<S4>/MATLAB Function'
typedef struct {
  real_T y[2];                         // '<S4>/MATLAB Function'
} B_MATLABFunction_MultiARDrone_T;

// Block signals for system '<S10>/pose'
typedef struct {
  real_T x;
  real_T y;
  real_T z;
  real_T yaw;
} B_pose_MultiARDroneCtrl_T;

// Block signals for system '<S10>/vel'
typedef struct {
  real_T vx;
  real_T vy;
  real_T vz;
} B_vel_MultiARDroneCtrl_T;

// Block signals (auto storage)
typedef struct {
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped In1;// '<S52>/In1'
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped In1_f;// '<S43>/In1'
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped In1_fo;// '<S34>/In1'
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped varargout_2;
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped In1_p;// '<S53>/In1'
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped In1_pg;// '<S44>/In1'
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped In1_b;// '<S35>/In1'
  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped varargout_2_m;
  SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist cmdBus_f;// '<S9>/cmdBus'
  SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist cmdBus_d;// '<S8>/cmdBus'
  SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist cmdBus;// '<S7>/cmdBus'
  B_vel_MultiARDroneCtrl_T vel_c;      // '<S12>/vel'
  B_pose_MultiARDroneCtrl_T pose_l;    // '<S12>/pose'
  B_vel_MultiARDroneCtrl_T vel_i;      // '<S11>/vel'
  B_pose_MultiARDroneCtrl_T pose_f;    // '<S11>/pose'
  B_vel_MultiARDroneCtrl_T vel;        // '<S10>/vel'
  B_pose_MultiARDroneCtrl_T pose;      // '<S10>/pose'
  B_MATLABFunction_MultiARDrone_T sf_MATLABFunction_i;// '<S6>/MATLAB Function'
  B_Coordinatetrnasformationfro_T sf_Coordinatetrnasformationfr_m;// '<S6>/Coordinate trnasformation  from inertial frame to body frame ' 
  B_MATLABFunction_MultiARDrone_T sf_MATLABFunction_f;// '<S5>/MATLAB Function'
  B_Coordinatetrnasformationfro_T sf_Coordinatetrnasformationfr_e;// '<S5>/Coordinate trnasformation  from inertial frame to body frame ' 
  B_MATLABFunction_MultiARDrone_T sf_MATLABFunction;// '<S4>/MATLAB Function'
  B_Coordinatetrnasformationfro_T sf_Coordinatetrnasformationfrom;// '<S4>/Coordinate trnasformation  from inertial frame to body frame ' 
  B_Waypointmanager_MultiARDron_T sf_Waypointmanager_o;// '<S3>/Waypoint manager ' 
  B_Waypointmanager_MultiARDron_T sf_Waypointmanager_e;// '<S2>/Waypoint manager ' 
  B_Waypointmanager_MultiARDron_T sf_Waypointmanager;// '<S1>/Waypoint manager ' 
} B_MultiARDroneCtrl_T;

// Block states (auto storage) for system '<Root>'
typedef struct {
  void *SourceBlock_PWORK;             // '<S48>/SourceBlock'
  void *SourceBlock_PWORK_e;           // '<S47>/SourceBlock'
  void *SourceBlock_PWORK_k;           // '<S39>/SourceBlock'
  void *SourceBlock_PWORK_m;           // '<S38>/SourceBlock'
  void *SourceBlock_PWORK_d;           // '<S30>/SourceBlock'
  void *SourceBlock_PWORK_kr;          // '<S29>/SourceBlock'
  void *SinkBlock_PWORK;               // '<S27>/SinkBlock'
  void *SinkBlock_PWORK_f;             // '<S25>/SinkBlock'
  void *SinkBlock_PWORK_o;             // '<S23>/SinkBlock'
  robotics_slros_internal_block_T obj; // '<S27>/SinkBlock'
  robotics_slros_internal_block_T obj_h;// '<S25>/SinkBlock'
  robotics_slros_internal_block_T obj_b;// '<S23>/SinkBlock'
  robotics_slros_internal_blo_m_T obj_m;// '<S48>/SourceBlock'
  robotics_slros_internal_blo_m_T obj_hv;// '<S47>/SourceBlock'
  robotics_slros_internal_blo_m_T obj_j;// '<S39>/SourceBlock'
  robotics_slros_internal_blo_m_T obj_e;// '<S38>/SourceBlock'
  robotics_slros_internal_blo_m_T obj_bl;// '<S30>/SourceBlock'
  robotics_slros_internal_blo_m_T obj_a;// '<S29>/SourceBlock'
  DW_Waypointmanager_MultiARDro_T sf_Waypointmanager_o;// '<S3>/Waypoint manager ' 
  DW_Waypointmanager_MultiARDro_T sf_Waypointmanager_e;// '<S2>/Waypoint manager ' 
  DW_Waypointmanager_MultiARDro_T sf_Waypointmanager;// '<S1>/Waypoint manager ' 
} DW_MultiARDroneCtrl_T;

// Parameters for system: '<S10>/pose'
struct P_pose_MultiARDroneCtrl_T_ {
  real_T Out1_Y0;                      // Computed Parameter: Out1_Y0
                                       //  Referenced by: '<S28>/Out1'

};

// Parameters for system: '<S10>/vel'
struct P_vel_MultiARDroneCtrl_T_ {
  real_T Vel_Y0;                       // Computed Parameter: Vel_Y0
                                       //  Referenced by: '<S31>/Vel '

};

// Parameters (auto storage)
struct P_MultiARDroneCtrl_T_ {
  real_T k_d_xy;                       // Variable: k_d_xy
                                       //  Referenced by:
                                       //    '<S4>/Vx-d1'
                                       //    '<S4>/Vx-d2'
                                       //    '<S5>/Vx-d1'
                                       //    '<S5>/Vx-d2'
                                       //    '<S6>/Vx-d1'
                                       //    '<S6>/Vx-d2'

  real_T k_d_z;                        // Variable: k_d_z
                                       //  Referenced by:
                                       //    '<S4>/Vx-d3'
                                       //    '<S5>/Vx-d3'
                                       //    '<S6>/Vx-d3'

  real_T k_p_xy;                       // Variable: k_p_xy
                                       //  Referenced by:
                                       //    '<S4>/kxp1'
                                       //    '<S4>/kxp2'
                                       //    '<S5>/kxp1'
                                       //    '<S5>/kxp2'
                                       //    '<S6>/kxp1'
                                       //    '<S6>/kxp2'

  real_T k_p_yaw;                      // Variable: k_p_yaw
                                       //  Referenced by:
                                       //    '<S4>/proportional control gain - yaw'
                                       //    '<S5>/proportional control gain - yaw'
                                       //    '<S6>/proportional control gain - yaw'

  real_T k_p_z;                        // Variable: k_p_z
                                       //  Referenced by:
                                       //    '<S4>/kxp3'
                                       //    '<S5>/kxp3'
                                       //    '<S6>/kxp3'

  real_T limit_cmd_xy;                 // Variable: limit_cmd_xy
                                       //  Referenced by:
                                       //    '<S4>/Constant'
                                       //    '<S5>/Constant'
                                       //    '<S6>/Constant'

  real_T waypoints1[20];               // Variable: waypoints1
                                       //  Referenced by: '<S1>/Constant5'

  real_T waypoints2[20];               // Variable: waypoints2
                                       //  Referenced by: '<S2>/Constant5'

  real_T waypoints3[20];               // Variable: waypoints3
                                       //  Referenced by: '<S3>/Constant5'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped Out1_Y0;// Computed Parameter: Out1_Y0
                                                            //  Referenced by: '<S34>/Out1'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped Constant_Value;// Computed Parameter: Constant_Value
                                                                   //  Referenced by: '<S29>/Constant'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped Out1_Y0_h;// Computed Parameter: Out1_Y0_h
                                                              //  Referenced by: '<S43>/Out1'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped Constant_Value_p;// Computed Parameter: Constant_Value_p
                                                                     //  Referenced by: '<S38>/Constant'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped Out1_Y0_i;// Computed Parameter: Out1_Y0_i
                                                              //  Referenced by: '<S52>/Out1'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PoseStamped Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                                     //  Referenced by: '<S47>/Constant'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped Out1_Y0_j;// Computed Parameter: Out1_Y0_j
                                                               //  Referenced by: '<S35>/Out1'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped Constant_Value_o;// Computed Parameter: Constant_Value_o
                                                                      //  Referenced by: '<S30>/Constant'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped Out1_Y0_b;// Computed Parameter: Out1_Y0_b
                                                               //  Referenced by: '<S44>/Out1'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped Constant_Value_g;// Computed Parameter: Constant_Value_g
                                                                      //  Referenced by: '<S39>/Constant'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped Out1_Y0_o;// Computed Parameter: Out1_Y0_o
                                                               //  Referenced by: '<S53>/Out1'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_PointStamped Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                      //  Referenced by: '<S48>/Constant'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist Constant_Value_c;// Computed Parameter: Constant_Value_c
                                                               //  Referenced by: '<S22>/Constant'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist Constant_Value_a;// Computed Parameter: Constant_Value_a
                                                               //  Referenced by: '<S24>/Constant'

  SL_Bus_MultiARDroneCtrl_geometry_msgs_Twist Constant_Value_n3;// Computed Parameter: Constant_Value_n3
                                                                //  Referenced by: '<S26>/Constant'

  real_T K_Gain;                       // Expression: -1
                                       //  Referenced by: '<S7>/K'

  real_T K1_Gain;                      // Expression: -1
                                       //  Referenced by: '<S7>/K1'

  real_T Constant1_Value;              // Expression: 0
                                       //  Referenced by: '<S7>/Constant1'

  real_T K_Gain_n;                     // Expression: -1
                                       //  Referenced by: '<S8>/K'

  real_T K1_Gain_k;                    // Expression: -1
                                       //  Referenced by: '<S8>/K1'

  real_T Constant1_Value_d;            // Expression: 0
                                       //  Referenced by: '<S8>/Constant1'

  real_T K_Gain_i;                     // Expression: -1
                                       //  Referenced by: '<S9>/K'

  real_T K1_Gain_b;                    // Expression: -1
                                       //  Referenced by: '<S9>/K1'

  real_T Constant1_Value_h;            // Expression: 0
                                       //  Referenced by: '<S9>/Constant1'

  P_vel_MultiARDroneCtrl_T vel_c;      // '<S12>/vel'
  P_pose_MultiARDroneCtrl_T pose_l;    // '<S12>/pose'
  P_vel_MultiARDroneCtrl_T vel_i;      // '<S11>/vel'
  P_pose_MultiARDroneCtrl_T pose_f;    // '<S11>/pose'
  P_vel_MultiARDroneCtrl_T vel;        // '<S10>/vel'
  P_pose_MultiARDroneCtrl_T pose;      // '<S10>/pose'
};

// Real-time Model Data Structure
struct tag_RTM_MultiARDroneCtrl_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (auto storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_MultiARDroneCtrl_T MultiARDroneCtrl_P;

#ifdef __cplusplus

}
#endif

// Block signals (auto storage)
extern B_MultiARDroneCtrl_T MultiARDroneCtrl_B;

// Block states (auto storage)
extern DW_MultiARDroneCtrl_T MultiARDroneCtrl_DW;

#ifdef __cplusplus

extern "C" {

#endif

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void MultiARDroneCtrl_initialize(void);
  extern void MultiARDroneCtrl_step(void);
  extern void MultiARDroneCtrl_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_MultiARDroneCtrl_T *const MultiARDroneCtrl_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'MultiARDroneCtrl'
//  '<S1>'   : 'MultiARDroneCtrl/Decising Making1'
//  '<S2>'   : 'MultiARDroneCtrl/Decising Making2'
//  '<S3>'   : 'MultiARDroneCtrl/Decising Making3'
//  '<S4>'   : 'MultiARDroneCtrl/Position Controller1'
//  '<S5>'   : 'MultiARDroneCtrl/Position Controller2'
//  '<S6>'   : 'MultiARDroneCtrl/Position Controller3'
//  '<S7>'   : 'MultiARDroneCtrl/Send Command 1'
//  '<S8>'   : 'MultiARDroneCtrl/Send Command 2'
//  '<S9>'   : 'MultiARDroneCtrl/Send Command 3'
//  '<S10>'  : 'MultiARDroneCtrl/navigation data 1'
//  '<S11>'  : 'MultiARDroneCtrl/navigation data 2'
//  '<S12>'  : 'MultiARDroneCtrl/navigation data 3'
//  '<S13>'  : 'MultiARDroneCtrl/Decising Making1/Waypoint manager '
//  '<S14>'  : 'MultiARDroneCtrl/Decising Making2/Waypoint manager '
//  '<S15>'  : 'MultiARDroneCtrl/Decising Making3/Waypoint manager '
//  '<S16>'  : 'MultiARDroneCtrl/Position Controller1/Coordinate trnasformation  from inertial frame to body frame '
//  '<S17>'  : 'MultiARDroneCtrl/Position Controller1/MATLAB Function'
//  '<S18>'  : 'MultiARDroneCtrl/Position Controller2/Coordinate trnasformation  from inertial frame to body frame '
//  '<S19>'  : 'MultiARDroneCtrl/Position Controller2/MATLAB Function'
//  '<S20>'  : 'MultiARDroneCtrl/Position Controller3/Coordinate trnasformation  from inertial frame to body frame '
//  '<S21>'  : 'MultiARDroneCtrl/Position Controller3/MATLAB Function'
//  '<S22>'  : 'MultiARDroneCtrl/Send Command 1/ Message'
//  '<S23>'  : 'MultiARDroneCtrl/Send Command 1/publish cmd'
//  '<S24>'  : 'MultiARDroneCtrl/Send Command 2/ Message'
//  '<S25>'  : 'MultiARDroneCtrl/Send Command 2/publish cmd'
//  '<S26>'  : 'MultiARDroneCtrl/Send Command 3/ Message'
//  '<S27>'  : 'MultiARDroneCtrl/Send Command 3/publish cmd'
//  '<S28>'  : 'MultiARDroneCtrl/navigation data 1/pose'
//  '<S29>'  : 'MultiARDroneCtrl/navigation data 1/subscribe pose'
//  '<S30>'  : 'MultiARDroneCtrl/navigation data 1/subscribe vel'
//  '<S31>'  : 'MultiARDroneCtrl/navigation data 1/vel'
//  '<S32>'  : 'MultiARDroneCtrl/navigation data 1/pose/ '
//  '<S33>'  : 'MultiARDroneCtrl/navigation data 1/pose/ Function'
//  '<S34>'  : 'MultiARDroneCtrl/navigation data 1/subscribe pose/Enabled Subsystem'
//  '<S35>'  : 'MultiARDroneCtrl/navigation data 1/subscribe vel/Enabled Subsystem'
//  '<S36>'  : 'MultiARDroneCtrl/navigation data 1/vel/ '
//  '<S37>'  : 'MultiARDroneCtrl/navigation data 2/pose'
//  '<S38>'  : 'MultiARDroneCtrl/navigation data 2/subscribe pose'
//  '<S39>'  : 'MultiARDroneCtrl/navigation data 2/subscribe vel'
//  '<S40>'  : 'MultiARDroneCtrl/navigation data 2/vel'
//  '<S41>'  : 'MultiARDroneCtrl/navigation data 2/pose/ '
//  '<S42>'  : 'MultiARDroneCtrl/navigation data 2/pose/ Function'
//  '<S43>'  : 'MultiARDroneCtrl/navigation data 2/subscribe pose/Enabled Subsystem'
//  '<S44>'  : 'MultiARDroneCtrl/navigation data 2/subscribe vel/Enabled Subsystem'
//  '<S45>'  : 'MultiARDroneCtrl/navigation data 2/vel/ '
//  '<S46>'  : 'MultiARDroneCtrl/navigation data 3/pose'
//  '<S47>'  : 'MultiARDroneCtrl/navigation data 3/subscribe pose'
//  '<S48>'  : 'MultiARDroneCtrl/navigation data 3/subscribe vel'
//  '<S49>'  : 'MultiARDroneCtrl/navigation data 3/vel'
//  '<S50>'  : 'MultiARDroneCtrl/navigation data 3/pose/ '
//  '<S51>'  : 'MultiARDroneCtrl/navigation data 3/pose/ Function'
//  '<S52>'  : 'MultiARDroneCtrl/navigation data 3/subscribe pose/Enabled Subsystem'
//  '<S53>'  : 'MultiARDroneCtrl/navigation data 3/subscribe vel/Enabled Subsystem'
//  '<S54>'  : 'MultiARDroneCtrl/navigation data 3/vel/ '

#endif                                 // RTW_HEADER_MultiARDroneCtrl_h_

//
// File trailer for generated code.
//
// [EOF]
//
