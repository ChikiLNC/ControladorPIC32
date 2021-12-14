// PIC32MX250F128B Configuration Bit Settings
// 'C' source line config statements

// Config Bits
#pragma config FNOSC = FRCPLL
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (4x Divider) 4MHz
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier) (80MHz)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider Clock Final 40MHz

#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Disabled)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Enabled)
#pragma config JTAGEN = OFF             // JTAG Disable
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config FPBDIV = DIV_2           // Perifericos clock = Sys/8 = 20MHz

#include <xc.h>
#include "sys/attribs.h"

/*
 * 
 * TRISx para decir si es Input 1 o Output 0
 * PORTx es para lectura del puerto
 * LATx es para escritura del puerto
 */

void main(void) 
{
    __builtin_enable_interrupts(); //Habilita interrupciones globales
    INTCONSET = _INTCON_MVEC_MASK; // Interrupt controller for multi-vector mode    
    
    TRISB = 0;
    LATBbits.LATB7 = 1;
    
    while(1)
    {
        //PORTBbits.RB7 = ~PORTBbits.RB7;
    }
}

void __ISR(_SPI_1_VECTOR, IPL1AUTO) SPI_1_Handler(void)
{
    
}

void __ISR(_SPI_2_VECTOR, IPL1AUTO) SPI_2_Handler(void)
{
    
}