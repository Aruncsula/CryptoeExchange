#pragma once
#include"OrderBookEntry.h"
#include"CsvReader.h"
#include<string>

class OrderBook
{

    public:
            /* 
                Constructor receiving a csv data file
                
            */
                    OrderBook(std::string filename);
         
            /* 
                Return vector of all known products in the dataset 
                
            */

           /*
                  OrderBook matching algorithm asks and bids
           */
            
            std::vector<OrderBookEntry> matchAskstoBids(std::string product, std::string timestamp);




            std::vector<std::string> getKnownProducts();
          
            
            /*return vector of Orders according to sent filters*/
            
            std::vector<OrderBookEntry>getOrders(OrderBookType type,
                                                  std::string product,
                                                  std::string timestamp);


            std::string getEarliestTime();

        /*
           Look through the input ime and find the next time.  
        */

            std::string getNextTime(std::string timestamp);
            void insertOrder(OrderBookEntry& order);

            static int getHighPrice(std::vector<OrderBookEntry>& orders);
            static double getLowPrice(std::vector<OrderBookEntry>& orders);
            static double getOpeningPrice(std::vector<OrderBookEntry>& orders);
            static double getClosingPrice(std::vector<OrderBookEntry>& orders);



    private:
                    std::vector<OrderBookEntry> orders;
      


};
