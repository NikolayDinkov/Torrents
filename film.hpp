#ifndef FILM_HPP
#define FILM_HPP

#include <iostream>
#include "torrent.hpp"

using namespace std;

class FilmTorrent : public Torrent
{
    string cast;
    int time;
    string language;
public:
    FilmTorrent(string name, int size, string uploader, int downloads, string cast, int time, string language)
    : cast(cast), time(time), language(language), Torrent(name, size, uploader, downloads)
    {
        if(cast == "" || cast == " ")
        {
            throw "Cast is empty";
        }
        if(time <= 0)
        {
            throw "Invalid time";
        }
        if(language == "" || language == " ")
        {
            throw "Language is empty";
        }
    }
    FilmTorrent(const FilmTorrent& torrent)
    : cast(torrent.cast), time(torrent.time), language(torrent.language), Torrent(torrent.name, torrent.size, torrent.uploader, torrent.downloads)
    {}
    string toString()
    {
        return "Film torrent:\nCast - " + cast + ", lenght - " + to_string(time) + ", language - " + language +
                "\nTorrent info: Name - " + this->name + ", size - " + to_string(this->size) + ", uploaded by " + this->uploader + 
                " has " + to_string(this->downloads) + " downloads";
    }
    virtual string get_cast()
    {
        return this->cast;
    }
};

#endif
