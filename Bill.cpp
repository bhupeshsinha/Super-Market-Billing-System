#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>

using namespace std;

class Bill
{
      
    private:
            string item;
            int rate, quantity;
    
    public:

            Bill(): item(""), rate(0), quantity(0){}

    void setItem(string item)            
    {
        this->item=item;
    }

    void setRate(string rate)            
    {
        this->rate=rate;
    }

        void setQuantity(string quantity)            
    {
        this->quantity=quantity;
    }

    string getItem()    return this->item;
    int getRate()   return this->rate;
    int getQuantity()   return this->quantity;
};

int main()
{
    Bill b;
    bool exit = false;      //variable that terminate the while loop

    while(!exit)
    {
        system("cls");          //this statement clear the previous output and display only the current output

        int val;

        cout<<"\t Welcome to Super Market Billing System"<<endl;
        cout<<"\t **************************************"<<endl;
        cout<<"\t 1. Add Item."<<endl;
        cout<<"\t 2. Print Bill."<<endl;
        cout<<"\t 3. Exit."<<endl;
        cout<<"\t\t Enter Choice: ";
        cin>>val;

    }

    return 0;
}