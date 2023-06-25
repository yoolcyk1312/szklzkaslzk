#pragma once
#include <string>
#include <iostream>

using namespace std;

class Plant
{
private:
    string name;
    int temperature_min;
    int temperature_max;
    int moisture_min;
    int moisture_max;
    int light_min;
    int light_max;
    int frutification_per_year;
    int frutification_age;
    bool has_fruits;
    int growth_rate;
public:
    Plant(string name, int temperature_min, int temperature_max, int moisture_min, int moisture_max,
        int light_min, int light_max, int frutification_per_year, int frutification_age)
        : name(name)
        , temperature_min(temperature_min)
        , temperature_max(temperature_max)
        , moisture_min(moisture_min)
        , moisture_max(moisture_max)
        , light_min(light_min)
        , light_max(light_max)
        , frutification_per_year(frutification_per_year)
        , frutification_age(frutification_age)
        , has_fruits(false)
        , growth_rate(0)
    {}
    string get_name() const { return name; }
    int get_growth_rate() const { return growth_rate; }
    int get_temperature_min() const { return temperature_min; }
    int get_temperature_max() const { return temperature_max; }
    int get_moisture_min() const { return moisture_min; }
    int get_moisture_max() const { return moisture_max; }
    int get_light_min() const { return light_min; }
    int get_light_max() const { return light_max; }
    int get_fructification_per_year() const { return frutification_per_year; }
    int get_fructification_age() const { return frutification_age; }
    bool is_fruiting() const { return has_fruits; }
    void give_fruits(int growth_rate)
    {
        if (has_fruits) { return; }
        if (growth_rate >= frutification_per_year && frutification_age > 0) { frutification_age--; }
        if (frutification_age == 0) { has_fruits = true; }
    }
    void set_has_fruits(bool has_fruits) { this->has_fruits = has_fruits; }
};