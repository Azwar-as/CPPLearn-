#include <iostream>
using namespace std;

struct node
{
    int nilai;
    struct node *alamat;

    static node *head;

    static void insDepan(int x)
    {
        node *Baru = new node;
        Baru->nilai = x;
        Baru->alamat = head;
        head = Baru;
    }

    static void insPosisi(int x, int posisi)
    {
        node *Baru = new node;
        Baru->nilai = x;
        Baru->alamat = NULL;

        if (posisi <= 1 || head == NULL)
        {
            // Kalau posisi <= 1 atau list kosong, insert depan
            Baru->alamat = head;
            head = Baru;
        }
        else
        {
            node *temp = head;
            int count = 1;

            // Maju sampai sebelum posisi yang dituju
            while (temp != NULL && count < posisi - 1)
            {
                temp = temp->alamat;
                count++;
            }

            if (temp != NULL)
            {
                Baru->alamat = temp->alamat;
                temp->alamat = Baru;
            }
            else
            {
                cout << "Posisi melebihi panjang linked list, data tidak ditambahkan.\n";
                delete Baru;
            }
        }
    }

    static void tampil()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->nilai << " -> ";
            temp = temp->alamat;
        }
        cout << "NULL" << endl;
    }
};

node *node::head = NULL;

int main()
{

    node::insDepan(30);
    node::insDepan(20);
    node::insDepan(10);

    cout << "Sebelum insert tengah:\n";
    node::tampil();

    node::insPosisi(25, 3);

    cout << "Setelah insert di posisi ke-3:\n";
    node::tampil();

    return 0;
}
