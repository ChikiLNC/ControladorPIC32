#include "Config.h"

void SPI_Config()
{
    //SPI 1 para el ENC28J60
    SPI1CONbits.ON = 0;
    SPI1CONbits.MCLKSEL = 0; //Periferico con clock de 5MHz
    SPI1CONbits.DISSDO = 0;//SDO1 y SDI1 controlados por modulo
    SPI1CONbits.DISSDI = 0;
    SPI1CONbits.ENHBUF = 0; 
    SPI1CONbits.MSTEN = 1; //Master Mode
    SPI1CONbits.CKE = 0;
    SPI1CONbits.CKP = 0; //CLK Idle en LOW
    
    SPI1BRG = 0; //Clock de 10MHz
    
    //SPI 2 para la SDcard
    SPI1CONbits.ON = 0;
    SPI2CONbits.MCLKSEL = 0; //Periferico con clock de 5MHz
    SPI2CONbits.DISSDO = 0;
    SPI2CONbits.DISSDI = 0;
    SPI2CONbits.ENHBUF = 0;
    SPI2CONbits.MSTEN = 1;//Master Mode
    SPI2CONbits.CKP = 1; //CLK Idle en HIGH
    
    SPI2BRG = 0; //Clock de 10MHz
    
    //Seteo Prioridades
    IPC7bits.SPI1IP = 1;
    IPC9bits.SPI2IP = 1;
    
    //Habilito Interrupciones    
    IEC1bits.SPI1EIE = 1;
    IEC1bits.SPI1RXIE = 1;
    IEC1bits.SPI1TXIE = 1;
    
    IEC1bits.SPI2EIE = 1;
    IEC1bits.SPI2RXIE = 1;
    IEC1bits.SPI2TXIE = 1;
}

void Config()
{
    SPI_Config();
}