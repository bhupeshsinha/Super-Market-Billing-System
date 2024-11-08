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

    void setRate(int rate)            
    {
        this->rate=rate;
    }

        void setQuantity(int quantity)            
    {
        this->quantity=quantity;
    }

    string getItem()
    { 
        return this->item;
    }    
    int getRate()
    {
        return this->rate;
    }   
    int getQuantity()
    {
        return this->quantity;
    }   
};



    void addItem(Bill b)
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
                system("cls");

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

                ofstream out("E:/CPP(MB Academy)/Super-Market-Billing-System/Bill.txt", ios::app);  
                    if(!out)
                    {
                        cout<<"\t Error: File Can't Opened"<<endl;
                    }
                    else{
                        /*now we are storing/writing (ofstream:    writing(output) data in the file) data from data varibles of the class into the file*/
                        out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuantity()<<endl<<endl;
                        cout<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuantity()<<endl<<endl;
                    }

                    out.close();    //closed the file
                    cout<<"\tItem added successfully!!"<<endl;
                    Sleep(4000);    //function from "window.h", library

            }else if(choice == 2){
                system("cls");
                close=true;

                cout<<"\t Back to Main Menu!"<<endl;
                Sleep(4000);
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
            addItem(b);
        }else if(val == 2)
        {

        }else
        {

        }
    }

    return 0;
}