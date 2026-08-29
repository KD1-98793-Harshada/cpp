#include <iostream>
using namespace std;

class Date{
    private:
    int day;
    int month;
    int year;

    public:
    Date(void) : day(0), month(0), year(0){}
    Date(int day, int month, int year) : day(day), month(month), year(year){}

    void acceptRecord(){
        cout<<"Day : ";
        cin>>day;
        cout<<"MOnth : ";
        cin>>month;
        cout<<"Year : ";
        cin>>year;
    }
    void printRecord(){
        cout<<"Day : "<<day<<endl;
        cout<<"MOnth : "<<month<<endl;
        cout<<"Year : "<<year<<endl;
    }
};

class Person
{
    private:
    string name;
    string address;
    Date d;
    

    public:
    Person(void): name(), address() {}
    Person(string name, string address, int dob) : name(name) , address(address) {}
    
    void acceptRecord(){
        cout<<"Enter Date of Birth: ";
        d.acceptRecord();
        cout<<"Name : ";
        cin>>name;
        cout<<"Address : ";
        cin>>address;
    }
    void printRecord(){
        cout<<"BirthDate"<<endl;
        d.printRecord();
        cout<<"Name = "<<name<<endl;
        cout<<"Address = "<<address<<endl;
    }
};

class Student
{
    private:
    int id;
    int marks;
    Date joiningDate;
    Date endDate;
    string course;
    public:

    Student(void) : id(0), marks(0), course(){}
    Student(int id, int marks, string course) : id(id), marks(marks), course(course){}

    void acceptRecord(){
        cout<<"Enter Joining Date : ";
        joiningDate.acceptRecord();
        cout<<"Enter End Date: ";
        endDate.acceptRecord();
        cout<<"id : ";
        cin>>id;
        cout<<"marks : ";
        cin>>marks;
        cout<<"course : ";
        cin>>course;
    }

    void printRecord(){
        cout<<"Enter Joining Date : ";
        joiningDate.printRecord();
        cout<<"Enter End Date: ";
        endDate.printRecord();
        cout<<"id = "<<id<<endl;
        cout<<"marks = "<<marks<<endl;
        cout<<"course = "<<course<<endl;
    }
};

// int main(){
//     Student stu;
//     stu.acceptRecord();
    
// }



int main(){

    Person p;
    p.acceptRecord();
    p.printRecord();

    return 0;
}