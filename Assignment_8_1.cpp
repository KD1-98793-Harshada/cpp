#include<iostream>
using namespace std;

class Distance
{
    private:
    int feet;
    int inches;

    public:
    Distance( void )
    {
        this->feet = 0;
        this->inches = 0;
    }

    Distance(int feet, int inches)
    {
        this->feet = feet;
        this->inches = inches;

        this->feet = this->feet + this->inches / 12;
        this->inches = this->inches % 12;
    }

    Distance operator+(Distance d)
    {
        Distance temp;

        temp.feet = this->feet + d.feet;
        temp.inches = this->inches + d.inches;

        temp.feet = temp.feet + temp.inches / 12;
        temp.inches = temp.inches % 12;

        return temp;
    }

    Distance operator++( void )
    {
        this->inches++;

        if(this->inches == 12)
        {
            this->feet++;
            this->inches = 0;
        }

        return *this;
    }

    friend Distance operator--(Distance &d);

    friend ostream& operator<<(ostream &out, Distance d);

    friend istream& operator>>(istream &in, Distance &d);
};

Distance operator--(Distance &d)
{
    if(d.inches == 0)
    {
        d.feet--;
        d.inches = 11;
    }
    else
    {
        d.inches--;
    }

    return d;
}

ostream& operator<<(ostream &out, Distance d)
{
    out<<"Feet : "<<d.feet<<endl;
    out<<"Inches : "<<d.inches<<endl;

    return out;
}

istream& operator>>(istream &in, Distance &d)
{
    cout<<"Enter Feet : ";
    in>>d.feet;

    cout<<"Enter Inches : ";
    in>>d.inches;

    d.feet = d.feet + d.inches / 12;
    d.inches = d.inches % 12;

    return in;
}

int main()
{
    Distance d1;
    Distance d2;
    Distance d3;

    cout<<"Enter First Distance"<<endl;
    cin>>d1;

    cout<<endl;

    cout<<"Enter Second Distance"<<endl;
    cin>>d2;

    cout<<endl;

    d3 = d1 + d2;

    cout<<"Addition of Distance"<<endl;
    cout<<d3;

    cout<<endl;

    ++d1;

    cout<<"After Incrementing First Distance"<<endl;
    cout<<d1;

    cout<<endl;

    --d2;

    cout<<"After Decrementing Second Distance"<<endl;
    cout<<d2;

    return 0;
}