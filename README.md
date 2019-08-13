# nRF24L01+ with STM32F103
How to connect up a pair of nRF24s and transmit up to 32 bytes of data

## See https://www.youtube.com/ralphbacon video #158
### (Direct link to video: https://youtu.be/jrcRhv9xZo8)

[Sponsor message goes here]

So we are going to see how easy it is to connect a pair of nRF24L01+ (note the plus sign) to a pair of STM32F103s (or the clones) and transmit up to 32 bytes per data packet.

### First things first!
#### The voltage regulator on the STM32 is **not** capable of supplying sufficient power to the nRF24 so you absolutely must use an adapter. <img src="/images/Adapter.png" width="50%" align="right">
They look like this and cost very little indeed. Buy a pack of 5 (you will need at least two anyway) and the cost is very low. I've included links to Amazon and Banggood but you can search the Internet for a store near you, to your liking, of course.

Not only do they solve the whole issue of power, they make the wiring up so much easier as you do it from the top like on an Arduino board.

As I said in my video, use **the same colour** DuPont cables as me so you can be absolutely sure that your wiring is correct. I've included a few close up photos to help you, like this:  
<img src="/images/IMG_20190813_135700.jpg" width="25%">  
All the photos are in the images folder in the GitHub. Some are quite large (I've reduced them on the Readme page) but it allows you to really "zoom in" to get all the details!  
