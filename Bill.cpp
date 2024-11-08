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



    addItem(Bill b)
    {
        bool close = false;
        while(!close)
        {
            int choice;
            cout<<"\t1. Add Item."<<endl;
            cout<<"\t2. Close."<<endl;
            cout<<"\t Enter Choice: ";
            cin>>choice;

            if(choice == 1)
            {

                string item;
                int rate, quantity;

                cout<<"\t Enter Item Name: ";
                cin>>item;
                b.setItem(item);

                cout<<"\t Enter Rate: ";
                cin>>rate;
                b.setRate(rate);

                cout<<"\t Enter Quantity: ";
                cin>>quantity;
                b.setQuantity(quantity);

            }else{

            }
        }
    }



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
        cout<<"\t\t 1. Add Item."<<endl;
        cout<<"\t\t 2. Print Bill."<<endl;
        cout<<"\t\t 3. Exit."<<endl;
        cout<<"\t\t Enter Choice: ";
        cin>>val;


        if(val == 1)
        {

        }else if(val == 2)
        {

        }else
        {

        }
    }

    return 0;
}