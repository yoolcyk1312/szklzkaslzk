#pragma once
#include "Greenhouse.h"
#include "Pid.h"
#include "World.h"
#include <iostream>

using namespace std;

class Device
{
public:
    void set_power(double power_of_device);
    virtual void control() = 0;
private:
    double power_nominal=2000;
    double power_of_device = 0;
};

class Heater : public Device
{
private:
    Greenhouse& greenhouse;
    PID& pid;
    vector<double> power_of_heater;
public:
    Heater();
    Heater(Greenhouse& greenhouse, PID& pid)
        : greenhouse(greenhouse)
        , pid(pid)
    {}
    void control() override
    {
        double target_value = greenhouse.get_desired_temperature();
        double power = pid.control_value(target_value, 1);
    }
};

class Humidifier : public Device
{
private:
    Greenhouse& greenhouse;
    PID& pid;
    bool is_humidifying=false;
    bool is_dehumidifying=false;
    vector<double> power_of_humidifier;
public:
    Humidifier();
    Humidifier(Greenhouse& greenhouse, PID& pid)
        : greenhouse(greenhouse)
        , pid(pid)
    {}
    void control() override
    {
        double target_value = greenhouse.get_desired_humidity();
        double outside_value = greenhouse.get_inside_humidity();
        if (target_value > outside_value) is_dehumidifying = true;
        else if(target_value<outside_value) is_humidifying = true;
        double power = pid.control_value(target_value, 2);
    }
};
class Lamp : public Device
{
private:
    Greenhouse& greenhouse;
    World& world;
    vector<double> work_time;//on/of
public:
    Lamp();
    void control() override
    {
        double work_time = greenhouse.get_desired_light() - world.get_sunny_time();
    }

};