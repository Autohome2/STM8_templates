/**
  \file gpio.h
   
  \author G. Icking-Konert
  \date 2013-11-22
  \version 0.1
   
  \brief declaration of functions/macros for GPIO control
   
  declaration of functions/macros for port pin control
  For speed use macros instead of functions where reasonable
  Optional functionality via #define:
    - USE_PORT_ISR: allow attaching user function to port interrupts (EXTIn)
    - USE_TLI_ISR:  allow attaching user function to interrupt on pin PD7 (TLI) 
*/

/*-----------------------------------------------------------------------------
    MODULE DEFINITION FOR MULTIPLE INCLUSION
-----------------------------------------------------------------------------*/
#ifndef _GPIO_H_
#define _GPIO_H_

/*-----------------------------------------------------------------------------
    INCLUDE FILES
-----------------------------------------------------------------------------*/
#include "stm8as.h"
#include "config.h"
#include "misc.h"


/*-----------------------------------------------------------------------------
    DECLARATION OF GLOBAL MACROS
-----------------------------------------------------------------------------*/

//////////
// port/pin control macros. For PORT_x see file "stm8as.h"
//////////

// rename bits to pins for readability
#define pin0  b0
#define pin1  b1
#define pin2  b2
#define pin3  b3
#define pin4  b4
#define pin5  b5
#define pin6  b6
#define pin7  b7

// pin configurations for below pinMode(). For details see 'stm8as.h'
#define  INPUT                    0x00     ///< configure pin as: input, float, no port interrupt
#define  INPUT_INTERRUPT          0x01     ///< configure pin as: input, float, with port interrupt
#define  INPUT_PULLUP             0x02     ///< configure pin as: input, pull-up, no port interrupt
#define  INPUT_PULLUP_INTERRUPT   0x03     ///< configure pin as: input, pull-up, with port interrupt
//#define  OUTPUT_OPENDRAIN_SLOW    0x04     ///< configure pin as: output, open-drain, slow (2MHz)
#define  OUTPUT_OPENDRAIN         0x05     ///< configure pin as: output, open-drain, fast (10MHz)
//#define  OUTPUT_SLOW              0x06     ///< configure pin as: output, push-pull, slow (2MHz)
#define  OUTPUT                   0x07     ///< configure pin as: output, push-pull, fast (10MHz)

// edge sensitivities for port/EXINT and pin/TLI interrupts
//#define  LOW                      0        ///< interrupt on low level (EXINT). Warning: may stall device!
#define  CHANGE                   1        ///< interrupt on both edges (EXINT)
#define  RISING                   2        ///< interrupt on rising edge (EXINT & TLI)
#define  FALLING                  3        ///< interrupt on falling edge (EXINT & TLI)
#define  PREV_SETTING             4        ///< keep current sensitivity (EXINT & TLI)

/// set pin mode
#define pinMode(port,pin,mode)  { \
   port.DDR.bit.pin = ((mode & 0x04) >> 2); \
   port.CR1.bit.pin = ((mode & 0x02) >> 1); \
   port.CR2.bit.pin = ((mode & 0x01) >> 0); \
}

// access port pins directly (for speed)
#define pinSet(port,pin)    (port.ODR.bit.pin)    ///< pin output state (1 pin)
#define pinRead(port,pin)   (port.IDR.bit.pin)    ///< pin input state (1 pin)
#define portSet(port)       (port.ODR.byte)       ///< port output state (8 pins)
#define portRead(port)      (port.IDR.byte)       ///< port input state (8 pins)


/*-----------------------------------------------------------------------------
    DECLARATION OF GLOBAL FUNCTIONS
-----------------------------------------------------------------------------*/

#if defined(USE_PORTA_ISR) || defined(USE_PORTB_ISR) || defined(USE_PORTC_ISR) || defined(USE_PORTD_ISR) || \
    defined(USE_PORTE_ISR) || defined(USE_PORTF_ISR) || defined(USE_PORT_ISR)

  /// configure edge sensitivity for EXINT
  void configExintEdge(PORT_t *addrPort, uint8_t edge);

#endif

/*-----------------------------------------------------------------------------
    END OF MODULE DEFINITION FOR MULTIPLE INLUSION
-----------------------------------------------------------------------------*/
#endif // _GPIO_H_
