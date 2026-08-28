#include <iostream>
using namespace std;

//The tollbooth keeps track of the number of cars that have gone by and of the total amount of money collected

class Tollbooth{
    private:
    unsigned  totalCars;
    double totalAmount;

    public:

    Tollbooth(){
        this->totalCars = 0;
        this->totalAmount =0;
    }
    void payingCar(){
        this->totalCars++ ; 
        this->totalAmount += 0.5;
    }

    void nopayCar(){
        this->totalCars++; 
    }

    void printOnConsole(){
        int total_payingCars = totalAmount/0.5;
        int total_nonpayingCars = this->totalCars - total_payingCars;


        cout<<"Total number of Cars: "<<this->totalCars<<endl;
        cout<<"Total amount of both Cars : "<<this->totalAmount<<endl;
        cout<<"Total number of Paying cars : "<<total_payingCars<<endl;
        cout<<"Total number of non paying cars : "<<total_nonpayingCars<<endl;

    }
};

int main()
{
    Tollbooth tb;
    tb.printOnConsole();
    tb.nopayCar();
    tb.payingCar();

    tb.printOnConsole();

    return 0;
}
