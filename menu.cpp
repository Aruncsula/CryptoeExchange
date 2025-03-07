 #include <iostream>
 #include <map>
 #include<string>
 #include<vector>


 

        enum class OrderBookType{bid,ask};

        class OrderBookEntry
        {
                public:


            /*  Beginning of constructor:
                                        What happens if we do not put the '_' constructor sign before the parameters?
                                        We would then have conflict as we have defined them inside the class also, so that can
                                        result in two declarations?
                                        So the best way is to define the constructor parameters under the Class(_param1,_param2,..) 
                                        and then define it: { param1=_param1}
                                        
                                        */
                /*Here we can do so , because it is inside the class OrderBookEntry, if it is outside, we have to specify it becasue
                 we're not inside the class wrapper.      
                 */                       
                OrderBookEntry( double _price,
                                double _amount,
                                std::string _timestamp,
                                std::string _product,
                                OrderBookType _orderType )

                /* Constructor initialisation list is an efficient way and it is defined below */

                :price(_price),
                 amount(_amount),
                 timestamp(_timestamp),
                 product(_product),
                 orderType(_orderType)
                {
                   /* The better way to define it would be above. 

                       We wont need this alternative below, if we are declaring the parameters
                       like above. 
                   
                   */
                         
                        // price=_price;
                        // amount=_amount;
                        // timestamp=_timestamp;
                        // product=_product;
                        // orderType=_orderType;


                }

                /*      End of constructor is here.
                                                        */

                    double price;
                    double amount;
                    std::string timestamp;
                    std::string product;
                    OrderBookType orderType;    

        };



  


/* 
    This file includes the menu for the Cryto exchange   

*/

                void printHelp(void)
  {

              // std::cout<<"You have selected the help option"<<std::endl;
                                    std::cout << "Help- choose options from the menu" << std::endl;
                                    std::cout << "and follow the on screen instructions." << std::endl;


  }

                void PrintMarketstats()
        {
             std::cout<<"Market looks good!! "<<std::endl;   
             std::cout<<"These are the current exchange stats for the $$coin! "<<std::endl;

        }


                void PrintEnteroffer()
        {

             std::cout<<"Make an offer: "<<std::endl;

        }


                void PrintEnterbid()
        {

             std::cout<<"Enter the bid: enter the amount "<<std::endl;

        }



                void PrintWallet()
        {

             std::cout<<"Your wallet is empty!! "<<std::endl;

        }


                void gotoNextTimeframe()
        {

             std::cout<<"Going to next time frame."<<std::endl;

        }





/*
                void PrintMenu(void):
                This function prints the 6 options to the console.
                 
*/


                void PrintMenu(void)
        {
                                std::cout << "1: Print help" << std::endl;
                                std::cout << "2: Print exchange stats"<< std::endl;
                                std::cout << "3: Place an ask" << std::endl;
                                std::cout << "4: Place a bid"<< std::endl;
                                std::cout << "5: Print a wallet"<< std::endl;
                                std::cout << "6: Continue" <<std::endl;




        }


/*
                int getUserOption(void)
                This function gets the useroption from the see in stream and 
                prints out the selected  choice to user.
                 
*/


                int getUserOption(void)
        {
                                int userOption;
                                std::cout << "Type in 1-6" << std::endl;
                                std::cin >> userOption;
                                std::cout << "You chose:"<<userOption << std::endl;

                                return userOption;
        }

/*
                void processUseroption(int userOption)
                This function processes the useroption  and calls the 
                selected  choice to user.A map is used along with function pointers to make the function lean.
                 
*/

                 void processUseroption(int userOption)


        {


                 std::map<int , void(*)()>menu;
                 menu[1]=printHelp;
                 menu[2]=PrintMarketstats;
                 menu[3]=PrintEnteroffer;
                 menu[4]=PrintEnterbid;
                 menu[5]=PrintWallet;
                 menu[6]=gotoNextTimeframe;

                 menu[userOption]();

                  


    
    
        }


      double computeTotalPrice(std::vector<OrderBookEntry>& entries)
      {
                double amount=0;

                for(OrderBookEntry& order: entries)
                {
                        amount+=order.price;

                }

                std::cout<<"The total price is  "<<amount<<std::endl;

                return amount;

      }           
                 
                 
        




 
                int main ()
 {

                int i=0,a=10;
                double price;
                std::string toprint;
                std::vector<OrderBookEntry> orders;


        //         while(true)
        // {
        //           PrintMenu();
        //           int userOption=getUserOption();
        //           processUseroption(userOption);
                 
        //  }


        /*
                One way of calling vectors of the object class.
                
        */

        // OrderBookEntry order1{1000,
        //                       0.02,
        //                       "5/7/24",
        //                       "BTC",
        //                       OrderBookType::bid
        //                       };

        // OrderBookEntry order2{4000,
        //                       0.02,
        //                       "5/7/24",
        //                       "BTC",
        //                       OrderBookType::bid
        //                       };


        // orders.push_back(order1);
        // orders.push_back(order2);


 /*
                Another way of calling vectors of the object class.
                
        */


        orders.push_back(  OrderBookEntry{   1000,
                                                0.02,
                                                "5/7/24",
                                                "BTC",
                                                OrderBookType::bid
                                                        }         );

        orders.push_back( OrderBookEntry{       4000,
                                                0.02,
                                                "5/7/24",
                                                "BTC",
                                                OrderBookType::bid
                                                        }         );



        // order1.amount=0.0012;
        // order1.price=20000;
        // order1.timestamp="5/7/24";
        // order1.product="BTC"; 
        // order1.orderType=OrderBookType::bid;


        /*Loops Method 1: Iterator type:*/


        //         for(OrderBookEntry order : orders)
        // {
        //         std::cout<<"The price is    "<<order.price<<std::endl;

        // }

        /*
                        Loops Method 1: Iterator type:
        
                        Drawbacks: copies orders to order and uses it
                        (not Memory efficient)
                        Better method would be to put an & before order, now it will not be making copies,
                        It(order) will be pointing to the value @ orders and printing them. 
        
        */

                  for(OrderBookEntry& order : orders)
        {
                std::cout<<"The price is    "<<order.price<<std::endl;

        }


        // /* 
        //         Loops Method 2: normal for loop 
        
        // */


        //         for(unsigned int i=0; i<orders.size();++i)
        // {
        //         std::cout<<"The price is    "<<orders[i].price<<std::endl;

        // }





        // /* 
        //         Loops Method 3: Object style for loop over vectors
        
        // */


        //         for(unsigned int i=0; i<orders.size();++i)
        // {
        //         std::cout<<"The price is    "<<orders.at(i).price<<std::endl;

        // }

       price= computeTotalPrice(orders);
     




 }