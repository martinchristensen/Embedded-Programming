#include <stdint.h>
#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int dummy;
    int counter = 0;

    SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF;

    dummy = SYSCTL_RCGC2_R;

    GPIO_PORTF_DIR_R = 0x0E;

    GPIO_PORTF_DEN_R = 0x1E;

    GPIO_PORTF_PUR_R = 0x10;

    while(1)
    {
        while((GPIO_PORTF_DATA_R & 0x10)){}
        GPIO_PORTF_DATA_R &= 0x00;
            if(counter == 0){
                GPIO_PORTF_DATA_R |= 0x02;
            }
            else if(counter == 1){
                GPIO_PORTF_DATA_R |= 0x04;
            }
            else if(counter == 2){
                GPIO_PORTF_DATA_R |= 0x06;
            }
            else if(counter == 3){
                GPIO_PORTF_DATA_R |= 0x08;
            }
            else if(counter == 4){
                GPIO_PORTF_DATA_R |= 0x0A;
            }
            else if(counter == 5){
                GPIO_PORTF_DATA_R |= 0x0E;
            }
            else if(counter == 6){
                GPIO_PORTF_DATA_R |= 0x0C;
            }
            else if(counter == 7){
                GPIO_PORTF_DATA_R |= 0x00;
            }
            while(!(GPIO_PORTF_DATA_R & 0x10)){}
            counter++;
            if(counter >= 8)
            {
                counter = 0;
            }
  //      }


    }
    return 0;
}
