using namespace std;
#include "main_classes.cpp"
#include <iostream>
class SearchAndSortSystem
{
public:
    void searchByExactTitle(mediaItem *library[], int size)
    {
        if (i == 0)
        {
            cout << "Nothing in library yet" << endl;
            return;
        }
        int comp = 0, start = 0, end = size - 1, comparisons = 0;
        for (int k = 0; k < (size - 1); k++)
        {
            int min = k;
            for (int j = k + 1; j < size; j++)
            {
                if (*library[j] < *library[min])
                {
                    min = j;
                    comp++;
                }
            }
            swap(library[min], library[k]);
        }
        string t;
        cout << "Title: ";
        cin.ignore();
        getline(cin, t);
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (library[mid]->getTitle() == t)
            {
                comparisons++;
                cout << "Found in " << comparisons << " comparisons        [binary search]" << endl;
                library[mid]->getinfo();
                return;
            }
            else if (library[mid]->getTitle() > t)
            {
                end = mid - 1;
                comparisons++;
            }
            else if (library[mid]->getTitle() < t)
            {
                start = mid + 1;
                comparisons++;
            }
        }
        cout << "Title not present" << endl;
    }
    void filterByartistOrgenre(mediaItem *library[], int size)
    {
        if (i == 0)
        {
            cout << "Nothing in library yet" << endl;
            return;
        }
        string person;
        cout << "artist or host: ";
        cin.ignore();
        getline(cin, person);
        int matches = 0, j = 0;
        for (; j < size; j++)
        {
            if (library[j]->getArtist() == person)
            {
                matches++;
                if (library[j]->getID() < 10)
                {
                    cout << "0" << library[j]->getID();
                }
                else
                {
                    cout << library[j]->getID();
                }
                cout << " " << library[j]->getTitle() << "     " << person << endl;
            }
            if (library[j]->getHost() == person)
            {
                matches++;
                if (library[j]->getID() < 10)
                {
                    cout << "0" << library[j]->getID();
                }
                else
                {
                    cout << library[j]->getID();
                }
                cout << " " << library[j]->getTitle() << "     " << person << endl;
            }
        }
        if (matches > 0)
        {
            cout << matches << " matches                     [linear search]" << endl;
        }
        else
        {
            cout << "Person not found" << endl;
        }
    }
    string lower(string st)
    {
        for (char &c : st)
        {
            c = tolower(c);
        }
        return st;
    }
    void SortLibrary(mediaItem *library[], int size)
    {
        if (i == 0)
        {
            cout << "Nothing in library yet" << endl;
            return;
        }
        int ch2;
        cout << "Sort by (1) title (2) duration (3) play count: ";
        cin >> ch2;

        switch (ch2)
        {
        case 1:
        {

            int comp = 0;
            for (int a = 0; a < (size - 1); a++)
            {
                int min = a;
                for (int j = a + 1; j < size; j++)
                {
                    comp++;
                    if (lower(library[j]->getTitle()) < lower(library[min]->getTitle()))
                    {
                        min = j;
                    }
                }
                swap(library[min], library[a]);
            }
            cout << "ID  TITLE            " << endl;
            for (int y = 0; y < size; y++)
            {
                if (library[y]->getID() < 10)
                {
                    cout << "0" << library[y]->getID();
                }
                else
                {
                    cout << library[y]->getID();
                }
                cout << " " << library[y]->getTitle() << endl; // plays
            }
            cout << "sorted in " << comp << " comparisons       [selection sort]" << endl;
            break;
        }

        case 2:
        {
            int diff = 0;
            for (int k = 0; k < (size - 1); k++)
            {
                int max = k;
                for (int j = k + 1; j < size; j++)
                {
                    diff++;
                    if (library[j]->convertTosec(library[j]->getDuration()) > library[max]->convertTosec(library[max]->getDuration()))
                    {
                        max = j;
                    }
                }
                swap(library[max], library[k]);
            }
            for (int g = 0; g < i; g++)
            {
                if (library[g]->getID() < 10)
                {
                    cout << "0" << library[g]->getID() << "  ";
                }
                else
                {
                    cout << library[g]->getID() << "  ";
                }
                cout << library[g]->getTitle() << "     " << library[g]->getDuration() << endl;
            }
            cout << "sorted in " << diff << " comparisons       [selection sort]" << endl;
            break;
        }
        case 3:
        {
            int com = 0;
            for (int k = 0; k < (size - 1); k++)
            {
                int max = k;
                for (int j = k + 1; j < size; j++)
                {
                    com++;
                    if (library[j]->getPlays() > library[max]->getPlays())
                    {
                        max = j;
                    }
                }
                swap(library[max], library[k]);
            }
            cout << "ID  TITLE            PLAYS" << endl;
            for (int g = 0; g < i; g++)
            {
                if (library[g]->getID() < 10)
                {
                    cout << "0" << library[g]->getID() << "  ";
                }
                else
                {
                    cout << library[g]->getID() << "  ";
                }
                cout << library[g]->getTitle() << "     " << library[g]->getPlays() << endl;
            }
            cout << "sorted in " << com << " comparisons       [selection sort]" << endl;
            break;
        }
        }
    }
};
SearchAndSortSystem s;
void show_searchAndSort()
{
    cout << "1. Search by exact title" << endl;
    cout << "2. Filter by artist or genre" << endl;
    cout << "3. Sort library" << endl;
    cout << "0.Back" << endl;
    int ch;
    do
    {
        cout << "choose: ";
        cin >> ch;
        switch (ch)
        {
        case 1:

            s.searchByExactTitle(library, i);
            break;
        case 2:
            s.filterByartistOrgenre(library, i);
            break;
        case 3:
            s.SortLibrary(library, i);
            break;

        case 0:
            cout << "You have exitted search and sort part" << endl;
            break;
        default:
            cout << "incorrect entry" << endl;
            break;
        }
    } while (ch != 0);
}
