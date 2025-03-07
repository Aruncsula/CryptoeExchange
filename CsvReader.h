#pragma once

#include"OrderBookEntry.h"
#include<vector>

class CSVReader
{
   public:
            CSVReader();
            // stateless function 'static'
            static std::vector<OrderBookEntry> readCsv (std::string csvFile);
            //  static std::vector<OrderBookEntry> readCsv (std::string csvFile);
            static std::vector<std::string> tokenise(std::string csvLine, char separator);


          /*
             In C++, we are allowed to do function overloading
          
          */

            static OrderBookEntry stringstoOBE(
                                               std::string price,
                                               std::string amount,
                                               std::string timestamp,
                                               std::string product,
                                               OrderBookType OrderBookType  );


   private:

            // tokenise: converts csv line in to a vector of strings 
            //tokenise converts vector of strings in to OrderBookEntry objects
            
            /*
            
            Static functions in classes do not have access to class data members. Non-static functions have access to class data members. 
            Static functions can be called without instantiating the class into an object. Non-static functions require an object, and you call them on that object.
            
            */
            static OrderBookEntry stringstoOBE(std::vector<std::string> strings);

};


