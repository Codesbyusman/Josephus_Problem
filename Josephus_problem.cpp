#include <iostream>
using namespace std;

struct circularNode
{
    int person;
    circularNode *next;
};

class circularList
{
    circularNode *head;

public:
    circularList()
    {
        head = NULL;
    }

    void insertAtme(int p)
    {
        //head is null mean first element
        if (head)
        {

            circularNode *curr = head;

            //finding the end of node
            while (curr->next != head)
            {
                curr = curr->next;
            }

            circularNode *temp = new circularNode();
            temp->person = p;

            //inserting next to current
            curr->next = temp;
            temp->next = head;
        }
        else
        {
            //first element
            circularNode *temp = new circularNode();
            temp->person = p;
            head = temp;
            temp->next = head;
        }
    }

    void deleteMe(int p)
    {
        circularNode *find = head;

        do
        {
            if (find->person == p)
            {
                //the data found
                break; //to delete
            }

            find = find->next;

        } while (find != head);

        //will delete the finded
        if (find == head)
        {

            //the first element
            if (find->next == head) //mean last
            {
                circularNode *deleteme = find;
                delete find;
                head = NULL;
            }
            else
            {
                //the first element and other element exist too
                circularNode *deleteme = find;
                circularNode *temp = head;

                while (temp->next != head)
                {

                    temp = temp->next;
                }

                head = find->next;
                //and end should also point to new head;
                temp->next = head;

                delete find;
            }
        }
        else
        {
            //in between some where

            //finding the previous
            circularNode *temp = head;

            while (temp->next != find)
            {

                temp = temp->next;
            }

            //pointing to next
            temp->next = find->next;

            delete find;
        }
    }

    void display()
    {
        circularNode *curr = head;

        if (head)
        {
            do
            {
                cout << curr->person << " ";
                curr = curr->next;
            } while (curr != head);

            cout << endl;
        }
        else
        {
            cout << "\n\t\t Empty " << endl;
        }
    }

    bool listHaveoneMember()
    {

        circularNode *curr = head;
        int members = 0;

        do
        {
            members++;
            curr = curr->next;
        } while (curr != head);

        if (members == 1)
        {
            return 1; //only one
        }

        return 0;
    }

    void startGame(int positionAt)
    {
        circularNode *temp = head;

        while (!listHaveoneMember())
        {

            cout << "\n\t\t ";
            display();

            //will move for the given position
            for (int i = 1; i < positionAt; i++)
            {
                temp = temp->next;
            }

            cout << "\n\t\t :::: bye " << temp->next->person << " ::::::" << endl;

            //will delete the temp
            //started from 1 and
            deleteMe(temp->next->person);

            temp = temp->next;

            cout << "\n\t\t ";
            display();

            cout << endl;
            system("pause");
            cout << endl;
        }

        cout << "\n\t\t :::::: Game Ended ::::::: " << endl;
        cout << "\n\t\t ::::::: " << head->person << " Congratulations ::::::: " << endl;
    }
};

int main()
{

    circularList c;

    c.insertAtme(1);
    c.insertAtme(2);
    c.insertAtme(3);
    c.insertAtme(4);
    c.insertAtme(5);
    c.insertAtme(6);
    c.insertAtme(7);

    system("pause");

    c.startGame(2);

    return 0;
}
