#ifndef SOFTWARE_HPP
#define SOFTWARE_HPP

#include <iostream>
#include "torrent.hpp"

using namespace std;

class SoftwareTorrent : public Torrent
{
    string establisher;
    string op_system;
    vector<int> version;
public:
    SoftwareTorrent(string name, int size, string uploader, int downloads, string establisher, string system, vector<int> version)
    : establisher(establisher), op_system(system), version(version), Torrent(name, size, uploader, downloads)
    {
        if(establisher == "" || establisher == " ")
        {
            throw "Establisher is empty";
        }
        if(op_system == "" || op_system == " ")
        {
            throw "Operation system is empty";
        }
    }
    SoftwareTorrent(const SoftwareTorrent& torrent)
    : establisher(torrent.establisher), op_system(torrent.op_system), version(torrent.version), Torrent(torrent.name, torrent.size, torrent.uploader, torrent.downloads)
    {}
    string toString()
    {
        return "Software torrent:\nMade by " + establisher + " working on " + op_system + 
                " with version " + to_string(version.at(0)) + "." + to_string(version.at(1)) + "." + to_string(version.at(2)) + 
                "\nTorrent info: Name - " + this->name + ", size - " + to_string(this->size) + ", uploaded by " + this->uploader + 
                " has " + to_string(this->downloads) + " downloads";
    }
    int get_majVersion()
    {
        return this->version.at(0);
    }
};

#endif

