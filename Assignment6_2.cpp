#include <iostream>
using namespace std;

class Employee
{   
    private:
    int id;
    double salary;
    public:
    Employee(void): id(0), salary(0.0){ }
    Employee(int id, double salary) : id(id), salary(salary){ }
    void setId(int)
    {
        this->id = id;
    }
    int getId()
    {
        return this->id;
    }
    void setSalary(double salary)
    {
        this->salary = salary;
    }
    double getSalary()
    {
        return this->salary;
    }
    virtual void accept(void)
    {
        cout << " Enter Id : ";
        cin >> id;
        cout << " Enter Salary : ";
        cin >> salary;
    }
    void display(void)
    {
        cout << " Id : " << id << endl;
        cout << " Salary : " << salary << endl;
    }
};

class Manager : virtual public Employee
{
    private:
    double bonus;
    public:
    Manager(int id, double salary, double bonus):Employee(id, salary), bonus(bonus){}
    void setBonus(double bonus){
        this->bonus = bonus;
    }
    double getBonus(void)
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
    void acceptManager(){
        cout<<"bonus";
        cin>>bonus;
    }
    void displayManager()
    {
        cout<<"Bonus : "<<bonus<<endl;
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


int main()
{
    cout << " Manager Details : " << endl;
    Manager m;
    m.accept();
    cout << " Salesman Details : " << endl;
    Salesman s;
    s.accept();
    cout << " Sales Manager Details : " << endl;
    SalesManager sm;
    sm.accept();

    cout << " Manager :" << endl;
    m.display();

    cout<<" Salesman : "<<endl;
    s.display();

    cout<<" Sales Manager : "<<endl;
    sm.display();
    return 0;
}