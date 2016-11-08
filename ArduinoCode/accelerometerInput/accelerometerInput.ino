/*****************************************************************************/
//	Function:    Get the accelemeter of the x/y/z axis. 
//  Hardware:    Grove - 3-Axis Digital Accelerometer(±1.5g)
//	Arduino IDE: Arduino-1.0
//	Author:	 Frankie.Chu		
//	Date: 	 Jan 10,2013
//	Version: v0.9b
//	by www.seeedstudio.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
/*******************************************************************************/

#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;

long int currentMillis = 0;
float pax = 0,pay = 0,paz = 0;
float prevForce = 0;
float ax,ay,az;
void setup()
{
	accelemeter.init();  
	Serial.begin(9600);
  delay(1000);
  accelemeter.getAcceleration(&ax,&ay,&az);
  prevForce = abs(ax) + abs(ay) + abs(az);
}
void loop()
{
	

	
	accelemeter.getAcceleration(&ax,&ay,&az);
  float force = abs(ax) + abs(ay) + abs(az);
  float difference = abs(force - prevForce);
  if(difference > 1.5){
    //Light LEDs
    Serial.print("Hit! Force =  ");
    Serial.print(force);
    Serial.print(" prevForce = ");
    Serial.print(prevForce);
    Serial.print(" Difference: ");
    Serial.println(difference);
  }

  prevForce = force;
	delay(10);
}


