#pragma once
#include "Device.h"
#include "Greenhouse.h"
#include "World.h"
#include "Plant.h"
#include "Pid.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

class Simulation
{
protected:
    vector<int> day_index;
    vector<string> season;
    vector<double> temperature_data;
    vector<double> humidity_data;
    vector<double> light_data;
    vector<double> heater_data;
    vector<double> humidifier_data;
    vector<double> lamp_data;
    vector<string> growing_data;
    vector<string> fruiting_data;
private:
    int duration;
    World world;
    Heater& heater;
    Humidifier& humidifier;
    Lamp& lamp;
public:
    Greenhouse& greenhouse;
    Simulation(int duration, Greenhouse& greenhouse)
        : duration(duration)
        , world(world)
        , greenhouse(greenhouse)
        , heater(heater)
        , humidifier(humidifier)
        , lamp(lamp)
    {}
    void add_plant(const Plant& plant) { greenhouse.add_plant(plant); }
    void run()
    {
        cout << "start symulacji o czasie trwania " << duration << " dni" << endl;
        srand(time(0));
        for (int day = 0; day < duration; day++)
        {
            cout << "dzien " << day+1 << ":" << endl;
            day_index.push_back(day+1);
            season.push_back(world.update_season());
            double temperature = world.get_world_temperature();
            double updated_temperature = world.update_temperature(temperature);
            temperature_data.push_back(updated_temperature);
            double humidity = world.get_world_humidity();
            double updated_humidity = world.update_humidity(humidity);
            humidifier_data.push_back(updated_humidity);
            double light = world.get_sunny_time();
            double updated_light = world.update_light(light);
            light_data.push_back(updated_light);
            grow_plants(updated_temperature, updated_humidity, updated_light);
        }
        cout << "symulacja zakonczona" << endl;
    }
private:
    void grow_plants(double temperature, double humidity, double light)
    {
        for (auto& plant : greenhouse.get_plants())
        {
            bool conditions_met = temperature_check(temperature, plant.get_temperature_min(), plant.get_temperature_max()) &&
                humidity_check(humidity, plant.get_moisture_min(), plant.get_moisture_max()) &&
                light_check(light, plant.get_light_min(), plant.get_light_max());
            if (conditions_met)
            {
                growing_data.push_back(plant.get_name());
                int growth_rate = plant.get_growth_rate();
                plant.give_fruits(growth_rate);
                bool conditions_maintained = check_conditions_maintained(15, temperature, plant.get_temperature_min(), plant.get_temperature_max(),
                    humidity, plant.get_moisture_min(), plant.get_moisture_max(),
                    light, plant.get_light_min(), plant.get_light_max());
                if (conditions_maintained) { fruiting_data.push_back(plant.get_name()); plant.set_has_fruits(true); }
            }
            else { plant.set_has_fruits(false); }
        }                 
    }

    bool temperature_check(double actual_temperature, int temperature_min, int temperature_max)
    {return actual_temperature >= temperature_min && actual_temperature <= temperature_max;}
    bool humidity_check(double actual_humidity, int humidity_min, int humidity_max)
    {return actual_humidity >= humidity_min && actual_humidity <= humidity_max;}
    bool light_check(double actual_light, int light_min, int light_max)
    {return actual_light >= light_min && actual_light <= light_max;}
    bool check_conditions_maintained(int days, double temperature, int temperature_min, int temperature_max,
        double humidity, int humidity_min, int humidity_max,
        double light, int light_min, int light_max)
    {
        for (int i = 0; i < days; ++i)
        {
            double current_temperature = world.get_world_temperature();
            double current_humidity = world.get_world_humidity();
            double current_light = world.get_sunny_time();
            if (!temperature_check(current_temperature, temperature_min, temperature_max) ||
                !humidity_check(current_humidity, humidity_min, humidity_max) ||
                !light_check(current_light, light_min, light_max)) {
                return false;
            }
        }
        return true;
    }
    public:

    void save_parameters_to_file() const
    {
        ofstream file("plik.csv");
        locale pol("pl_PL");
        file.imbue(pol);
        if (!file)
        {
            cerr << "nipowodzenie" << endl;
            return;
        }
        file << "dzien\; pora roku\; temperatura\; wilgotnosc\; moc grzejnika\; moc nawil¿acza\; moc lampy" << endl;
        for (size_t i = 0; i < day_index.size(); ++i)
        {
            file << day_index[i] << "\;" << season[i] << "\;" << temperature_data[i] << "\;" << humidifier_data[i] << endl;
        }
        file.close();
        system("uklonik");

    }
};