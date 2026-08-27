#include <iostream>
using namespace std;

class Volume{
    private :
    int lenght;
    int width;
    int height;
    public:
    Volume(void){
        this->lenght = 0;
        this->width = 0;
        this->height = 0;
    }

    Volume(int value){
        //cout<<"single value";
        this->lenght = value;
        this->width = value;
        this->height = value;
    }

    Volume (int lenght,int width, int height){
        //cout<<"3 parameters";
        this->lenght = lenght;
        this->width = width;
        this->height = height;
    }
    void acceptRecord(void){
        cout<<"Enter lenght = ";
        cin>>lenght;
        cout<<"Enter width = ";
        cin>>width;
        cout<<"Enter height = ";
        cin>>height;
    }
    void printRecord(void){
        cout<<"Volume ="<<calVolume();
            }

    int calVolume(){
        return lenght * width * height;
            }
};

int menulist(void){
    int choice;
    cout<<"0.Exit\n";
    cout<<"1. Calculate Volume with default values \n";
    cout<<"2. Calculate Volume with length,breadth and height with same value\n";
    cout<<"3. Calculate Volume with different length,breadth, height values\n";

    cin>>choice;
    return choice;
}

int main(){
    
    int choice;
    while((choice=menulist())!=0){
        switch (choice)
        {
        case 1:{
                Volume v1;
                v1.printRecord();
                break;
        }
        
        case 2:{
              int a;
              cout<<"Enter a:";
              cin>>a;

              Volume v2(a);
             cout<<"calVolume: "<< v2.calVolume()<<endl;
              break;
        }
        case 3:{
        int h,w,b;
              cout<<"Enter the height "<<endl;
              cin>>h;
              cout<<"Enter the width "<<endl;
              cin>>w;
              cout<<"Enter the breadth "<<endl;
              cin>>b;
              Volume v2(h,w,b);
              v2.printRecord();
              break;
        }
        default:{
            cout<<"Enter only 0,1,2,3";
            break;
        }
        }
    }

    return 0;
}
