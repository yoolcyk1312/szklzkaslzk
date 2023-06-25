#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Device.h"
#include "Greenhouse.h"
#include "Pid.h"
#include "Plant.h"
#include "Simulation.h"
#include "World.h"

using namespace std;

void plant_catalog(Greenhouse& greenhouse, int choice)
{
    switch (choice)
    {
        case 1:
        {Plant aloes("aloes", 15, 30, 40, 60, 6, 8, 1, 2); greenhouse.add_plant(aloes); break; }
        case 2:
        {Plant ananas("ananas", 20, 32, 60, 80, 10, 12, 1, 2); greenhouse.add_plant(ananas); break; }
        case 3:
        {Plant arbuz("arbuz", 20, 30, 60, 80, 8, 10, 1, 2); greenhouse.add_plant(arbuz); break; }
        case 4:
        {Plant bazylia("bazylia", 15, 28, 40, 60, 10, 12, 3, 0); greenhouse.add_plant(bazylia); break; }
        case 5:
        {Plant begonia("begonia", 18, 24, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(begonia); break; }
        case 6:
        {Plant brokul("brokul", 15, 25, 60, 80, 8, 10, 1, 1); greenhouse.add_plant(brokul); break; }
        case 7:
        {Plant cebula("cebula", 10, 25, 50, 70, 10, 12, 1, 1); greenhouse.add_plant(cebula); break; }
        case 8:
        {Plant czosnek("czosnek", 10, 25, 50, 70, 10, 12, 1, 1); greenhouse.add_plant(czosnek); break; }
        case 9:
        {Plant fikus("fikus", 15, 24, 40, 60, 8, 10, 1, 2); greenhouse.add_plant(fikus); break; }
        case 10:
        {Plant fittonia("fittonia", 18, 24, 60, 80, 8, 10, 1, 1); greenhouse.add_plant(fittonia); break; }
        case 11:
        {Plant hortensja("hortensja", 10, 24, 40, 60, 6, 8, 1, 2); greenhouse.add_plant(hortensja); break; }
        case 12:
        {Plant jarmuz("jarmuz", 10, 24, 40, 60, 8, 10, 1, 1); greenhouse.add_plant(jarmuz); break; }
        case 13:
        {Plant kaktus("kaktus", 18, 30, 10, 30, 4, 6, 0, 2); greenhouse.add_plant(kaktus); break; }
        case 14:
        {Plant kalatea("kalatea", 18, 24, 60, 80, 8, 10, 1, 1); greenhouse.add_plant(kalatea); break; }
        case 15:
        {Plant kapusta("kapusta", 10, 20, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(kapusta); break; }
        case 16:
        {Plant kolendra("kolendra", 10, 27, 40, 70, 8, 12, 1, 1); greenhouse.add_plant(kolendra); break; }
        case 17:
        {Plant limonka("limonka", 18, 30, 50, 70, 8, 12, 1, 2); greenhouse.add_plant(limonka); break; }
        case 18:
        {Plant lubczyk("lubczyk", 10, 25, 40, 60, 8, 10, 1, 2); greenhouse.add_plant(lubczyk); break; }
        case 19: {Plant majeranek("majeranek", 10, 25, 40, 60, 8, 10, 1, 1); greenhouse.add_plant(majeranek); break; }
        case 20:
        {Plant malina("malina", 15, 25, 50, 70, 8, 12, 2, 1); greenhouse.add_plant(malina); break; }
        case 21:
        {Plant mandarynka("mandarynka", 20, 30, 50, 70, 10, 12, 1, 2); greenhouse.add_plant(mandarynka); break; }
        case 22:
        {Plant maranta("maranta", 18, 24, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(maranta); break; }
        case 23:
        {Plant marchew("marchew", 10, 25, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(marchew); break; }
        case 24:
        {Plant melon("melon", 20, 30, 60, 80, 8, 12, 1, 2); greenhouse.add_plant(melon); break; }
        case 25:
        {Plant mieta("mieta", 15, 24, 40, 60, 8, 10, 1, 1); greenhouse.add_plant(mieta); break; }
        case 26:
        {Plant monstera("monstera", 18, 28, 50, 70, 8, 10, 1, 2); greenhouse.add_plant(monstera); break; }
        case 27:
        {Plant ogorek("ogorek", 18, 30, 60, 80, 10, 12, 1, 2); greenhouse.add_plant(ogorek); break; }
        case 28:
        {Plant oregano("oregano", 15, 25, 40, 60, 8, 10, 2, 1); greenhouse.add_plant(oregano); break; }
        case 420:
        {Plant trawa("trawa", 18, 30, 40, 60, 10, 12, 2, 2); greenhouse.add_plant(trawa); break; }
        case 29:
        {Plant paprotka("paprotka", 18, 24, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(paprotka); break; }
        case 30:
        {Plant papryczka_chilli("papryczka chilli", 20, 30, 50, 70, 10, 12, 1, 2); greenhouse.add_plant(papryczka_chilli); break; }
        case 31:
        {Plant papryka_slodka("papryka slodka", 20, 30, 50, 70, 10, 12, 1, 2); greenhouse.add_plant(papryka_slodka); break; }
        case 32:
        {Plant pietruszka("pietruszka", 10, 25, 40, 60, 8, 10, 1, 1); greenhouse.add_plant(pietruszka); break; }
        case 33:
        {Plant pomidor("pomidor", 15, 30, 50, 70, 8, 12, 2, 1); greenhouse.add_plant(pomidor); break; }
        case 34:
        {Plant por("por", 10, 25, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(por); break; }
        case 35:
        {Plant poziomka("poziomka", 15, 24, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(poziomka); break; }
        case 36:
        {Plant rzodkiew("rzodkiew", 10, 20, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(rzodkiew); break; }
        case 37:
        {Plant sansewieria("sansewieria", 18, 24, 30, 50, 6, 8, 0, 1); greenhouse.add_plant(sansewieria); break; }
        case 38:
        {Plant seler("seler", 10, 20, 40, 60, 8, 10, 1, 1); greenhouse.add_plant(seler); break; }
        case 39:
        {Plant storczyk("storczyk", 18, 24, 50, 70, 8, 10, 0, 3); greenhouse.add_plant(storczyk); break; }
        case 40:
        {Plant strelicja("strelicja", 18, 30, 50, 70, 8, 12, 1, 2); greenhouse.add_plant(strelicja); break; }
        case 41:
        {Plant szalwia("szalwia", 10, 25, 40, 60, 8, 10, 1, 1); greenhouse.add_plant(szalwia); break; }
        case 42:
        {Plant szczypiorek("szczypiorek", 10, 25, 40, 60, 8, 10, 1, 1); greenhouse.add_plant(szczypiorek); break; }
        case 43:
        {Plant trawa_cytrynowa("trawa cytrynowa", 20, 30, 60, 80, 10, 12, 1, 2); greenhouse.add_plant(trawa_cytrynowa); break; }
        case 44:
        {Plant truskawka("truskawka", 15, 25, 50, 70, 8, 12, 2, 1); greenhouse.add_plant(truskawka); break; }
        case 45:
        {Plant tymianek("tymianek", 10, 25, 40, 60, 8, 10, 2, 1); greenhouse.add_plant(tymianek); break; }
        case 46:
        {Plant winogrona("winogrona", 18, 30, 50, 70, 10, 12, 1, 2); greenhouse.add_plant(winogrona); break; }
        case 47:
        {Plant ziemniak("ziemniak", 10, 20, 50, 70, 8, 10, 1, 1); greenhouse.add_plant(ziemniak); break; }
        default:
            cout << "Nieprawidlowy wybor." << endl; break;
    }
}
int main()
{
    double height, width, length, surface;
    int plants_number=0, check_plant_number = 0, duration, species_number, choice;
    double desired_temperature, desired_humidity, desired_light_time;
    cout << "WITAJ W SYMULACJI SZKLARNI\n";
    cout << "podaj wymiary szklarni:\n";
    cout << "wysokosc: "; cin >> height;
    cout << "szerokosc: "; cin >> width;
    cout << "dlugosc: "; cin >> length;
    cout << "podaj czas symulacji (w dniach): "; cin >> duration;
    cout << "podaj temperature: "; cin >> desired_temperature;
    cout << "podaj wilgotnosc: "; cin >> desired_humidity;
    cout << "podaj czas naswieltania: "; cin >> desired_light_time;


    surface = width * length;
    plants_number = surface / 0.7;
    Greenhouse greenhouse(height, width, length, desired_temperature, desired_humidity, desired_light_time);
    do
    {
        cout << "wybierz rosline do wyhodowania (0 aby zakonczyc wybieranie)\n";
        cout << "1. aloes\t\t2. ananas\t\t3. arbuz\t\t4. bazylia\n";
        cout << "5. begonia\t\t6. broku³\t\t7. cebula\t\t8. czosnek\n";
        cout << "9. fikus\t\t10. fittonia\t\t11. hortensja\t12. jarmu¿\n";
        cout << "13. kaktus\t\t14. kalatea\t\t15. kapusta\t\t16. kolendra\n";
        cout << "17. limonka\t\t18. lubczyk\t\t19. majeranek\t\t20. malina\n";
        cout << "21. mandarynka\t\t22. maranta\t\t23. marchew\t\t24. melon\n";
        cout << "25. miêta\t\t26. monstera\t\t27. ogórek\t\t28. oregano\n";
        cout << "29. paprotka\t\t30. papryczka chilli\t31. papryka s³odka\t\t32. pietruszka\n";
        cout << "33. pomidor\t\t34. por\t\t\t35. poziomka\t\t36. rzodkiew\n";
        cout << "37. sansewieria\t\t38. seler\t\t39. storczyk\t\t40. strelicja\n";
        cout << "41. sza³wia\t\t42. szczypiorek\t\t43. trawa cytrynowa\t\t44. truskawka\n";
        cout << "45. tymianek\t\t46. winogrona\t\t47. ziemniak\n";
        cin >> choice;
        if (choice != 0)
        {
            cout << "podaj liczbe roslin: "; cin >> species_number;
            if (check_plant_number + species_number > plants_number)
            {
                species_number = plants_number - check_plant_number;
                cout << "podano za duza liczbe, mozesz wyhodowac jedynie " << species_number << " roslin";
            }
            for (int i = 0; i < species_number; i++)
            {
                plant_catalog(greenhouse, choice);
            }
        }
    } while (choice != 0&& check_plant_number<plants_number);
    Simulation simulation(duration, greenhouse);
    simulation.greenhouse.set_desired_temperature(desired_temperature);
    simulation.greenhouse.set_desired_humidity(desired_humidity);
    simulation.greenhouse.set_desired_light(desired_humidity);
    World world;
    simulation.run();
    simulation.save_parameters_to_file();
    return 0;
}

