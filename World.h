#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;

class World
{
private:
    double world_temperature;
    double world_humidity;
    double sunny_time;
    string season;
    int days_passed;
public:
    World()
    {
        world_temperature = 0;
        world_humidity = 0;
        sunny_time = 0;
        days_passed = 0;
        season = "";
    }
    string update_season()
    {
        if (days_passed>= 0 && days_passed < 91)
        {
            season = "zima";
            world_temperature = generate_random_value(-10.0, 15.0);
            world_humidity = generate_random_value(40.0, 55.0);
            sunny_time = generate_random_value(0, 6);
        }
        else if (days_passed >= 91 && days_passed < 182)
        {
            season = "wiosna";
            world_temperature = generate_random_value(0.0, 25.0);
            world_humidity = generate_random_value(60.0, 75.0);
            sunny_time = generate_random_value(0, 10);
        }
        else if (days_passed >= 182 && days_passed < 274)
        {
            season = "lato";
            world_temperature = generate_random_value(10.0, 35.0);
            world_humidity = generate_random_value(70.0, 85.0);
            sunny_time = generate_random_value(0, 14);
        }
        else if (days_passed >= 274 && days_passed < 365)
        {
            season = "jesien";
            world_temperature = generate_random_value(0.0, 25.0);
            world_humidity = generate_random_value(55.0, 70.0);
            sunny_time = generate_random_value(0, 10);
        }
        else days_passed = 0;
        days_passed++;
        return season;
    }
    double generate_random_value(double value_min, double value_max)
    {
        double range = value_max - value_min;
        double random_value = (rand() / static_cast<double>(RAND_MAX)) * range + value_min;
        return random_value;
    }
    double get_world_temperature() { return world_temperature; }
    double get_world_humidity() { return world_humidity; }
    double get_sunny_time() { return sunny_time; }
    double update_temperature(double new_temperature) { return world_temperature = new_temperature; }
    double update_humidity(double new_humidity) { return world_humidity = new_humidity; }
    double update_light(double new_light) { return sunny_time = new_light; }
};