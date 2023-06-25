#pragma once
#include "Plant.h"
#include "World.h"

#include <iostream>
#include <vector>

using namespace std;

class Greenhouse
{
private:
    World& world;
    double desired_temperature;
    double desired_humidity;
    double desired_light;
    double height;
    double width;
    double depth;
    double wall_surface;
    double air_mass;
    double temperature_inside;
    double humidity_inside;
    double heat_entering;
    double humidity_entering;
    const double heat_specific;
    const double absolute_humidity;
    const double air_density;
    const double wall_thickness;
    const double wall_conductance;
    const double wall_tightness;
    double temperature_outside;
    double humidity_outside;
    double temperature_change(double q, double dt) const { return q / (air_mass * heat_specific) * dt; }
    double heat_change() const
    { return wall_conductance * wall_surface * (temperature_inside - temperature_outside) / wall_thickness; }
    double humidity_change(double w, double dt) const { return w / (air_mass * absolute_humidity) * dt; }
    double wet_change()const
    { return wall_tightness * wall_surface * (humidity_inside - humidity_outside) / wall_thickness; }
    vector<Plant> plants;
public:
    Greenhouse(double height, double width, double depth, double desired_temperature, double desired_humidity, double desired_light)
        : world (world)
        , height(height)
        , width(width)
        , depth(depth)
        , desired_temperature (desired_temperature)
        , desired_humidity(desired_humidity)
        , desired_light(desired_light)
        , heat_entering(0)
        , humidity_entering(0)
        , heat_specific(721)
        , air_density(1.225)
        , wall_thickness(0.4)
        , wall_conductance(0.3)
        , wall_tightness(0.9)
        , temperature_outside(20.0)
        , temperature_inside(20.0)
        , absolute_humidity(20)
        , humidity_inside(20)
        , humidity_outside(20)
    {
        wall_surface = 2 * (width + depth) * height;
        air_mass = width * depth * height * air_density;
    }
    vector<Plant> get_plants() { return plants; };
    double get_inside_temperature() { return temperature_inside; }
    double get_outside_temperature() { return temperature_outside; }
    double get_inside_humidity() { return humidity_inside; }
    double get_outside_humidity() { return humidity_outside; }
    double get_desired_temperature() { return desired_temperature; }
    double get_desired_humidity() { return desired_humidity; }

    void heat_add(double q) { heat_entering += q; }
    void humidity_add(double w) { humidity_entering += w; }
    void update(double dt)
    {
        heat_entering += heat_change();
        temperature_inside += temperature_change(heat_entering, dt);
        heat_entering = 0;
        humidity_entering += wet_change();
        humidity_inside += humidity_change(humidity_entering, dt);
        humidity_entering = 0;
    }
    void set_desired_temperature(double temperature) { desired_temperature = temperature; }
    void set_desired_humidity(double humidity) { desired_humidity = humidity; }
    void set_desired_light(double light) { desired_light = light; }
    double get_desired_light() { return desired_light; }
    double get_world_temperature() { return temperature_inside; }
    double get_world_humidity() { return humidity_inside; }

    void add_plant(const Plant& plant) { plants.push_back(plant); }
};