#include "main_classes.cpp"
class stats
{
public:
    void show_most_played()
    {
        if (i == 0)
        {
            cout << "Nothing in library yet" << endl;
            return;
        }
        cout << "TOP 5 MOST PLAYED" << endl;
        for (int k = 0; k < (i - 1); k++)
        {
            int max = k;
            for (int j = k + 1; j < i; j++)
            {
                if (library[j]->getPlays() > library[max]->getPlays())
                {
                    max = j;
                }
            }
            swap(library[max], library[k]);
        }
        int actual = (i < 5) ? i : 5;
        for (int u = 0; u < actual; u++)
        {
            cout << u + 1 << ". " << library[u]->getTitle() << "   " << library[u]->getPlays() << " plays" << endl;
        }
    }
};
stats stat;