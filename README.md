# nRF24L01+ with STM32F103
How to connect up a pair of nRF24s and transmit up to 32 bytes of data

## See https://www.youtube.com/ralphbacon video #158
### (Direct link to video: https://youtu.be/jrcRhv9xZo8)

[Sponsor message goes here]

So we are going to see how easy it is to connect a pair of nRF24L01+ (note the plus sign) to a pair of STM32F103s (or the clones) and transmit up to 32 bytes per data packet.

First things first: the voltage regulator on the STM32 is **not** capable of supplying sufficient power to the nRF24 so you 
### absolutely must use an adapter.
They look like this:
<img src="/images/Adapter.png" width="50%">
