# nRF24L01+ with STM32F103
How to connect up a pair of nRF24s and transmit up to 32 bytes of data

## See https://www.youtube.com/ralphbacon video #158
### (Direct link to video: https://youtu.be/jrcRhv9xZo8)

$8 off your first order at LCSC Electronics with https://lcsc.com/?href=ralphsbacon&source=referral

So we are going to see how easy it is to connect a pair of nRF24L01+ (note the plus sign) to a pair of STM32F103s (or the clones) and transmit up to 32 bytes per data packet.

### First things first!
#### The voltage regulator on the STM32 is **not** capable of supplying sufficient power to the nRF24 so you absolutely must use an adapter. <img src="/images/Adapter.png" width="50%" align="right">
They look like this and cost very little indeed. Buy a pack of 5 (you will need at least two anyway) and the cost is very low. I've included links to Amazon and Banggood but you can search the Internet for a store near you, to your liking, of course.

Not only do they solve the whole issue of power, they make the wiring up so much easier as you do it from the top like on an Arduino board.

As I said in my video, use **the same colour** DuPont cables as me so you can be absolutely sure that your wiring is correct. I've included a few close up photos to help you, like this:  
<img src="/images/IMG_20190813_135700.jpg" width="35%">  
All the photos are in the images folder in the GitHub. Some are quite large (I've reduced them on the Readme page) but it allows you to really "zoom in" to get all the details!  

### Beginner Sketches
If you have never done this before please use the "Simple" version of the two sketches first. Why? They are (a little) simpler than the other two and it will take moments to switch sketches when you have these two running successfully.

If you already have done this step on an Arduino, for example, then feel free to load up the sketches that transfer more data in one go, thanks to the **struct** described in the video.

None of this is difficult, although I threw in a **sprintf** just to keep you on your toes. If you hate it just revert to using multiple **Serial.print** style statements! Byt learning about **sprintf** will make you a better C++ coder, as well as taking years off you and making you rich too! OK, I lied about the last two points.

### Fakes? Clones?
Frankly, it's almost impossible to tell easily.  
<img src="/images/nRF24L01+LargePic.png" width="25%">  
Even we zoom in on the nRF24 chip itself it's no guarantee that it's genuine <img src="/images/IMG_20190813_140651.jpg" width="25%" align="right"> so best just try what you have. If you absolutely need genuine parts then you will have to contact the (larger) reseller to get confirmation.  

I've found these little devices to be very good (apart from the one that stopped working today, suddenly, whilst it was just sat on my workbench). As a simple device to send messages from a greenhouse, water tower, out house or similar they must be the simplest way to do it.

Just in case you need a really long range of 1km, I've included a link to one with an aerial from Banggood. Who knows, perhaps it's even genuine Nordic!  
<img src="/images/LongRangeVersion.JPG" width="25%">  
```
Connections (use the same colour Dupont cables as me)    
 NRF24L01     Arduino_ Uno  Blue_Pill(stm32f01C)  
 ___________________________________________________  
  VCC  RED    |    3.3v   |      3.3v  
  GND  BROWN  |    GND    |      GND  
  CSN  YELOW  |   Pin10   | A4 NSS1   (PA4)\  
  CE   ORANGE |   Pin9    | B0 digital(PB0)|	     NB  
  SCK  GREEN  |   Pin13   | A5 SCK1   (PA5)|- All these pins  
  MOSI BLUE   |   Pin11   | A7 MOSI1  (PA7)|  are 3.3v tolerant  
  MISO PURPLE |   Pin12   | A6 MISO1  (PA6)/  
```
  **Always use the adapter plate for 5v!**

RF24-STM library  
https://github.com/jaretburkett/RF24-STM

All about sprintf  
http://www.cplusplus.com/reference/cstdio/sprintf/

Datasheet  
https://www.sparkfun.com/datasheets/Components/SMD/nRF24L01Pluss_Preliminary_Product_Specification_v1_0.pdf

Crazepony-UK 10PCS Arduino NRF24L01+ 2.4GHz Wireless RF Transceiver Module New £10  
https://amzn.to/2KNL6u2

5Pcs NRF24L01+ SI24R1 2.4G Wireless Power Enhanced Communication Receiver Module $5.56  
https://www.banggood.com/5Pcs-NRF24L01-SI24R1-2_4G-Wireless-Power-Enhanced-Communication-Receiver-Module-p-1059601.html?p=FQ040729393382015118&utm_campaign=25129675&utm_content=3897

Enhanced high power version 1,100 meter range  
https://uk.banggood.com/1100-Meter-Long-Distance-NRF24L01PALNA-Wireless-Module-With-Antenna-p-1057170.html?p=FQ040729393382015118&utm_campaign=25129675&utm_content=3897

Adapter boards, 5 pcs  
5Pcs Socket Adapter Module Board For 8 Pin NRF24L01+ Wireless Transceiver  
https://www.banggood.com/5Pcs-Socket-Adapter-Module-Board-For-8-Pin-NRF24L01-Wireless-Transceiver-p-1026348.html?p=FQ040729393382015118&utm_campaign=25129675&utm_content=3897

Adapter Plates from Amazon  
https://amzn.to/31B6EAR

Is it a fake?  
https://forum.mysensors.org/topic/1153/we-are-mostly-using-fake-nrf24l01-s-but-worse-fakes-are-emerging

If you like this video please give it a thumbs up, share it and if you're not already subscribed please consider doing so and joining me on my Arduinite journey

My channel and blog are here:  
\------------------------------------------------------------------  
https://www.youtube.com/RalphBacon  
https://ralphbacon.blog  
\------------------------------------------------------------------
