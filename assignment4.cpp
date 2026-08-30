#include<iostream>
using namespace std;

class Time{
    private:
    int hrs;
    int mins;
    int secs;
    public:
    Time(void) : hrs(0) , mins(0), secs(0){
    }
    Time(int hrs, int mins, int secs) : hrs(hrs), mins(mins) , secs(secs){
    }
    void setHrs(int hrs){
        this->hrs = hrs;
    }
    void setMins(int mins){
        this->mins = mins;
    }
    void setSecs(int secs){
        this->secs = secs;
    }
    int getHrs(void){
        return this->hrs;
    }
    int getMins(void){
        return this->mins;
    }
    int getSecs(void){
        return secs;
    }
    void acceptTime(){
        cout<<"Hours : MIns : Secs";
        cin>>hrs>>mins>>secs;
    }
   

    void printTime() {
        cout<<" hours :"<<hrs<<endl;
        cout<<" min :"<<mins<<endl;
        cout<<" sec :"<<secs<<endl;
        
    }
};

int menuList(void ){
    int choice ;
    cout<<"0.Exit :"<<endl;
    cout<<"1.Add Time :"<<endl;
    cout<<"2.Display All Time "<<endl;
    cout<<"3.Display only hrs of all time objects "<<endl;
    cin>>choice;
    return choice;
}

int main(){

    Time * arr =new Time [2];
    int choice ;
    while ((choice=menuList())!=0){
        switch(choice){
            case 1:{
            //  Time t1 (10,20,30);
            for(int i=0;i<2;i++){
                arr[i].setHrs(10);
                arr[i].setMins(10);
                arr[i].setSecs(10);
                
            }

            }
            case 2:{
                for (int i=0;i<2;i++){
                    arr[i].printTime();
                }
            }
            case 3:{
                for(int i=0;i<2;i++){
                    cout <<"hours :"<<arr[i].getHrs()<<endl;
                }
            }
        
        }
    }
    return 0;
}