/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: thor
 *
 * Created on April 14, 2016, 3:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <wiringPi.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>

#include "DistanceSensor.h"

#define TRIG_PIN 16
#define ECHO_PIN 15

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    //(int trigPin, int echoPin, uint64_t offset, uint64_t openLandscapeThresshold, uint32_t burstTime ) 
    DistanceSensor frontSonar(TRIG_PIN, ECHO_PIN, 0);

    while (1) {
        cout << "Meters: " << frontSonar.getDistanceM() << endl;
    }



    return 0;
}

