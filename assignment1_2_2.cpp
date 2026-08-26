#include<iostream>
using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;

    public:
    void initDate(){
        day = 01;
        month = 01;
        year = 2001;
    }

    void acceptDateFromConsole(){ 
        cout<<"Day: ";
        cin>>day;
        cout<<"Month: ";
        cin>>month;
        cout<<"Year: ";
        cin>>year;
    } 

    void printDateOnConsole(){
        cout<<"Day : "<<day << " "; 
        cout<<"Month : "<<month << " "; 
        cout<<"Year : "<<year << " " << endl; 
    }
    bool isLeapYear() {
        if ((year % 4 == 0)){
            return true;
        }
        return false;
    }
};

int menuList(void){
    int choice;
    cout<<"0.Exit\n";
    cout<<"1.Init Date\n";
    cout<<"2.Accept date\n";
    cout<<"3.Print date\n";
    cout<<"4.Check for leap year\n";
    cout<<"Enter choice: ";
    cin>>choice;
    return choice;
}

int main() {
    Date dt; 
    dt.initDate(); 

    int choice;
    while ((choice = menuList()) != 0) {
        switch (choice) {
            case 1:
                dt.initDate();
                cout << "Initialized Date\n";
                break;
            case 2:
                dt.acceptDateFromConsole(); 
                break;
            case 3:
                dt.printDateOnConsole(); 
                break;
            case 4:
                if (dt.isLeapYear()) {
                    cout << " a Leap Year!\n";
                } else {
                    cout<< " not a Leap Year.\n";
                }
                break;
            default:
                break;
        }
    }
    return 0;
} 