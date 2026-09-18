#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "main_classes.cpp"
#include "library_system_class.cpp"
#include "search-and-sort-part.cpp"
#include "playlist-class.cpp"
#include "queue_class.cpp"
#include "stat-class.cpp"
using namespace std;
int main()
{
    cout << "=========================================\n";
    cout << "           PLAYLIST MANAGER                              \n";
    cout << "=========================================\n";
    cout << "1. Library\n";
    cout << "2. Playlist\n";
    cout << "3. Up Next queue\n";
    cout << "4. Search and Sort\n";
    cout << "5. Stats\n";
    cout << "0. Exit\n";
    cout << "-----------------------------------------\n";
    int ch;
    do
    {
        cout << "choose: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            show_library();
            break;
        case 2:
            show_playList();
            break;
        case 3:
            show_upnextQueue();
            break;
        case 4:
            show_searchAndSort();
            break;
        case 5:
        {
            stat.show_most_played();
            cout << "Library total: " << i << " items, ";
            int td = 0;
            for (int t = 0; t < i; t++)
            {
                td += library[t]->convertTosec(library[t]->getDuration());
            }
            int minutes = td / 60;
            int seconds = td % 60;
            cout << "Total duration " << endl;
            if (minutes < 10)
            {
                cout << "0" << minutes << ":";
            }
            else
            {
                cout << minutes << ":";
            }
            if (seconds < 10)
            {
                cout << "0" << seconds << endl;
            }
            else
            {
                cout << seconds << " over " << i << " tracks" << endl;
            }
            break;
        }

        case 0:
            cout << "you have exitted" << endl;
            return 0;
        default:
            cout << "incorrect entry" << endl;
            break;
        }
    } while (ch != 0);
}
