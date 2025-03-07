#include"CsvReader.h"
#include<iostream>
#include<fstream>
#include<string>

    CSVReader::CSVReader()
{


}



    std::vector<OrderBookEntry> CSVReader::readCsv (std::string csvFilename)

{
       std::vector<OrderBookEntry> entries;

       std::ifstream csvFile{csvFilename};
       
       std::string line;

             if(csvFile.is_open())
        {
                while(std::getline(csvFile, line))
            {
                 
                 try{
                    OrderBookEntry obe= stringstoOBE(tokenise(line,','));
                    entries.push_back(obe);
                    
                }catch(const std::exception& e)
                {
                        // throw e;
                        std::cout<<"Bad data"<<std::endl;

                }
            
            
            }

        }   

        std::cout<<"CsvReader::readcsv"<<entries.size()<<"entries"<<std::endl;

       return entries;

}









 
                std::vector<std::string>  CSVReader::tokenise(std::string csvLine, char separator)
  {
            std::vector <std::string> tokens;
            std::string token;

            signed int start, end;
            start = csvLine.find_first_not_of(separator,0);

                                        /*          PseudoCode:    
                                                        // do
                                                    //    end= next 'separator' after start
                                                    //    if start == csvLine.length or start == end ### nothing more to find
                                                    //       break
                                                    //    if end>=0 ## we found the separator
                                                    //       token = csvLine.substr(start, end - start)## start, substring length
                                                    //    else 
                                                    //         the final case where the separator is not found
                                                    //         else token=csvLine.substr(start,csvLine.length() - start);
                                                    //    save the token 
                                                    //    start=end + 1; ## Move past this token!
                                                    // while end is> 0 or the separator is still there.
                                                
                                        */

    do{
                        end=csvLine.find_first_of(separator,start);
                        if(start==csvLine.length() || start==end) break;


                        if(end>=0) token=csvLine.substr(start, end-start);

                        else token=csvLine.substr(start,csvLine.length() - start);

                        tokens.push_back(token);
                        start=end + 1;

    }while(end!=std::string::npos); 


    return tokens;


}


 OrderBookEntry  CSVReader::stringstoOBE(std::vector<std::string> tokens)
{
    double price ,amount;

/*

        Design: 1.First exception when the token size is bad.

                2. 2nd exception, when the string to double is failed.
                
                3.Create an instance of the Class


*/



    if(tokens.size()!=5)
                {//skip to the next line
                    // continue;//no longer in a loop
                    std::cout<<"Bad line!!!"<<std::endl;

                    throw std::exception{};
                }

                /* 
                   Adding exceptions here so that we 
                   can handle unexpected values in there.
                   try-catch 
                */

               try{

                    double price = std::stod(tokens[3]);
                    
                    double amount = std::stod(tokens[4]);
                    // std::cout <<"Bad float! " <<amount<<std::endl;
             

                  }


                catch(const std::exception& e){

                    std::cout <<"Bad float! " <<tokens[3]<<std::endl;
                    std::cout <<"Bad float! " <<tokens[4]<<std::endl;
                    //throw e; why not throw? Is this a design choice?
                    // break;
                    throw; 

                }





    OrderBookEntry obe{price,
                       amount,
                       tokens[0],
                       tokens[1],
                       OrderBookEntry::stringtoOrderBookType(tokens[2])};


    return obe;



 }



  OrderBookEntry CSVReader::stringstoOBE(
                                               std::string priceString,
                                               std::string amountString,
                                               std::string timestamp,
                                               std::string product,
                                               OrderBookType OrderType  )
{

        double price, amount;


           try{

                    double price = std::stod(priceString);
                    double amount = std::stod(amountString);
             

                  }


                catch(const std::exception& e){

                     std::cout <<"CSVReader::stringstoOBE Bad float! " <<priceString<<std::endl;
                     std::cout <<"CSVReader::stringstoOBE Bad float! " <<amountString<<std::endl;
                    //throw e; why not throw? Is this a design choice?
                    // break;
                    throw; 

                }

    OrderBookEntry obe{price,
                       amount,
                       timestamp,
                       product,
                       OrderType};


    return obe;





}