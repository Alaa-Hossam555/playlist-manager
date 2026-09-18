
using namespace std;
class librarysystem
{
public:
    void Addsong()
    {
        song *mySong = new song;
        library[i] = mySong;

        string s, d, a, g;
        cout << "Title    : ";
        cin.ignore();
        getline(cin, s);
        mySong->setTitle(s);
        cout << "Artist   : ";
        getline(cin, a);
        mySong->setartist(a);
        cout << "Duration : ";
        cin >> d;
        mySong->setDuration(d);
        cout << "Genre    : ";
        cin >> g;
        mySong->setGenre(g);

        i++;
        mySong->setID(i);
        cout << "[OK] Added. Library has " << i << " items" << endl;
    }

    void Addpodcast()
    {
        podcast *pod = new podcast;
        library[i] = pod;
        string s, d, a;
        int e;
        cout << "Title    : ";
        cin.ignore();
        getline(cin, s);
        pod->setTitle(s);
        cout << "Host     : ";
        getline(cin, a);
        pod->setHost(a);
        cout << "Duration : ";
        cin >> d;
        pod->setDuration(d);
        cout << "Episode  : ";
        cin >> e;
        pod->setEpisode(e);
        i++;
        pod->setID(i);
        cout << "[OK] Added. Library has " << i << " items" << endl;
    }
    void viewall()
    {
        if (i == 0)
        {
            cout << "Nothing added yet" << endl;
            return;
        }
        cout << "ID  TYPE      TITLE           BY             LENGTH  PLAYS" << endl;

        for (int h = 0; h < i; h++)
        {

            library[h]->getinfo();
        }
    }
    void delete_item()
    {
        if (i == 0)
        {
            cout << "Nothing is persent to delete" << endl;
            return;
        }
        string title;
        cout << "Enter the title you wanna delete: ";
        cin.ignore();
        getline(cin, title);

        for (int j = 0; j < i; j++)
        {
            if (library[j]->getTitle() == title)
            {
                delete library[j];
                for (int k = j; k < (i - 1); k++)
                {
                    library[k] = library[k + 1];
                }
                i--;
                cout << "[OK] Item got deleted" << endl;
                return;
            }
        }
        cout << "Item not found" << endl;
    }
    ~librarysystem()
    {
        for (int h = 0; h < i; h++)
        {
            delete library[h];
        }
    }
};
librarysystem lib;
void show_library()
{
    cout << "------------- LIBRARY -------------------\n";
    cout << "1. Add song\n";
    cout << "2. Add podcast\n";
    cout << "3. View all\n";
    cout << "4. Delete item\n";
    cout << "0. Back\n";
    cout << "-----------------------------------------\n";
    int ch;
    do
    {
        cout << "choose: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            lib.Addsong();
            break;
        case 2:
            lib.Addpodcast();
            break;
        case 3:
            lib.viewall();
            break;
        case 4:
            lib.delete_item();
            break;
        case 0:
            cout << "You have exitted library" << endl;
            break;
        default:
            cout << "incorrect entry" << endl;
            break;
        }

    } while (ch != 0);
}