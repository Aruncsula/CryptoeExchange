 #include <iostream>
 #include <map>
 
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


                 
                 
                 
        




 
                int main ()
 {

                while(true)
        {
                  PrintMenu();
                  int userOption=getUserOption();
                  processUseroption(userOption);
                 
         }

 
 }