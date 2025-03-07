
#pragma once

#include<vector>
#include"OrderBookEntry.h"
#include"OrderBook.h"
#include"CsvReader.h"
#include"Wallet.h"



class MerkelMain
{
        public:
                        MerkelMain();
                        /*init: Call this to start the sim*/
                        void init();

        private:   
                        // void loadOrderBook();
                        void printHelp(void);
                        void PrintMarketstats(void);
                        void PrintEnteroffer(void);
                        void EnterAsk(void);
                        
                        void EnterBid(void);
                        void PrintWallet(void);
                        void gotoNextTimeframe(void);
                        void PrintMenu(void);
                        int getUserOption(void);
                        void processUseroption(int userOption);

                        std::string currentTime;

                        OrderBook OrderBook{"20200317.csv"};


                        Wallet wallet;

                        // std::vector<OrderBookEntry> orders;


    





};