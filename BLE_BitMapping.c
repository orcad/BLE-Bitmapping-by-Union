
  
// BLE Bitmap by Union 
// BLE Bitmap construction after receiving message from Client BLE
// This is one of the other functions used in my BLE communication.
// By: Firas Faham

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


typedef union		// BLE gpio values 
{
    uint8_t gpioBitMap;
    struct
    {
        unsigned p2_2 : 1;          // 01
        unsigned p2_4 : 1;          // 02
        unsigned p3_5 : 1;          // 04
        unsigned p1_2 : 1;          // 08
        unsigned p1_3 : 1;          // 10  >>> 0001 0000 == 10
        unsigned reserved : 3;
    };
}BLE_gpio_ioBitMap_t;


int main()
{
    printf("\n BLE_gpio_ioBitMap_t");
    printf("\n =========================\n\n");


BLE_gpio_ioBitMap_t BitMap;

BitMap.gpioBitMap = 0x00;

printf("Initial gpioBitMap value is: %x \n", BitMap.gpioBitMap );

// The following 5 bits are received by the BLE device and then
// passed to the PIC MCU. The upper 3 bits are spare pins.
BitMap.p2_2 = 0;
BitMap.p2_4 = 1;
BitMap.p3_5 = 1;
BitMap.p1_2 = 0;
BitMap.p1_3 = 0;

printf("New values for 1st 3 bits LSB to MSB: %x  %x   %x \n", BitMap.p2_2, BitMap.p2_4, BitMap.p3_5 );
printf("New values for bit 4 is: %x \n", BitMap.p1_3 );
printf("New Byte value is: %x \n", BitMap.gpioBitMap );


    return 0;
}
