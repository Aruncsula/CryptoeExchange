#pragma once
#include<string>

/*
   Now this header file just have the specification and no further details 
   are shown here.The implementation will be available in the .cpp file for OrderBookEntry. 
*/


        enum class OrderBookType{bid,ask,unknown,sale};

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

                OrderBookEntry( double _price,
                                double _amount,
                                std::string _timestamp,
                                std::string _product,
                                OrderBookType _orderType );

                /* Constructor initialisation list is an efficient way and it is defined below */

               
        /* This func converts a string entry in to OrderBooktype */
        static OrderBookType stringtoOrderBookType(std::string s);


        static bool compareByTimestamp(OrderBookEntry&e1, OrderBookEntry&e2)
        {
              return e1.timestamp<e2.timestamp;



        }


        static bool compareByPriceAsc(OrderBookEntry&e1, OrderBookEntry&e2)
        {
              return e1.price<e2.price;



        }

           static bool compareByPriceDesc(OrderBookEntry&e1, OrderBookEntry&e2)
        {
              return e1.price<e2.price;



        }






                /*      End of constructor is here.
                                                        */

                    double price;
                    double amount;
                    std::string timestamp;
                    std::string product;
                    OrderBookType orderType;    

        };
