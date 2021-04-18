#include <bits/stdc++.h>
using namespace std;

class Customer{
    public:
        int id;
        Customer(int c_id){
            id = c_id;
            cout<<"Customer "<<id<<" arrives at the barbershop\n";
        }
        void enterShop(){
            cout<<"Customer "<<id<<" enters the barbershop\n";
        }

        void sitOnSofa(){
            cout<<"Customer "<<id<<" sits in the waiting room\n";
        }

        void sitInBarberChair(int barberID){
            cout<<"Customer "<<id<<" sits on barber chair "<<barberID<<" to get a haircut\n";
        }
        void waitforPayment(){
            // wait here
        }
        void pay(int barberID){
            cout<<"Customer "<<id<<" leaves barber chair "<<barberID<<" to pay\n";
        }
        void exitShop(){
            cout<<"Customer "<<id<<" exits the barbershop after paying for the service\n";
        }
};

class Barber{
    public:
        int id;
        Barber(int b_id){
            id = b_id;
            cerr<<"Barber "<<id<<" created\n";
        }
        void sleep(){
            cout<<"Barber "<<id<<" is sleeping, waiting for customer\n";
        }

        void cutHair(int customerID){
            cout<<"Barber "<<id<<" starts haircut of customer "<<customerID<<"\n";
            cout<<"Barber "<<id<<" finishes haircut of customer "<<customerID<<"\n";
        }

        void cleanChair(){
            cout<<"Barber "<<id<<" is cleaning.\n";
        }
        void acceptPayment(int customerID){
            cout<<"Barber "<<id<<" recieve payment from customer "<<customerID<<"\n";
        }
};

class Gatekeeper{
    public:
        int id;
        Gatekeeper(int g_id){
            id = g_id;
            cerr<<"Gatekeeper "<<id<<" created\n";
        }

        void giveToken(int customerID){
            cout<<"customer "<<customerID<<" takes token\n";
        }

        void takeToken(int customerID){
            cout<<"The customer "<<customerID<<" submits the token to the gatekeeper.\n";
            cout<<"The customer "<<customerID<<" leaves the shop.\n";
        }
};
