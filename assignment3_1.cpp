#include <iostream>
using namespace std;

class Cylinder{
    private:
    double radius;
    double height;
    static double PI ;
    public:
    Cylinder() : radius(1),height(1){
    }

    Cylinder(double radius,double height):radius(radius), height(height){
    }

    void setRadius(double radius){
        this->radius = radius;
    }

    double getRadius(void){
        return radius;
    }

    void setHeight(double Height){
        this->height = Height;
    }

    double getHeight(void){
        return height;
    }

    double calculateVolume(void){
        return PI * radius *radius * height;
    }
};

double Cylinder::PI = 3.14;

int main(){

    Cylinder c1;
    cout<<"Volume : "<<c1.calculateVolume()<<endl;
    cout<<"Parameterless ctor"<<endl;
    Cylinder c2;
    c2.setRadius(10);
    c2.setHeight(10);
    cout<<"Radius :"<<c2.getRadius()<<endl;
    cout<<"Height : "<<c2.getHeight()<<endl;
    cout<<"Volume : "<<c2.calculateVolume()<<endl;

    Cylinder c3(2,3);
    cout<<"Double valued parameterised ctor";
    cout<<"Radius :"<<c3.getRadius()<<endl;
    cout<<"Height : "<<c3.getHeight()<<endl;
    cout<<"Volume : "<<c3.calculateVolume()<<endl;
    
    return 0;
}