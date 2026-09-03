#include <iostream>
using namespace std;

class Employee
{
private:
    int Id;
    double salary;

public:
    Employee() : Id(101), salary(0.0) {};

    Employee(int Id, double salary) : Id(Id), salary(salary) {};

    void setId(int Id)
    {
        this->Id = Id;
    }

    int getId()
    {
        return this->Id;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return this->salary;
    }

    virtual void accept()
    {
        cout << " Enter Id : ";
        cin >> Id;
        cout << " Enter Salary : ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << " Id : " << Id << endl;
        cout << " Salary : " << salary << endl;
    }
};

class Manager : virtual public Employee
{

private:
    double bonus;

public:
    Manager() : bonus(0.0) {};

    Manager(int Id, double salary, double bouns) : Employee(Id, salary), bonus(bonus) {};

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return this->bonus;
    }

    void accept()
    {
        Employee::accept();
        this->acceptManager();
    }

    void display()
    {
        Employee::display();
        this->displayManager();
    }

protected:
    void acceptManager()
    {
        cout << " Bonus : ";
        cin >> bonus;
    }

    void displayManager()
    {
        cout << " Bonus : " << bonus << endl;
    }
};

class Salesman : virtual public Employee
{

private:
    double commission;

public:
    Salesman() : commission(0.0) {};

    Salesman(int Id, double salary, double commission) : Employee(Id, salary), commission(commission) {};

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return this->commission;
    }

    void accept()
    {

        Employee::accept();
        this->acceptSalesman();
    }

    void display()
    {
        Employee::display();
        this->displaySalesman();
    }

protected:
    void acceptSalesman()
    {
        cout << " Commission : ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << " Commission : " << commission << endl;
    }
};

class SalesManager : public Manager, public Salesman
{

public:
    SalesManager() {};

    SalesManager(int Id, double salary, double bonus, double commission) : Employee(Id, salary), Manager(Id, salary, bonus), Salesman(Id, salary, commission) {};

    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int menuList()
{
    int choice;
    cout<<"0.Exit"<<endl;
    cout<<"1. Add Manager "<<endl;
    cout<<"2. Add Salesman "<<endl;
    cout<<"3. Add Salesmanager "<<endl;
    cout<<"4. Display the count of all employees with respect to designation "<<endl;
    cout<<"5. Display All Managers"<<endl;
    cout<<"6. Display All Salesman "<<endl;
    cout<<"7. Display All SalesManagers "<<endl;
    cout<<"Enter choice"<<endl;
    cin>>choice;
    return choice;
}

int main()
{
    int choice;
    Manager m;
    Salesman s;
    SalesManager sm;



    while((choice = ::menuList()) != 0)
    {
        switch(choice)
        {
            case 1:
                m.accept();
                break;
            case 2:
                s.accept();
                break;
            case 3:
                sm.accept();
                break;
            case 4:
                ////
                break;
            case 5:
                m.display();
                break;
            case 6:
                s.display();
                break;
            case 7:
                sm.display(); 
        }
    }
    return 0;
}