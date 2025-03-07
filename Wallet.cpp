#include"Wallet.h"

Wallet::Wallet()
{





}


void Wallet::insertCurrency(std::string type, double amount)
{

 double balance;
 if(amount<0)
 {

        throw std::exception();

 }


  if(currencies.count(type)==0) // not here yet
{
        balance = 0;


}

else  
{

        balance= currencies[type];

}

        balance+=amount;
        currencies[type]=balance;


}



bool Wallet::removeCurrency(std::string type, double amount)
{


double balance;
 if(amount<0)
 {

        // throw std::exception();
         return false;

 }


  if(currencies.count(type)==0) // not here yet
{
       return false;


}

else  // is there -ddo we have enough
{       if(containsCurrency(type,amount)) // we have enough
      {
        currencies[type]-=amount;
        return true;


      }
      else  // they have it, but not enough.
      {
        return false;

      }

        

}

        balance+=amount;
        currencies[type]=balance;





}


bool Wallet::containsCurrency(std::string type, double amount)
{

    if(currencies.count(type)==0) \
    return false;

    else
         return currencies[type]>=amount;     

}



std::string Wallet::toString()
{

    std::string s;
        for(std::pair<std::string,double> pair:currencies)
        {
               std::string currency = pair.first;
               double amount=pair.second;
               s+= currency + " : " +std::to_string(amount) + "\n";


            
        }


        return s;


}




        bool Wallet::canFullfillOrder(OrderBookEntry order)
{
        /* eg: separate ETH/BTC  using tokenise function*/
        std::vector<std::string> currs = CSVReader::tokenise(order.product,'/');

        /*
               If the orderbook type is of ask
        
        */

                if(order.orderType==OrderBookType::ask)
        {

                double amount = order.amount;
                std::string currency = currs[0];
                std::cout<<"Wallet::canFullfillOrder "<< currency<< " : "<<amount<<std::endl;
                return containsCurrency(currency,amount);
        
        }



        /*
               If the orderbook type is of bid
        
        */

                if(order.orderType==OrderBookType::bid)
        {

                double amount = order.amount*order.price;
                std::string currency = currs[1];
                std::cout<<"Wallet::canFullfillOrder "<< currency<< " : "<<amount<<std::endl;
                return containsCurrency(currency,amount);
        
        }

        /*     else it has to be false  */

        return false;



}


//  std::ostream&  operator<<(std::ostream& os, Wallet& wallet)
//  {
//  os << wallet.toString();
//  return os;
//  }