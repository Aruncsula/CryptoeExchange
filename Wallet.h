#include<string>
#include<map>
#include"OrderBookEntry.h"
#include<vector>
#include"CsvReader.h"
#include<iostream>


class Wallet
{
    /*  By default all the member functions and variables 
        are private.
    */
    public:
            Wallet();

            /*  Insert money to the wallet    */
            void insertCurrency(std::string type, double amount);

                /*  Remove money to the wallet    */
            // void removeCurrency(std::string type, double amount);
            /*checks if the wallet has this much money removed or not*/
            bool removeCurrency(std::string type, double amount);

            /*checks if the wallet has this much money or not*/
            bool containsCurrency(std::string type, double amount);
            /*checks if the wallet can cope with this ask or bid.*/

            /* generate a string representation of wallet */
            std::string toString();

            /*Checks if it can fullfill the  ask or bid order */
            bool canFullfillOrder(OrderBookEntry order);    


            //  friend std::ostream& operator<<(std::ostream& os, Wallet& wallet);


    private:
           /* We are mapping a string to a ouble*/
           std::map<std::string,double> currencies;



};