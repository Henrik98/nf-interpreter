//
// Copyright (c) 2019 The nanoFramework project contributors
// See LICENSE file in the project root for full license information.
//

#include <nanoHAL.h>
#include <ti/sysbios/knl/Clock.h>

// Converts FreeRTOS Tickcount to .NET ticks (100 nanoseconds)
uint64_t HAL_Time_SysTicksToTime(unsigned int sysTicks) 
{
    //return (((int64_t)sysTicks * (int64_t)1000000 + (int64_t)configTICK_RATE_HZ - 1) / (int64_t)configTICK_RATE_HZ) * 10;
    // return ((int64_t)sysTicks * (int64_t)Clock_tickPeriod) * 10;
    // Clock_tickPeriod is the Clock period in microseconds
    return (((int64_t)sysTicks * (int64_t)1000000 + (int64_t)Clock_tickPeriod - 1) / (int64_t)Clock_tickPeriod) * 10;
}

// because HAL_Time_SysTicksToTime needs to be called from C we need a proxy to allow it to be called from 'C' code
extern "C" {
    
    uint64_t HAL_Time_SysTicksToTime_C(unsigned int sysTicks)
    {
        return HAL_Time_SysTicksToTime(sysTicks);
    }
}
