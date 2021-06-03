#ifndef TORRENT_HPP
#define TORRENT_HPP

#include <iostream>

using namespace std;

class Torrent
{
    string name;
    int size;
    string uploader;
    int downloads;

    friend class SoftwareTorrent;
    friend class GameTorrent;
    friend class FilmTorrent;
public:
    Torrent(string name, int size, string uploader, int downloads)
    : name(name), size(size), uploader(uploader), downloads(downloads)
    {
        if(name == "" || name == " ")
        {
            throw "There's no name";
        }
        if(uploader == "" || uploader == " ")
        {
            throw "There's no uploader";
        }
        if(downloads < 0)
        {
            throw "Downloads cannot be negative number";
        }
    }
    Torrent(const Torrent& torrent)
    {
        *this = torrent;
    }
    virtual string toString() = 0;
    string get_uploader()
    {
        return this->uploader;
    }
    string get_name()
    {
        return this->name;
    }
    virtual char get_matRating()
    {
        return 0;
    }
    virtual string get_cast()
    {
        return "";
    }
    virtual int get_majVersion()
    {
        return 0;
    }
};

#endif

