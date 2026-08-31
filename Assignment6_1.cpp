#include <iostream>
using namespace std;

class Product
{
    protected:
    int id;
    string title;
    double price;

    public:
    Product(void):id(0), title(), price(0){ }
    Product(int id,string title, double price) : id(id), title(title), price(price){ }

    void acceptRecord(void)
    {
        cout<<"id : ";
        cin>>id;
        cout<<"title :";
        cin>>id;
        cout<<"price : ";
        cin>>price;
    }
    void printRecord(void)
    {
        cout<<"id : "<<id<<endl;
        cout<<"title : "<<title<<endl;
        cout<<"price : "<<price<<endl;
    }
    ~Product(){}
};

class Book : public Product
{
    private:
    string author;

    public:
    Book(): author(" "){};
    Book(int id, string title, double price, string author): Product(id, title, price), author(author){}
    void acceptRecord(void)
    {
        Product::acceptRecord();
        cout<<"Author : ";
        cin>>author;
    }
    void printRecord(void)
    {
        Product::printRecord();
        cout<<"Author : "<<author;
    }

    double calculateDiscount(void){
        return price * 0.10;
    }

};

class Tape : public Product
{
    private:
    string artist;

    public:
    Tape():artist(" "){}
    Tape(int id, string title, double price, string artist) : Product(id, title, price), artist(artist) {}

    void acceptRecord(void)
    {
        Product::acceptRecord();
        cout<<"Artist : ";
        cin>>artist;
    }
    void printRecord(void)
    {
        Product::printRecord();
        cout<<"Artist : "<<artist;
    }

    double calculateDiscount(void)
    {
        return price * 0.05;
    }
};

int menuList(){
    int choice;
    cout<<"0.Exit"<<endl;
    cout<<"1.Add Book"<<endl;
    cout<<"2.Add Tape"<<endl;
    cout<<"Enter a choice"<<endl;
    cin>>choice;
    return choice;
}

int main()
{
    int choice;

    while((choice = ::menuList()) != 0){

        Product *product = new Product[3]; 
        
        delete[] product;
        product = NULL;
    }

    return 0;
}