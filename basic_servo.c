#include "TM4C123GH6PM.h"

#define two_second 1000000 // two-second delay from the microsecond delay function

void Delay_MicroSecond(int time); // generates delay in microseconds
void Servo_0_Degree(void);        // 3% duty cycle of 50Hz pulse
void Servo_90_Degree(void);       // 7% duty cycle of 50Hz pulse
void Servo_180_Degree(void);      // 12% duty cycle of 50Hz pulse

/* main code to control servo motor angular movement */
int main(void)
{
    /* PF1 as a digital output signal to provide a trigger signal */
    SYSCTL->RCGCGPIO |= (1 << 5); // enable clock to PORTF
    GPIOF->DIR |= (1 << 1);        // set PF1 as a digital output pin
    GPIOF->DEN |= (1 << 1);        // make PF1 as a digital pin

    while (1)
    {
        Servo_0_Degree();
        Delay_MicroSecond(two_second);
        Servo_90_Degree();
        Delay_MicroSecond(two_second);
        Servo_180_Degree();
        Delay_MicroSecond(two_second);
    }
}

/* This function generates a 3% duty cycle from a 20ms PWM signal or 50Hz */
void Servo_0_Degree(void)
{
    int i;
    for (i = 0; i < 50; i++)
    {
        /* Given 10us trigger pulse */
        GPIOF->DATA |= (1 << 1); // make control pin high
        Delay_MicroSecond(600);  // 0.6ms seconds delay
        GPIOF->DATA &= ~(1 << 1); // make control pin low
        Delay_MicroSecond(19400); // 1.94ms seconds delay
    }
}

/* This function generates a 7% duty cycle from a 20ms PWM signal or 50Hz */
void Servo_90_Degree(void)
{
    int i;
    for (i = 0; i < 50; i++)
    {
        /* Given 10us trigger pulse */
        GPIOF->DATA |= (1 << 1); // make control pin high
        Delay_MicroSecond(1800); // 1.8ms seconds delay
        GPIOF->DATA &= ~(1 << 1); // make control pin low
        Delay_MicroSecond(18600); // 1.86ms seconds delay
    }
}

/* This function generates a 12% duty cycle from a 20ms PWM signal or 50Hz */
void Servo_180_Degree(void)
{
    int i;
    for (i = 0; i < 50; i++)
    {
        /* Given 10us trigger pulse */
        GPIOF->DATA |= (1 << 1); // make control pin high
        Delay_MicroSecond(2600); // 2.6ms seconds delay
        GPIOF->DATA &= ~(1 << 1); // make control pin low
        Delay_MicroSecond(17600); // 1.76ms seconds delay
    }
}

/* Create a one-microsecond delay using Timer block 1 and sub-timer A */
void Delay_MicroSecond(int time)
{
    int i;
    SYSCTL->RCGCTIMER |= (1 << 1); // enable clock to Timer Block 1
    TIMER1->CTL = 0;               // disable Timer before initialization
    TIMER1->CFG = 0x04;            // 16-bit option
    TIMER1->TAMR = 0x02;           // periodic mode and down-counter
    TIMER1->TAILR = 16 - 1;        // TimerA interval load value reg
    TIMER1->ICR = 0x1;             // clear the TimerA timeout flag
    TIMER1->CTL |= 0x01;           // enable Timer A after initialization

    for (i = 0; i < time; i++)
    {
        while ((TIMER1->RIS & 0x1) == 0)
            ;                  // wait for TimerA timeout flag
        TIMER1->ICR = 0x1;      // clear the TimerA timeout flag
    }
}
