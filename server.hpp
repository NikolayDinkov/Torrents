#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <vector>
#include "torrent.hpp"
#include "game.hpp"
#include "film.hpp"
#include "software.hpp"

class Server
{
    vector<Torrent*> torrents;
    vector<string> users;
public:
    Server() {}
    void add_torrent(Torrent& torrent)
    {
        bool if_ = false;
        for(auto it = users.begin(); it != users.end(); it++)
        {
            if(*it == torrent.get_uploader())
            {
                if_ = true;
            }
        }
        if(if_ == false)
        {
            throw "Uploader is not in our database";
        }
        torrents.push_back(&torrent);
    }
    void add_user(string user)
    {
        users.push_back(user);
    }
    const vector<Torrent*> search_inName(string filter)
    {
        cout << endl << "Search for parts in the name, FILTER IS " << filter << endl << endl;
        vector<Torrent*> found;
        for(int i = 0; i < torrents.size(); i++)
        {
            if(torrents.at(i)->get_name().find(filter) != string::npos)
            {
                found.push_back(torrents.at(i));
            }
        }
        return found;
    }
    const vector<GameTorrent*> search_matRating(char rating)
    {
        cout << endl << "Search for maturity rating, FILTER IS " << rating << endl << endl;
        if(rating != 'E' && rating != 'M' && rating != 'P')
        {
            throw "I do not like the maturity rating when we do the comparison";
        }
        vector<GameTorrent*> found;
        for(int i = 0; i < torrents.size(); i++)
        {
            if(torrents.at(i)->get_matRating() == rating)
            {
                found.push_back((GameTorrent*)torrents.at(i));
            }
        }
        return found;
    }
    const vector<FilmTorrent*> search_castName(string cast)
    {
        cout << endl << "Search for same caster, FILTER IS " << cast << endl << endl;
        vector<FilmTorrent*> found;
        for(int i = 0; i < torrents.size(); i++)
        {
            if(torrents.at(i)->get_cast() == cast)
            {
                found.push_back((FilmTorrent*)torrents.at(i));
            }
        }
        return found;
    }
    const vector<SoftwareTorrent*> search_majVersion(int version)
    {
        cout << endl << "Search for major version, FILTER IS " << version << endl << endl;
        vector<SoftwareTorrent*> found;
        for(int i = 0; i < torrents.size(); i++)
        {
            if(torrents.at(i)->get_majVersion() == version)
            {
                found.push_back((SoftwareTorrent*)torrents.at(i));
            }
        }
        return found;
    }
};

#endif