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

void printBill()
{
    system("cls");
    int count = 0;
    bool close = false;

    while(!close)
    {
        system("cls");
        int choice;

        cout<<"\t1. Add Bill."<<endl;
        cout<<"\t2. End Session."<<endl;
        cout<<"\tEnter Choice ";
        cin>>choice;

        if(choice == 1)
        {
            string item;
            int rate, quantity;

            cout<<"\tEnter Item: ";
            cin>>item;
            cout<<"\tEnter Quantity: ";
            cin>>quantity;

            ifstream in("E:/CPP(MB Academy)/Super-Market-Billing-System/Bill.txt");      //To READ data from the file:  file from which we will perform read oprtn inorder to generate the final bill
            ofstream out("E:/CPP(MB Academy)/Super-Market-Billing-System/Bill_Temp.txt");     //to WRITE data in the file:    

            string line;    //store the string data that is now stored in "in()" file
            bool found = false;

            while(getline(in, line))    //Read from :in and Write to :line
            {
                stringstream ss;
                ss<<line;

                string itemName;
                int itemRate, itemQuantity;
                char delimiter;

                ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuantity;

                if(item == itemName)
                {
                    found = true;
                    if(quantity <= itemQuantity)
                    {
                        int amount = itemRate * quantity;
                        cout<<"\tItem | Rate | Quantity | Amount"<<endl;
                        cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<itemQuantity<<"\t "<<amount<<endl;

                        int newQuantity = itemQuantity - quantity;
                        itemQuantity = newQuantity;

                        count+=amount;
                        out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuantity<<endl<<endl;
                    }
                    else{
                         cout<<"\tSorry!,"<<itemName<<" It's Out of Stock. We have only "<<itemQuantity<<" remaining"<<endl;
                    }

                }else{
                        out<<line<<; 
                }
            }
             
        if(!found)  
        {
            cout<<"\tOoops!, Item Not Available!!"<<endl;
        }

        out.close();
        in.close(); 

        remove("E:/CPP(MB Academy)/Super-Market-Billing-System/Bill.txt");
        rename("E:/CPP(MB Academy)/Super-Market-Billing-System/Bill_Temp.txt", "E:/CPP(MB Academy)/Super-Market-Billing-System/Bill.txt")

        }else if( choice == 2)
        {
            close=true;
            cout<<"\tWait, Bill is generating"<<endl;
            
        }
        Sleep(3000);
    }

    system("cls");
    cout<<endl<<endl;
    cout<<"\t Total Bill is:\t"<<count<<endl<<endl;
    cout<<"\t Thanks for Shopping!, Please visit Again!!"<<endl;
    Sleep(5000);
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
            system("cls");
            addItem(b);
            Sleep(4000);
        }
        else if(val == 2)
        {
            printBill();
        }
        else
        {
                system("cls");
                exit=true;
                cout<<"Thank You, Have a good day"<<endl;
        }
    }

    return 0;
}