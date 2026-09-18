#include "main_classes.cpp"
struct node2
{
    mediaItem *d;
    node2 *next;
};
class Upnext
{
private:
    node2 *front = NULL;
    node2 *l = NULL;
    int qsize = 0;

public:
    void setQueuesize(int qs)
    {
        qsize = qs;
    }
    int getqs()
    {
        return qsize;
    }
    node2 *getfront()
    {
        return front;
    }
    node2 *getL()
    {
        return l;
    }
    void addToTrack(mediaItem *info)
    {
        if (info == NULL)
        {
            return;
        }
        int queue_size = getqs();
        node2 *ptr = new node2;
        ptr->d = info;
        ptr->next = NULL;
        if (front == NULL)
        {
            front = ptr;
            l = ptr;
            queue_size++;
        }
        else
        {
            l->next = ptr;
            l = ptr;
            queue_size++;
        }
        setQueuesize(queue_size);
        cout << "[OK] " << ptr->d->getTitle() << " added to the queue" << endl;
    }
    void viewQueue()
    {
        if (i == 0)
        {
            cout << "Nothing in library yet" << endl;
            return;
        }
        if (front == NULL)
        {
            cout << "Nothing in the queue" << endl;
        }
        node2 *display = front;
        int index = 1;
        while (display != NULL)
        {
            cout << index << ". " << display->d->getTitle() << endl;
            display = display->next;
            index++;
        }
    }
    void playNextfromQueue()
    {

        if (front == NULL)
        {
            cout << "[X] Nothing in the queue to play" << endl;
            return;
        }
        else
        {
            node2 *dptr = front;
            cout << "--> NOW PLAYING: " << dptr->d->getTitle() << " - " << dptr->d->getArtist() << endl;
            dptr->d->setPlays(dptr->d->getPlays() + 1);
            if (front == l)
            {
                front = NULL;
                l = NULL;
            }
            else
            {
                front = front->next;
            }
            delete dptr;
            setQueuesize(getqs() - 1);
            if (getqs() > 0)
            {
                cout << getqs() << " track left in the queue." << endl;
            }
            else
            {
                cout << "Queue is now empty." << endl;
            }
        }
    }
    ~Upnext()
    {
        while (front != NULL)
        {
            node2 *temp = front;
            front = front->next;
            delete temp;
        }
    }
};
Upnext queue;
void show_upnextQueue()
{
    cout << "----------- UP NEXT ---------------------" << endl;
    cout << "1. Add to queue" << endl;
    cout << "2. view queue" << endl;
    cout << "3. play next from queue" << endl;
    cout << "0. back" << endl;
    cout << "-----------------------------------------" << endl;
    int ch;
    do
    {
        cout << "choose: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int id;
            if (i == 0)
            {
                cout << "Nothing in library yet" << endl;
                break;
            }
            for (int h = 0; h < i; h++)
            {
                cout << library[h]->getID() << ". " << library[h]->getTitle() << endl;
            }
            cout << "Track ID: ";
            cin >> id;
            if (id < 1 || id > i)
            {
                cout << "Invalid Track  ID" << endl;
            }
            else
            {
                queue.addToTrack(library[id - 1]);
            }
            break;
        }
        case 2:
            if (i == 0)
            {
                cout << "Nothing in library yet" << endl;
                break;
            }
            queue.viewQueue();
            break;
        case 3:
            if (i == 0)
            {
                cout << "Nothing in library yet" << endl;
                break;
            }
            queue.playNextfromQueue();
            break;
        case 0:
            cout << "you have exitted queue part" << endl;
            break;
        default:
            cout << "incorrect entry" << endl;
            break;
        }

    } while (ch != 0);
}