 
 #include"OrderBookEntry.h"



/*
 This Cpp file contains the implementation of the class.
 Here we have used the constructor initialisation list over here.

*/

 
 OrderBookEntry::OrderBookEntry( double _price,
                                double _amount,
                                std::string _timestamp,
                                std::string _product,
                                OrderBookType _orderType )

         :price(_price),
         amount(_amount),
         timestamp(_timestamp),
         product(_product),
         orderType(_orderType)


{





}


OrderBookType OrderBookEntry::stringtoOrderBookType(std::string s)
{

     if(s=="ask")
     {
        return OrderBookType::ask;

     }
      if(s=="bid")
     {
        return OrderBookType::bid;

     }

    return OrderBookType::unknown;




}