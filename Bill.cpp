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

    return 0;
}