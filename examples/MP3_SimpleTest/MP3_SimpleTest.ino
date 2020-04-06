/*
 * MP3_Play_Test.ino
 * A quick start example for Grove-Serial MP3 Player V2.0			-And Modified for HackDays
 * Note: The MP3 chip of Grove-Serial MP3 Player V2.0 is different from Grove-Serial MP3 Player V1.0
 * Description: This demo let you can send instruction 1-8 to control the Grove-Serial MP3 Player, via the serial port.
 *
 * Copyright (c) 2015 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Wuruibin
 * Created Time: Dec 2015
 * Modified Time:
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include <SoftwareSerial.h>
#include <MP3Player_KT403A.h>

// Note: You must define a SoftwareSerial class object that the name must be mp3, 
//       but you can change the pin number according to the actual situation.
SoftwareSerial mp3(2, 3);

void setup()
{
    mp3.begin(9600);
    Serial.begin(9600); 
    delay(100);
    
    SelectPlayerDevice(0x02);       // Select SD card as the player device.
    SetVolume(0x0E);                // Set the volume, the range is 0x00 to 0x1E.
}

void loop()
{
	SpecifyMusicPlay(1);			//Plays Song 1 (actually starts with 1, not 0)
	
//	PlayPause();
//	PlayResume();
//	PlayNext();
//	PlayPrevious();
//	PlayLoop();
//	IncreaseVolume();
//	DecreaseVolume();

	delay(100000);
}
