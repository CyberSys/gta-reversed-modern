/*
    Plugin-SDK file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

enum eVehicleHandlingModelFlags : uint32 {
    VEHICLE_HANDLING_MODEL_NONE = 0x0,
    VEHICLE_HANDLING_MODEL_IS_VAN = 0x1,
    VEHICLE_HANDLING_MODEL_IS_BUS = 0x2,
    VEHICLE_HANDLING_MODEL_IS_LOW = 0x4,
    VEHICLE_HANDLING_MODEL_IS_BIG = 0x8,
    VEHICLE_HANDLING_MODEL_REVERSE_BONNET = 0x10,
    VEHICLE_HANDLING_MODEL_HANGING_BOOT = 0x20,
    VEHICLE_HANDLING_MODEL_TAILGATE_BOOT = 0x40,
    VEHICLE_HANDLING_MODEL_NOSWING_BOOT = 0x80,
    VEHICLE_HANDLING_MODEL_NO_DOORS = 0x100,
    VEHICLE_HANDLING_MODEL_TANDEM_SEATS = 0x200,
    VEHICLE_HANDLING_MODEL_SIT_IN_BOAT = 0x400,
    VEHICLE_HANDLING_MODEL_CONVERTIBLE = 0x800,
    VEHICLE_HANDLING_MODEL_NO_EXHAUST = 0x1000,
    VEHICLE_HANDLING_MODEL_DOUBLE_EXHAUST = 0x2000,
    VEHICLE_HANDLING_MODEL_NO1FPS_LOOK_BEHIND = 0x4000,
    VEHICLE_HANDLING_MODEL_FORCE_DOOR_CHECK = 0x8000,
    VEHICLE_HANDLING_MODEL_AXLE_F_NOTILT = 0x10000,
    VEHICLE_HANDLING_MODEL_AXLE_F_SOLID = 0x20000,
    VEHICLE_HANDLING_MODEL_AXLE_F_MCPHERSON = 0x40000,
    VEHICLE_HANDLING_MODEL_AXLE_F_REVERSE = 0x80000,
    VEHICLE_HANDLING_MODEL_AXLE_R_NOTILT = 0x100000,
    VEHICLE_HANDLING_MODEL_AXLE_R_SOLID = 0x200000,
    VEHICLE_HANDLING_MODEL_AXLE_R_MCPHERSON = 0x400000,
    VEHICLE_HANDLING_MODEL_AXLE_R_REVERSE = 0x800000,
    VEHICLE_HANDLING_MODEL_IS_BIKE = 0x1000000,
    VEHICLE_HANDLING_MODEL_IS_HELI = 0x2000000,
    VEHICLE_HANDLING_MODEL_IS_PLANE = 0x4000000,
    VEHICLE_HANDLING_MODEL_IS_BOAT = 0x8000000,
    VEHICLE_HANDLING_MODEL_BOUNCE_PANELS = 0x10000000,
    VEHICLE_HANDLING_MODEL_DOUBLE_RWHEELS = 0x20000000,
    VEHICLE_HANDLING_MODEL_FORCE_GROUND_CLEARANCE = 0x40000000,
    VEHICLE_HANDLING_MODEL_IS_HATCHBACK = 0x80000000
};
