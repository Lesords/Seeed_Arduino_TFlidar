#include "TFLidar.h"
//NOTE this demo cannot work with   TFmini for now
#define SERIAL Serial

#define USETFMINI
// #define USETFLUNA

#if defined(SEEED_XIAO_M0)
    #define uart  Serial1
#elif defined(SEEED_WIO_TERMINAL)
    SoftwareSerial uart(0, 1);
#else
    SoftwareSerial uart(2, 3);
#endif

#ifdef USETFLUNA
TFLuna SeeedTFLuna;
TFLidar SeeedTFLidar(&SeeedTFLuna);
#endif

#ifdef USETFMINI
TFMini SeeedTFMini;
TFLidar SeeedTFLidar(&SeeedTFMini);
#endif 


void setup() {
    // put your setup code here, to run once:
    SERIAL.begin(9600);
    while(!Serial);
    int buff[3] = {0};
    SeeedTFLidar.begin(&uart,115200);
    if(SeeedTFLidar.set_baud_rate(9600))
    {
        SERIAL.print("config successful");        
    }
}
void loop() {

}