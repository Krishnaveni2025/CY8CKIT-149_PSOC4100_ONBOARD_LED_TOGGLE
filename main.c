#include <stdint.h>

// Register Definitions for Port 1
volatile uint32_t *HSIOM_PORT_SEL1 = (uint32_t *)0x40020004; // Port 1 selection register
volatile uint32_t *GPIO_PORT1_PC = (uint32_t *)0x40040108;   // Port 1 configuration register
volatile uint32_t *GPIO_PORT1_DR = (uint32_t *)0x40040100;   // Port 1 output data register
#define PIN 2

int main(void)
{
    // Configure P1.2 as GPIO
    // HSIOM: Set P1.2 to GPIO mode (0)
    *HSIOM_PORT_SEL1 &= ~(0x0F << (PIN * 4)); 
    *HSIOM_PORT_SEL1 |= (0x00 << (PIN * 4));

    // PC: Set P1.2 to Strong Drive mode (6)
    *GPIO_PORT1_PC &= ~(0x07 << (PIN * 3));
    *GPIO_PORT1_PC |= (0x06 << (PIN * 3)); 

    while (1)
    {
        *GPIO_PORT1_DR |= (1 << PIN); // Set P1.2 high
        for (volatile int i = 0; i < 100000; i++); // Delay
        
        *GPIO_PORT1_DR &= ~(1 << PIN); // Set P1.2 low
        for (volatile int i = 0; i < 100000; i++); // Delay
    }
}
