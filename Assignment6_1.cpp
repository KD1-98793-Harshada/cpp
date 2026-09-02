#include <iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title;
    double price;

public:
    Product() : id(1), title(" "), price(1) {};

    Product(int id, string title, int price) : id(id), title(title), price(price) {};

    virtual void acceptData()
    {
        cout << " ID :";
        cin >> id;
        cout << " Title :";
        cin >> title;
        cout << " Price :";
        cin >> price;
    }

    virtual void printData()
    {
        cout << " ID : " << id << endl;
        cout << " Title : " << title << endl;
        cout << " Price : " << price << endl;
    }
        virtual double bill() = 0;
};

class Book : public Product
{
private:
    string author;

public:
    Book() : author(" ") {};

    Book(int id, string title, int price, string author) : author(author), Product(id, title, price) {};

    void acceptData()
    {
        Product::acceptData();
        cout << " Author :";
        cin >> author;
    }

    void printData()
    {
        Product::printData();
        cout << " Author : " << author << endl;
    }

    double bill()
    {
        double discount = this->price * 0.1;
        double finalPrice = this->price - discount;
        return finalPrice;
    }
};

class Tape : public Product
{
private:
    string artist;

public:
    Tape() : artist(" ") {};

    Tape(int id, string title, int price, string artist) : artist(artist) {};

    void acceptData()
    {
        Product::acceptData();
        cout << " Artist :";
        cin >> artist;
    }

    void printData()
    {
        Product::printData();
        cout << " Artist : " << artist << endl;
    }

    double bill()
    {
        double discount = this->price * 0.05;
        double finalPrice = this->price - discount;
        return finalPrice;
    }
};

int menuList()
{
    int choice;
    cout << "0. Exit" << endl;
    cout << "1. Add Book " << endl;
    cout << "2. Add Tape " << endl;
    cout << "3. Final Bill " << endl;
    // cout << "3. Display Only Hours of Time " << endl;
    cin >> choice;
    return choice;
};

int main()
{
    Product *arr[3];
    int count = 0;
    int choice;
    while ((choice = ::menuList()) != 0)
    {

        switch (choice)
        {
        case 1:
        {
            if (count == 3)
            {
                cout << " CART FULL !!" << endl;
                break;
            }

            arr[count] = new Book();
            arr[count]->acceptData();
            count++;
            break;
        }

        case 2:
        {
            if (count == 3)
            {
                cout << " CART FULL !!" << endl;
                break;
            }

            arr[count] = new Tape();
            arr[count]->acceptData();
            count++;
            break;
        }
        case 3:
        {
            double totalBill = 0;
            for (int i = 0; i < count; i++)
            {
                totalBill += arr[i]->bill();
                arr[i]->printData();
            }
            cout << "Total Bill after Overall Discount : " << totalBill << endl;
            break;
        }
        }
    }
    for (int i = 0; i < count; i++)
    {
        delete arr[i];
    }

    return 0;
}