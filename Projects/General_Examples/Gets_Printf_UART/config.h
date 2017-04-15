/**
  \file config.h
   
  \author G. Icking-Konert
  \date 2013-11-22
  \version 0.1
   
  \brief project specific settings
   
  project specific configuration header file
  Select STM8 device and activate optional options
*/

/*-----------------------------------------------------------------------------
    MODULE DEFINITION FOR MULTIPLE INCLUSION
-----------------------------------------------------------------------------*/
#ifndef _CONFIG_H_
#define _CONFIG_H_


/// select STM8 device (no default). For supported devices see file "stm8as.h"
#define STM8S208      // muBoard

// use ftoa() function for printing floats. Requires ~3.3kB flash
#define USE_FTOA 


/*-----------------------------------------------------------------------------
    END OF MODULE DEFINITION FOR MULTIPLE INLUSION
-----------------------------------------------------------------------------*/
#endif  // _CONFIG_H_