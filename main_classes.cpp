#pragma once
using namespace std;
int i = 0;
class mediaItem
{
private:
    string title;
    string duration;
    int plays = 0;
    int ID;

public:
    virtual void play() = 0;
    virtual void getinfo() = 0;
    void setTitle(string s)
    {
        title = s;
    }
    string getTitle()
    {
        return title;
    }
    void setDuration(string d)
    {
        duration = d;
    }
    string getDuration()
    {
        return duration;
    }
    void setID(int id)
    {
        ID = id;
    }
    int getID()
    {
        return ID;
    }
    virtual string getArtist() { return ""; }
    virtual string getHost() { return ""; }
    void setPlays(int pl)
    {
        plays = pl;
    }
    int getPlays()
    {
        return plays;
    }
    int convertTosec(string duration)
    {
        int mm = stoi(duration.substr(0, 2));
        int ss = stoi(duration.substr(3, 2));
        return mm * 60 + ss;
    }
    bool operator<(mediaItem &m)
    {
        return getTitle() < m.getTitle();
    }
    virtual ~mediaItem() {};
};
mediaItem *library[100];
class song : public mediaItem
{
private:
    string artist;
    string genre;

public:
    void setartist(string a)
    {
        artist = a;
    }
    string getArtist()
    {
        return artist;
    }
    void setGenre(string g)
    {
        genre = g;
    }
    string getGenre()
    {
        return genre;
    }
    void play() override
    {
        cout << "--> NOW PLAYING: " << getTitle() << " - " << getArtist() << " " << "(" << getDuration() << ")" << endl;
        cout << "  [SONG] streaming audio--.        [Song::play]" << endl;
    }
    void getinfo() override
    {
        if (getID() < 10)
        {
            cout << "0" << getID();
        }
        else
        {
            cout << getID();
        }
        cout << " SONG" << "      " << getTitle() << "         " << getArtist() << "        " << getDuration() << "      " << getPlays() << endl; // plays and endl
    }
};

class podcast : public mediaItem
{
private:
    string host;
    int ep;

public:
    void setHost(string h)
    {
        host = h;
    }
    string getHost()
    {
        return host;
    }
    void setEpisode(int e)
    {
        ep = e;
    }
    int getEpisode()
    {
        return ep;
    }
    void play() override
    {
        cout << "--> NOW PLAYING: " << getTitle() << " - " << getHost() << " " << "(" << getDuration() << ")" << endl;
        cout << "  [PODCAST] streaming audio--.        [podcast::play]" << endl;
    }
    void getinfo() override
    {
        if (getID() < 10)
        {
            cout << "0" << getID();
        }
        else
        {
            cout << getID();
        }
        cout << " PODCAST" << "   " << "Ep." << getEpisode() << " " << getTitle() << "   " << getHost() << "    " << getDuration() << "          " << getPlays() << endl; // plays and endl
    }
};