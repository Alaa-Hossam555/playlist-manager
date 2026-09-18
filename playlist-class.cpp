#include "main_classes.cpp"
struct node
{
    node *pre;
    node *next;
    mediaItem *data;
};
class playlist
{
private:
    node *head = NULL;

public:
    int counter = 0;
    node *getHead()
    {
        return head;
    }
    void addtrack(mediaItem *newtrack)
    {

        node *ptr = new node;
        ptr->data = newtrack;
        ptr->pre = NULL;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = ptr;
            ptr->pre = current;
        }
        counter++;
    }
    void removeTrack(mediaItem *deleteTrack)
    {

        node *dpointer = getHead();
        while (dpointer != NULL && dpointer->data != deleteTrack)
        {
            dpointer = dpointer->next;
        }
        if (dpointer == NULL)
        {
            cout << "track not found" << endl;
            return;
        }
        if (dpointer->pre != NULL)
        {
            dpointer->pre->next = dpointer->next;
        }
        else
        {
            head = dpointer->next;
        }
        if (dpointer->next != NULL)
        {
            dpointer->next->pre = dpointer->pre;
        }
        counter--;
        delete dpointer;
    }
    void viewlist()
    {
        node *curr = getHead();
        if (curr == NULL)
        {
            cout << "No list avaliable" << endl;
            return;
        }
        int index = 1;
        while (curr != NULL)
        {
            cout << index << ". " << curr->data->getTitle() << endl;
            curr = curr->next;
            index++;
        }
    }
    void play(mediaItem *library[], int i)
    {
        char c;
        node *play = getHead();
        while (c != 'q')
        {
            if (counter > 0)
            {
                play->data->play();
                play->data->setPlays(play->data->getPlays() + 1);
                cout << "(n) next   (p) previous   (q) quit" << endl;
                cout << "> ";
                cin >> c;
                switch (c)
                {
                case 'n':
                    if (play->next != NULL)
                    {
                        play = play->next;
                    }
                    else
                    {
                        cout << "[!] You are on the last track." << endl;
                    }
                    break;
                case 'p':
                    if (play->pre != NULL)
                    {
                        play = play->pre;
                    }
                    else
                    {
                        cout << "[!] You are at beginning of track." << endl;
                    }
                    break;
                case 'q':
                    cout << "You have exitted playlist" << endl;
                    break;
                }
            }
            else
            {
                cout << "Nothing to listen to now" << endl;
            }
        }
    }
    void printForward(node *curr_node)
    {
        if (curr_node == NULL)
        {
            return;
        }
        cout << curr_node->data->getID() << ". " << curr_node->data->getTitle() << endl;
        printForward(curr_node->next);
    }
    void printBack(node *last)
    {
        if (last == NULL)
        {
            return;
        }
        cout << last->data->getID() << ". " << last->data->getTitle() << endl;
        printBack(last->pre);
    }
    int sec(string duration)
    {
        int min = stoi(duration.substr(0, 2));
        int sec = stoi(duration.substr(3, 2));
        return min * 60 + sec;
    }
    int total(node *cu)
    {
        if (cu == NULL)
        {
            return 0;
        }
        return sec(cu->data->getDuration()) + total(cu->next);
    }
    void showDuration()
    {
        int t = total(getHead());
        int minutes = t / 60;
        int seconds = t % 60;
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
            cout << "0" << seconds;
        }
        else
        {
            cout << seconds << " over " << counter << " tracks" << endl;
        }
    }
    ~playlist()
    {
        node *current = getHead();
        while (current != NULL)
        {
            node *temp = current;
            current = current->next;
            delete temp;
        }
    }
};
playlist p;
void show_playList()
{
    cout << "-------playlist--------" << endl;
    cout << "1.Add Track" << endl;
    cout << "2.Remove track" << endl;
    cout << "3.View playlist" << endl;
    cout << "4.play" << endl;
    cout << "5.print forward" << endl;
    cout << "6.print backward" << endl;
    cout << "7.Total duration" << endl;
    cout << "0.back" << endl;
    cout << "-------------------------" << endl;
    int ch;
    do
    {
        cout << "choose: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            if (i == 0)
            {
                cout << "Nothing in library" << endl;
                break;
            }
            else
            {
                for (int g = 0; g < i; g++)
                {
                    cout << library[g]->getID() << ". " << library[g]->getTitle() << endl;
                }
                int idtrack;
                cout << "choose id of item you wanna add to playlist: ";
                cin >> idtrack;
                p.addtrack(library[idtrack - 1]);
            }
            break;
        }
        case 2:
        {
            if (i == 0)
            {
                cout << "Nothing in library" << endl;
                break;
            }
            else
            {
                int d_id_track;
                p.viewlist();
                cout << "choose id you wanna delete: ";
                cin >> d_id_track;
                p.removeTrack(library[d_id_track - 1]);
            }
            break;
        }
        case 3:
            if (i == 0)
            {
                cout << "Nothing in library" << endl;
                break;
            }
            p.viewlist();
            break;

        case 4:
            if (i == 0)
            {
                cout << "Nothing in library" << endl;
                break;
            }
            p.play(library, i);
            break;
        case 5:
        {
            if (i == 0)
            {
                cout << "Nothing in library" << endl;
                break;
            }
            p.printForward(p.getHead());
            break;
        }
        case 6:
        {
            if (i == 0)
            {
                cout << "Nothing in library" << endl;
                break;
            }
            node *tail = p.getHead();
            if (tail == NULL)
            {
                cout << "nothing in list" << endl;
            }
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            p.printBack(tail);
            break;
        }
        case 7:
        {
            if (i == 0)
            {
                cout << "Nothing in library" << endl;
                break;
            }
            p.showDuration();
            break;
        }
        case 0:
            cout << "You have exitted playlist" << endl;
            break;
        default:
            cout << "incorrect entry" << endl;
            break;
        }

    } while (ch != 0);
}