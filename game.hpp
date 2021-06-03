#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "torrent.hpp"

using namespace std;

class GameTorrent : public Torrent
{
    string platform;
    char maturity_rating;
public:
    GameTorrent(string name, int size, string uploader, int downloads, string platform, char rating)
    : platform(platform), maturity_rating(rating), Torrent(name, size, uploader, downloads)
    {
        if(platform != "Windows" && platform != "PS4" && platform != "Linux")
        {
            throw "Wrong platform";
        }
        if(platform == "" || platform == " ")
        {
            throw "Platform is empty";
        }
        if(rating != 'E' && rating != 'M' && rating != 'P')
        {
            throw "I do not like the maturity rating";
        }
    }
    GameTorrent(const GameTorrent& torrent)
    : platform(torrent.platform), maturity_rating(torrent.maturity_rating), Torrent(torrent.name, torrent.size, torrent.uploader, torrent.downloads)
    {}
    string toString()
    {
        return "Game torrent:\nUsing " + platform + " platform has maturity rating '" + maturity_rating + "'" +
                "\nTorrent info: Name - " + this->name + ", size - " + to_string(this->size) + ", uploaded by " + this->uploader + 
                " has " + to_string(this->downloads) + " downloads";
    }
    char get_matRating()
    {
        return this->maturity_rating;
    }
};

#endif
