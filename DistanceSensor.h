/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DistanceSensor.h
 * Author: thor
 *
 * Created on April 14, 2016, 8:41 PM
 */

#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H


#include <stdint.h>

class DistanceSensor {
public:
    DistanceSensor(int trigPin, int echoPin, uint64_t offset = 0, uint64_t openLandscapeThresshold = -1, uint32_t burstTime = 15);
    DistanceSensor(const DistanceSensor& orig);
    double getDistanceM();
    double getDistanceCm();
    virtual ~DistanceSensor();
private:
    int echoPin;
    int trigPin;
    uint64_t offset;
    uint64_t openLandscapeThresshold;
    uint32_t burstTime;
};

#endif /* DISTANCESENSOR_H */

