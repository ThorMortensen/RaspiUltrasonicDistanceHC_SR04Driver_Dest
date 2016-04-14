/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DistanceSensor.cpp
 * Author: thor
 * 
 * Created on April 14, 2016, 8:41 PM
 */

#include "DistanceSensor.h"
#include "wiringPi.h"
#include "time.h"
#include "iostream"

DistanceSensor::DistanceSensor(int trigPin, int echoPin, uint64_t offset, uint64_t openLandscapeThresshold, uint32_t burstTime) :
echoPin(echoPin), trigPin(trigPin), offset(offset), openLandscapeThresshold(openLandscapeThresshold), burstTime(burstTime) {
    wiringPiSetup();
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(trigPin, LOW);
}

DistanceSensor::DistanceSensor(const DistanceSensor& orig) :
echoPin(orig.echoPin), trigPin(orig.trigPin), offset(orig.offset), openLandscapeThresshold(orig.openLandscapeThresshold) {
}

DistanceSensor::~DistanceSensor() {

}

double DistanceSensor::getDistanceM() {
    long start_time;
    long time_difference;
    struct timespec gettime_now;
    double distance;
    long open = 0;

    digitalWrite(trigPin, HIGH);
    delay(burstTime);
    digitalWrite(trigPin, LOW);
    if (clock_gettime(CLOCK_REALTIME, &gettime_now) == -1) {
        return -1;
    }
    start_time = gettime_now.tv_nsec; //Get nS value
    delayMicroseconds(500);
    while (digitalRead(echoPin) || open > openLandscapeThresshold) {
        open++;
    }
   // std::cout << "open " <<open << std::endl; //debug
    clock_gettime(CLOCK_REALTIME, &gettime_now);
    time_difference = gettime_now.tv_nsec - start_time;

    distance = 0.5 * 344 * (time_difference - 500000 - offset);
    distance /= 1000000000;
    return distance;
}

double DistanceSensor::getDistanceCm() {
    return getDistanceM() * 100;
}