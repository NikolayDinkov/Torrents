#include <iostream>
#include <cstring>
#include <vector>
#include <string>

#include "server.hpp"

using namespace std;

int main()
{
    try
    {
        GameTorrent game1("Sniper elite 1", 100000, "Pesho", 10000, "PS4", 'M');
        GameTorrent game2("The crew 2", 170000, "Pesho", 1250, "Windows", 'P');
        GameTorrent game3("The crew 1", 150000, "Pesho", 1000, "PS4", 'P');
        GameTorrent game4("LoL", 200000, "Pesho", 2, "Windows", 'E');
        GameTorrent game5("WoW", 200000, "Pesho", 2, "Windows", 'E');

        FilmTorrent film1("Star wars 1", 2500, "Gosho", 120000, "Pesho ot Dimitrovgrad", 120, "English");
        FilmTorrent film2("Star wars 2", 7500, "Gosho", 120225, "Pesho ot Sofiq", 130, "English");
        FilmTorrent film3("Star wars 3", 5000, "Gosho", 125000, "Pesho ot Plovdiv", 140, "English");
        FilmTorrent film4("Star wars 4", 12000, "Gosho", 210000, "Pesho ot Sofiq", 110, "English");
        FilmTorrent film5("Star wars 5", 10000, "Gosho", 215000, "Pesho ot Plovdiv", 180, "English");

        SoftwareTorrent software1("Merc-eyetriger", 1000, "Pesho", 200000, "Visteon", "Unix", {3, 5, 1});
        SoftwareTorrent software2("Merc-hadtriger", 1300, "Pesho", 200000, "Visteon", "Unix", {3, 5, 2});
        SoftwareTorrent software3("Merc-autopilot", 2400, "Pesho", 200000, "Visteon", "Linux", {3, 5, 3});
        SoftwareTorrent software4("BMW-autopilot", 5600, "Gosho", 200000, "Visteon", "Linux", {1, 1, 1});
        SoftwareTorrent software5("AUDI-autopilot", 6500, "Gosho", 200000, "Visteon", "Linux", {1, 11, 4});



        Server server1;
        server1.add_user("Gosho");
        server1.add_user("Pesho");
        server1.add_torrent(game1);
        server1.add_torrent(game2);
        server1.add_torrent(game3);
        server1.add_torrent(game4);
        server1.add_torrent(game5);

        server1.add_torrent(film1);
        server1.add_torrent(film2);
        server1.add_torrent(film3);
        server1.add_torrent(film4);
        server1.add_torrent(film5);

        server1.add_torrent(software1);
        server1.add_torrent(software2);
        server1.add_torrent(software3);
        server1.add_torrent(software4);
        server1.add_torrent(software5);

        vector<Torrent*> try1 = server1.search_inName("1");
        for(int i = 0; i < try1.size(); i++)
        {
            cout << try1.at(i)->toString() << endl;
        }
        vector<GameTorrent*> try2 = server1.search_matRating('E');
        for(int i = 0; i < try2.size(); i++)
        {
            cout << try2.at(i)->toString() << endl;
        }
        vector<FilmTorrent*> try3 = server1.search_castName("Pesho ot Plovdiv");
        for(int i = 0; i < try3.size(); i++)
        {
            cout << try3.at(i)->toString() << endl;
        }
        vector<SoftwareTorrent*> try4 = server1.search_majVersion(3);
        for(int i = 0; i < try4.size(); i++)
        {
            cout << try4.at(i)->toString() << endl;
        }
    } catch(const char *err) {
        cout << err << endl;
    }
    return 0;
}