 #include <iostream>
 #include <map>
 #include<string>
 #include<vector>
 #include"OrderBookEntry.h"
 #include"MerkelMain.h"
#include"CsvReader.h"
 
/*
        The OrderBookEntry represents a row in the order book data set (i.e. a single order in the order book). It can be a bid or an ask order.

        The OrderBook class presents a high level interface on all the orders in the order book data set, including query functions to find out 
        which products are in the data set, and to retrieve a subset of the orders using filters.
        
        The MerkelMain class represents the application itself, and it deals with user input and menu printing. 
*/





  


/* 
    This file includes the menu for the Cryto exchange   

*/

                 
        




 
                int main ()
 {


    // MerkelMain app{};
    // // app.PrintMenu();
    // app.init();
    
    // OrderBookEntry entry;
    // CSVReader reader;
    // CSVReader::readCsv("20200317.csv");


    Wallet wallet;
    wallet.insertCurrency("BTC",1.5);
     wallet.insertCurrency("USDT",1000);
    std::cout<<"The wallet contains BTC "<<wallet.containsCurrency("BTC",10)<<std::endl;
    std::cout<<wallet.toString()<<std::endl;

    wallet.removeCurrency("USDT",900);
    std::cout<<wallet.toString()<<std::endl;
    std::cout << "Wallet should contain 1.5 BTC now" << std::endl;


    // std::cout << "Wallet should contain 1.5 BTC now" << std::endl;
    // // std::cout<< wallet << std::endl;
    // bool result = wallet.containsCurrency("BTC", 1.5);
    // std::cout << "Result should be true " << result << std::endl;
    // result = wallet.removeCurrency("BTC", 2.0);
    // std::cout << "Result should be false " << result << std::endl;
    // result = wallet.removeCurrency("BTC", 1.0);
    // std::cout << "Result should be true " << result << std::endl;




 }








//                 int i=0,a=10;
//                 double price;
//                 std::string toprint;
//                 std::vector<OrderBookEntry> orders;


//         //         while(true)
//         // {
//         //           PrintMenu();
//         //           int userOption=getUserOption();
//         //           processUseroption(userOption);
                 
//         //  }


//         /*
//                 One way of calling vectors of the object class.
                
//         */

//         // OrderBookEntry order1{1000,
//         //                       0.02,
//         //                       "5/7/24",
//         //                       "BTC",
//         //                       OrderBookType::bid
//         //                       };

//         // OrderBookEntry order2{4000,
//         //                       0.02,
//         //                       "5/7/24",
//         //                       "BTC",
//         //                       OrderBookType::bid
//         //                       };


//         // orders.push_back(order1);
//         // orders.push_back(order2);


//  /*
//                 Another way of calling vectors of the object class.
                
//         */


//         orders.push_back(  OrderBookEntry{   1000,
//                                                 0.02,
//                                                 "5/7/24",
//                                                 "BTC",
//                                                 OrderBookType::bid
//                                                         }         );

//         orders.push_back( OrderBookEntry{       4000,
//                                                 0.02,
//                                                 "5/7/24",
//                                                 "BTC",
//                                                 OrderBookType::bid
//                                                         }         );



//         // order1.amount=0.0012;
//         // order1.price=20000;
//         // order1.timestamp="5/7/24";
//         // order1.product="BTC"; 
//         // order1.orderType=OrderBookType::bid;


//         /*Loops Method 1: Iterator type:*/


//         //         for(OrderBookEntry order : orders)
//         // {
//         //         std::cout<<"The price is    "<<order.price<<std::endl;

//         // }

//         /*
//                         Loops Method 1: Iterator type:
        
//                         Drawbacks: copies orders to order and uses it
//                         (not Memory efficient)
//                         Better method would be to put an & before order, now it will not be making copies,
//                         It(order) will be pointing to the value @ orders and printing them. 
        
//         */

//                   for(OrderBookEntry& order : orders)
//         {
//                 std::cout<<"The price is    "<<order.price<<std::endl;

//         }


//         // /* 
//         //         Loops Method 2: normal for loop 
        
//         // */


//         //         for(unsigned int i=0; i<orders.size();++i)
//         // {
//         //         std::cout<<"The price is    "<<orders[i].price<<std::endl;

//         // }





//         // /* 
//         //         Loops Method 3: Object style for loop over vectors
        
//         // */


//         //         for(unsigned int i=0; i<orders.size();++i)
//         // {
//         //         std::cout<<"The price is    "<<orders.at(i).price<<std::endl;

//         // }

//        price= computeTotalPrice(orders);
     




//  }