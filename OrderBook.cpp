#include"OrderBook.h"
#include"OrderBookEntry.h"
#include<string>
#include"CsvReader.h"
#include<iostream>
#include<map>
#include<algorithm>



         /* 
                Constructor receiving a csv data file
                
            */
                    OrderBook::OrderBook(std::string filename)
            {

                /*
                Conceptual: How can i use private order vector variable from the OrderBook class?
                Private variables/methods are sharable across the class!!
                
                */
                  orders=CSVReader::readCsv(filename);  









            }
            
            
            /* 
                Return vector of all known products in the dataset 
                
            */
            
            std::vector<std::string> OrderBook::getKnownProducts()
            {

                  std::vector<std::string> products;
                  /*
                    create a map and map the product string to bool
                  */
                  std::map<std::string,bool> prodMap;

                /*
                 Look through all the vectors and map all the product types 
                
                */  
                
                for(OrderBookEntry& e:orders)
                {                             
                    prodMap[e.product]=true;

                }

            /*
               Now flatten the map to a vector of strings
               and return the key values of the map data structure. 
            */
             
                for(auto const& e:prodMap)
            {

                products.push_back(e.first);

            } 


                  
                  return products;  

           
            
}
            
            
            
            /*return vector of Orders according to sent filters*/
            
            std::vector<OrderBookEntry>OrderBook::getOrders(OrderBookType type,
                                                  std::string product,
                                                  std::string timestamp          
                    )
            {


                std::vector<OrderBookEntry> orders_sub;   

            for(OrderBookEntry& e:orders)
            {
                if(e.orderType==type &&
                   e.product==product &&
                   e.timestamp==timestamp)
            {

                orders_sub.push_back(e); 


            }

            }


                return orders_sub;


            }


            int OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
    {

            double max=orders[0].price;
            for(OrderBookEntry& e:orders)
        {
             if(e.price>max)max=e.price;
         
        }

        // std::cout<<"high price"<<max<<std::endl;    

            return max;    

    }



       double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
    {

            double min=orders[0].price;
            for(OrderBookEntry& e:orders)
        {
             if(e.price<min)min=e.price;
         
        }
        return min;    

    }
/*
            This function looks through the array and  returns the price of the first 
            or opening order entry.


 */



         double OrderBook::getOpeningPrice(std::vector<OrderBookEntry>& orders)
     {

            double opening_price=orders[0].price;

            return opening_price;




     }
      
     /*
          This function looks through the array and  returns the price of the final or
          closing  order entry.
     
     
     
     */ 



      
             double OrderBook::getClosingPrice(std::vector<OrderBookEntry>& orders)
     {
            OrderBookEntry last_item=orders.back();

            double closing_price=last_item.price;

            return closing_price;





     }        


 std::string OrderBook::getEarliestTime()
 /* Can this function be a static function?
 No, because it accesses one of the object's data members and static functions cannot access object state, 
 unless you pass the object in as a parameter.
 
 */
 {

    return orders[0].timestamp;


 }

/*
    Go through the orderbook entries and find the next time stamp, that is greater than the input argument.
    If could not find it, it will roll over to the initial one



*/



 std::string OrderBook::getNextTime(std::string timestamp)
 {
        std::string next_timestamp="";

        for(OrderBookEntry& e:orders)
    {
            if(e.timestamp>timestamp)
        {
            next_timestamp=e.timestamp;
            break;

        }
        


    }
     /* What if it is the end?*/
        if(next_timestamp=="")
     {

        next_timestamp=orders[0].timestamp;

     }


    return next_timestamp;


 }

 /*
 
  The sorting function ,that returns a bool True ,if e1 time stamp is less than e2 time stamp
  or else a False bool.
 
 */



 void OrderBook::insertOrder(OrderBookEntry& order)
 {
    orders.push_back(order);
    std::sort(orders.begin(),orders.end(),OrderBookEntry::compareByTimestamp);
    
 }



/*
 Here is the pseudocode algorithm.
// asks = orderbook.asks in this timeframe
// bids = orderbook.bids in this timeframe
// sales = []
// sort asks lowest first
// sort bids highest first
// for ask in asks:
// for bid in bids:
// if bid.price >= ask.price # we have a match
// sale = new orderbookentry()
// sale.price = ask.price
// if bid.amount == ask.amount: # bid completely clears ask
// sale.amount = ask.amount
// sales.append(sale)
// bid.amount = 0 # make sure the bid is not processed again
// # can do no more with this ask
// # go onto the next ask
// break
// if bid.amount > ask.amount: # ask is completely gone slice the bid
// sale.amount = ask.amount
// sales.append(sale)
// # we adjust the bid in place
// # so it can be used to process the next ask
// bid.amount = bid.amount - ask.amount
// # ask is completely gone, so go to next ask
// break
// if bid.amount < ask.amount # bid is completely gone, slice the ask
// sale.amount = bid.amount
// sales.append(sale)
// # update the ask
// # and allow further bids to process the remaining amount
// ask.amount = ask.amount - bid.amount
// bid.amount = 0 # make sure the bid is not processed again
2
// # some ask remains so go to the next bid
// continue
// return sales  */


    std::vector<OrderBookEntry> OrderBook::matchAskstoBids(std::string product, std::string timestamp)
{   // asks = orderbook.asks in this timeframe
    // bids = orderbook.bids in this timeframe
    std::vector<OrderBookEntry> asks =getOrders(OrderBookType::ask, 
                                                            product,
                                                            timestamp);

    std::vector<OrderBookEntry> bids =getOrders(OrderBookType::bid, 
                                                            product,
                                                            timestamp);
    std::vector<OrderBookEntry> sales;
    std::sort(asks.begin(),asks.end(),OrderBookEntry::compareByPriceAsc);
    std::sort(bids.begin(),asks.end(),OrderBookEntry::compareByPriceDesc);

    for(OrderBookEntry& ask:asks)
    {
        for(OrderBookEntry& bid:bids)
        {

                    if(bid.price>=ask.price)
                {

                    OrderBookEntry sale{ask.price,0,timestamp,
                                                              product,OrderBookType::sale  };

                    if(bid.amount==ask.amount)
                    {
                       sale.amount=ask.amount;

                       sales.push_back(sale);

                       bid.amount=0;


                       break; 

                    }

                     if(bid.amount>ask.amount)
                    {
                        sale.amount=ask.amount;
                        sales.push_back(sale);
                        bid.amount=bid.amount-ask.amount;
                        break;
                   }
                    
                     if(bid.amount<ask.amount)
                    {                        
                        sale.amount=bid.amount;
                        sales.push_back(sale);
                        ask.amount=ask.amount-bid.amount;
                        bid.amount=0;
                        continue;    
                        
                    }
                }
            }
        }
    return sales;
}
