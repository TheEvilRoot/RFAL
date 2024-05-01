/******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2020 STMicroelectronics</center></h2>
  *
  * Licensed under ST MYLIBERTY SOFTWARE LICENSE AGREEMENT (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/myliberty
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied,
  * AND SPECIFICALLY DISCLAIMING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
******************************************************************************/

/*! \file pltf_timer.c
 *
 *  \brief SW Timer implementation
 *
 *  \author Gustavo Patricio
 *
 *   This module makes use of a System Tick in millisconds and provides
 *   an abstraction for SW timers.
 *   Modified to implement timers on Linux platform.
 *
 */

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
#include "pltf_timer.h"
#include "rfal_platform.h"
#include <stdint.h>
#include <Arduino.h>
/*
******************************************************************************
* LOCAL DEFINES
******************************************************************************
*/

/* Number of timers supported */
#define PLT_TIMER_MAX 10U

/*
******************************************************************************
* GLOBAL AND HELPER FUNCTIONS
******************************************************************************
*/

/* Extern semaphore to signal once a timer expires */
/* Define an array of POSIX timers */

/****************************************************************************/
uint32_t platformGetSysTick_linux()
{
    return millis();
}


/****************************************************************************/
uint32_t plfTimerCreate(uint32_t time)
{
    return platformGetSysTick_linux() + time;
}


/****************************************************************************/
bool plfTimerIsExpired(uint32_t timer)
{
    uint32_t diff = millis() - timer;
    return !(diff > 0);
}


/****************************************************************************/
void plfTimerDestroy(uint32_t timer)
{
}
