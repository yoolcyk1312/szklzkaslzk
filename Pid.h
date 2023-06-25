#pragma once
#include <iostream>
#include "Greenhouse.h"

using namespace std;

class PID
{
private:
    Greenhouse& greenhouse;
    double sampling_time;
    double measured_last;
public:
    PID(Greenhouse& greenhouse, double sampling_time)
        : greenhouse(greenhouse)
        , sampling_time(sampling_time)
        , measured_last(0.0)
    {}

    void set_sampling_time(double delta) { sampling_time = delta; }
    void set_measured_last(double last) { measured_last = last; }
    double control_value(double value_requested)
    {
        double value_measured = greenhouse.get_value_inside(temp_or_hum);
        double delta = sampling_time;
        double error = value_requested - value_measured;
        double proportional = 4 * error;
        double integral = 0.2 * error * delta;
        double derivative = 0.02 * (value_measured - measured_last) / delta;
        double power = proportional + integral + derivative;
        if (power > 1) power = 1;
        else if (power <= 0) power = 0;
        measured_last = value_measured;
        return power;
    }
};