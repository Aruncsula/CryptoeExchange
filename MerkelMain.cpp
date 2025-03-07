  #include"MerkelMain.h"
  #include<iostream>
  #include<string>
  #include <map>
  #include"OrderBookEntry.h"
  #include<vector>
  #include"CsvReader.h"
  #include"OrderBook.h"
  #include<limits>
  
//    void MerkelMain::loadOrderBook()
//  {
//                 // std::vector<OrderBookEntry> orders;


    


//         /*
//                 One way of calling vectors of the object class.
                
//         */

//                             // OrderBookEntry order1{1000,
//                             //                     0.02,
//                             //                     "5/7/24",
//                             //                     "BTC",
//                             //                     OrderBookType::bid
//                             //                     };

//                             // OrderBookEntry order2{4000,
//                             //                     0.02,
//                             //                     "5/7/24",
//                             //                     "BTC",
//                             //                     OrderBookType::bid
//                             //                     };


//                             // orders.push_back(order1);
//                             // orders.push_back(order2);

// /* We can use the private  vector of objects order from the MerkelMain Class instances*/
//                   orders= CSVReader::readCsv("20200317.csv");

// }



  MerkelMain::MerkelMain()
  {
    
    
  
  }

 void MerkelMain::init()

 {

    // loadOrderBook();
    currentTime=OrderBook.getEarliestTime();
    int input;
    wallet.insertCurrency("BTC",5);
    
    while(true)
    {


        /*
          We can call these functions ddirectly because we are inside 
          the MerkelMain class now.

        */

        PrintMenu();
        input=getUserOption();
        processUseroption(input);

    }


 }



           

  
  
  
  
                void MerkelMain::printHelp(void)
  {

              // std::cout<<"You have selected the help option"<<std::endl;
                                    std::cout << "Help- choose options from the menu" << std::endl;
                                    std::cout << "and follow the on screen instructions." << std::endl;


  }

                 void MerkelMain::PrintMarketstats()
         {

            for(std::string const& p: OrderBook.getKnownProducts())
            {

              std::cout<<"Product: "<<p<<std::endl;
              std::vector<OrderBookEntry> ask_entries=OrderBook.getOrders(OrderBookType::ask,
                                                                   p,currentTime);
              std::vector<OrderBookEntry> bid_entries=OrderBook.getOrders(OrderBookType::bid,
                                                                   p,currentTime);
              std::cout<<"Asks seen:"<<ask_entries.size()<<std::endl;
              std::cout<<"Maximum Asks :"<<OrderBook::getHighPrice(ask_entries)<<std::endl;
              std::cout<<"Minimum Asks :"<<OrderBook::getLowPrice(ask_entries)<<std::endl;
              std::cout<<"Opening Price :"<<OrderBook::getOpeningPrice(ask_entries)<<std::endl;
              std::cout<<"Closing Price :"<<OrderBook::getClosingPrice(ask_entries)<<std::endl;

              std::cout<<"Bids seen:"<<bid_entries.size()<<std::endl;
              std::cout<<"Maximum Bids :"<<OrderBook::getHighPrice(bid_entries)<<std::endl;
              std::cout<<"Minimum Bids :"<<OrderBook::getLowPrice(bid_entries)<<std::endl;


            }





        //   /* We have access to private vector class orders as we 
        //      are inside the MErkelMain class ,so we can access it. 
             
        //   */
        //      std::cout<<"Market looks good!! "<<std::endl;   
        //      std::cout<<"The OrderBook contains ::"<<orders.size()<<std::endl;

        //      unsigned int asks=0;
        //      unsigned int bids=0;
        //       for(OrderBookEntry& e:orders)
        //      {
        //           if(e.orderType==OrderBookType::ask)
        //           {
        //             asks++;
        //           } 

        //           if(e.orderType==OrderBookType::bid)
        //           {
        //            bids++;   
        //           }

                  

        //      }
        //     std::cout<<"OrderBook asks:"<<asks<<std::endl<<" Bids "<<bids<<std::endl;
         }


                void MerkelMain::PrintEnteroffer()
        {

             std::cout<<"Make an offer: "<<std::endl;

        }



        /*
        
             EnterAsk function
        
        */


                void MerkelMain::EnterAsk()
        {

             std::cout<<"Make an ask: enter the amount: product, price, amount, eg ETH/BTC,200,0.5 "<<std::endl;
             std::string input;

            //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

             std::getline(std::cin,input);

             std::vector<std::string> tokens =CSVReader::tokenise(input,',');
              if(tokens.size()!=3)
             {

                  std::cout<<"Bad input: "<<input <<std::endl;


             }
             else{

              try{
                OrderBookEntry obe =CSVReader::stringstoOBE(
                                           tokens[1],
                                           tokens[2],
                                           currentTime,
                                           tokens[0],
                                           OrderBookType::ask   
                                          );


                if(wallet.canFullfillOrder(obe)) 
                {
                    std::cout<<"Wallet looks good. " <<std::endl;
                    OrderBook.insertOrder(obe);


                }           

                else{

                  std::cout<<"wallet has insufficient funds"<<std::endl;

                }              

                // OrderBook.insertOrder(obe);
                }

                catch (const std::exception&e)
                {

                  std::cout<<"MerkelMain::EnterAsk ( Bad input)" <<std::endl;

                }

             }
       
          


             std::cout<<"You typed: "<<input <<std::endl;


        }

/*

            enterBid


*/

void MerkelMain::EnterBid()
        {

            //  std::cout<<"Make a Bid: enter the amount: product, price, amount, eg ETH/BTC,200,0.5 "<<std::endl;
            //  std::string input;

            // //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            //  std::getline(std::cin,input);

            //  std::vector<std::string> tokens =CSVReader::tokenise(input,',');
            //   if(tokens.size()!=3)
            //  {

            //       std::cout<<"Bad input: "<<input <<std::endl;


            //  }
            //  else{

            //   try{
            //     OrderBookEntry obe =CSVReader::stringstoOBE(
            //                                tokens[1],
            //                                tokens[2],
            //                                currentTime,
            //                                tokens[0],
            //                                OrderBookType::bid   
            //                               );

            //     OrderBook.insertOrder(obe);
            //     }

            //     catch (const std::exception&e)
            //     {

            //       std::cout<<"MerkelMain::EnterBid ( Bad input)" <<std::endl;

            //     }

            //  }
       
          


            //  std::cout<<"You typed: "<<input <<std::endl;



             std::cout<<"Make a bid: enter the amount: product, price, amount, eg ETH/BTC,200,0.5 "<<std::endl;
             std::string input;

            //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

             std::getline(std::cin,input);

             std::vector<std::string> tokens =CSVReader::tokenise(input,',');
              if(tokens.size()!=3)
             {

                  std::cout<<"MerkelMain::EnterBid Bad input: "<<input <<std::endl;


             }
             else{

              try{
                OrderBookEntry obe =CSVReader::stringstoOBE(
                                           tokens[1],
                                           tokens[2],
                                           currentTime,
                                           tokens[0],
                                           OrderBookType::bid   
                                          );


                if(wallet.canFullfillOrder(obe)) 
                {
                    std::cout<<"Wallet looks good. " <<std::endl;
                    OrderBook.insertOrder(obe);


                }           

                else{

                  std::cout<<"wallet has insufficient funds"<<std::endl;

                }              

                // OrderBook.insertOrder(obe);
                }

                catch (const std::exception&e)
                {

                  std::cout<<"MerkelMain::EnterBid Bad input" <<std::endl;

                }

             }
       
          


             std::cout<<"You typed: "<<input <<std::endl;




        }


                void MerkelMain::PrintWallet()
        {

            //  std::cout<<"Your wallet is empty!! "<<std::endl;
             std::cout<< wallet.toString()<<std::endl;

        }





                void MerkelMain::gotoNextTimeframe()
    {

             std::cout<<"Going to next time frame."<<std::endl;
             for(std::string& p:OrderBook.getKnownProducts())
             {
                std::cout << "matching " << p << std::endl;
                std::vector<OrderBookEntry> sales =  OrderBook.matchAskstoBids(p,currentTime); 
                std::cout<<"Sales: "<<sales.size()<<std::endl;

                      for(OrderBookEntry& sale:sales)
                      {

                        std::cout<<"Sales price: "<<sale.price<<"Amount"<<sale.amount<<std::endl;

                      }

             currentTime=OrderBook.getNextTime(currentTime);

              }

    }



/*
                void PrintMenu(void):
                This function prints the 6 options to the console.
                 
*/


                void MerkelMain::PrintMenu(void)
        {
                                std::cout << "1: Print help" << std::endl;
                                std::cout << "2: Print exchange stats"<< std::endl;
                                std::cout << "3: Make an offer" << std::endl;
                                std::cout << "4: Place a bid"<< std::endl;
                                std::cout << "5: Print a wallet"<< std::endl;
                                std::cout << "6: Continue" <<std::endl;
                                std::cout << "Current Time is"<<currentTime <<std::endl;




        }


/*
                int getUserOption(void)
                This function gets the useroption from the see in stream and 
                prints out the selected  choice to user.
                 
*/


                int MerkelMain::getUserOption(void)
        {

                                std::string line;       
                                int userOption=0;
                                std::cout << "Type in 1-6" << std::endl;
                                std::getline(std::cin,line);

                          try{

                               userOption=std::stoi(line);
                              }
                          catch(const std::exception& e)
                            {


                            }

                                
                                std::cout << "You chose:"<<userOption << std::endl;

                                return userOption;
        }

// /*
//                 void processUseroption(int userOption)
//                 This function processes the useroption  and calls the 
//                 selected  choice to user.A map is used along with function pointers to make the function lean.
                 
// */

//          /*
         
//             we have to investigate the 
         
//          */



                 void MerkelMain::processUseroption(int userOption)


        {


                //  std::map<int , void(*)()>menu;
                //  menu[1]=MerkelMain::printHelp;
                //  menu[2]=MerkelMain::PrintMarketstats;
                //  menu[3]=MerkelMain::PrintEnteroffer;
                //  menu[4]=MerkelMain::PrintEnterbid;
                //  menu[5]=MerkelMain::PrintWallet;
                //  menu[6]=MerkelMain::gotoNextTimeframe;

                //  menu[userOption]();

                //    std::map<int , void(*)()>menu;

                  if(userOption==1)
                  { 
                    printHelp();
                  }

                    if(userOption==2)
                  { 
                    PrintMarketstats();
                  }

                    if(userOption==3)
                  { 
                    EnterAsk();
                  }

                    if(userOption==4)
                  { 
                    
                    EnterBid();
                  }

                    if(userOption==5)
                  { 
                    PrintWallet();
                  }

                    if(userOption==6)
                  { 
                    gotoNextTimeframe();
                  }
                //  menu[2]=MerkelMain::PrintMarketstats;
                //  menu[3]=MerkelMain::PrintEnteroffer;
                //  menu[4]=MerkelMain::PrintEnterbid;
                //  menu[5]=MerkelMain::PrintWallet;
                //  menu[6]=MerkelMain::gotoNextTimeframe;

                //  menu[userOption]();


                  


    
    
        }