// RX RX RX RX RX RX RX RX RX RX RX RX
#include "Arduino.h"
#include <SPI.h>
#include <RF24-STM.h>

struct data {
	signed int temperature; // 2 bytes, -32,768 to 32,767, same as short
	unsigned maxTemp;		// 2 bytes, 0 to 65,535
	double humidity; 		// 4 bytes 32-bit floating point (Due=8 bytes, 64-bit)
	float dewPoint;  		// 4 bytes 32-bit floating point, same as double
	signed long beeCount;	// 4 bytes from -2,147,483,648 to 2,147,483,647
	unsigned long maxBees;	// 4 bytes from to 4,294,967,295
	byte ID;				// 1 byte
	// Total 21, you can have max 32 bytes here
};

// Create an instance of the data container
data myDataRx;

/*
 * NRF24L01     Arduino_ Uno  Blue_Pill(stm32f01C)
 * ___________________________________________________
 * VCC  RED    |    3.3v   |      3.3v
 * GND  BROWN  |    GND    |      GND
 * CSN  YELOW  |   Pin10   | A4 NSS1   (PA4)	\
 * CE   ORANGE |   Pin9    | B0 digital(PB0)    |	    NB
 * SCK  GREEN  |   Pin13   | A5 SCK1   (PA5)	|- All these pins
 * MOSI BLUE   |   Pin11   | A7 MOSI1  (PA7)	|  are 3.3v tolerant
 * MISO PURPLE |   Pin12   | A6 MISO1  (PA6) 	/
 *
 *    Always use the adapter plate for 5v!
 */
RF24 radio(PB0, PA4); // CE, CSN

// -----------------------------------------------------------------------------
// SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP   SETUP
// -----------------------------------------------------------------------------
void setup() {
	// RX RX RX RX RX RX RX RX RX RX RX RX
	Serial.begin(115200);
	Serial.println("THIS IS THE RECEIVER CODE - YOU NEED THE OTHER ARDUINO TO TRANSMIT");

	// Initiate the radio object
	radio.begin();

	// Set the transmit power to lowest available to prevent power supply related issues
	radio.setPALevel(RF24_PA_LOW);

	// Set the speed of the transmission to the quickest available
	radio.setDataRate(RF24_2MBPS);

	// Use a channel unlikely to be used by Wifi, Microwave ovens etc 124
	radio.setChannel(104);

	radio.setRetries(255, 5);

	// Open a writing and reading pipe on each radio, with opposite addresses
	radio.openReadingPipe(1, 0xB3B4B5B602);
	radio.openWritingPipe(0xB3B4B5B601);

	// Start the radio listening for data
	radio.startListening();

	// Auto ackknowledgment of a transmission
	radio.setAutoAck(true);

	// Debugging information
	radio.printDetails();
}

// -----------------------------------------------------------------------------
// We are LISTENING on this device only (although we do transmit a response)
// -----------------------------------------------------------------------------
void loop() {
	// RX RX RX RX RX RX RX RX RX RX RX RX

	// Is there any data for us to get?
	if (radio.available()) {
		// Go and read the data and put it into that variable
		//while (radio.available()) {
		radio.read(&myDataRx, sizeof(data));

		delay(100);
		Serial.println("RX: Received");

		// First, stop listening so we can talk
		radio.stopListening();

		// Show user what we sent and what we got back
		Serial.print("ID         : ");
		Serial.println(myDataRx.ID);
		Serial.print("Temperature: ");
		Serial.println(myDataRx.temperature);
		Serial.print("Max Temp.  : ");
		Serial.println(myDataRx.maxTemp);
		Serial.print("Humidity   : ");
		Serial.println(myDataRx.humidity);
		Serial.print("Dew Point  : ");
		Serial.println(myDataRx.dewPoint);
		Serial.print("Bee Count  : ");
		Serial.println(myDataRx.beeCount);
		Serial.print("Max Bees   : ");
		Serial.println(myDataRx.maxBees);

		// Change something
		myDataRx.temperature++;
		myDataRx.maxBees++;
		myDataRx.humidity += 0.1;

		// Tell the user what we sent back (the random numer + 1)
		Serial.println("RX: Replied");

		if (!radio.write(&myDataRx, sizeof(data))) {
			Serial.println("RX: No ACK");
		} else {
			Serial.println("RX: ACK");
		}

		// Now, resume listening so we catch the next packets.
		radio.startListening();
	}
}
