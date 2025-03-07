#include <string>
#include <vector>
#include <iostream>
#include<fstream>


std::vector<std::string> tokenise(std::string csvLine, char separator)
{
    // string csvLine='thing','thing2','thing3' ## the string we are processing
    // string vector tokens ## stores the tokens
    // char separator = ',' ## the character that separates the tokens
    std::vector <std::string> tokens;
    std::string token;
    // init start, end ## the character that separates the tokens
    // int start, end ## used to delineate the position of the tokens
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


/* 
       test function for parsing!! csv!! 

*/


    int main(void)

{




    // std::vector<std::string> tokens;
    // std::string s="01:24.9,	ETH/BTC,	bid,	0.02187008,	0.21,";

    // tokens=tokenise(s,',');

    //     for(std::string& t:tokens)
    // {
    //     std::cout<<t<<std::endl;


    // }

    // return 0;


    std::ifstream csvFile{"20200317.csv"};
    std::string line;
    std::vector<std::string> tokens;
    
            if(csvFile.is_open())
        {

        // std::cout <<"File open"<< std::endl;
        // /* getline is used to read line from 
        //    the csv file
        // */
        // std::getline(csvFile,line);
        // std::cout<<"Read line from the file"<<std::endl<<line<<std::endl;

        // /* We can read multiple lines by 
        //    repeating the function
        // */
        // std::getline(csvFile,line);


        //parse the lines till the end of file or until getline() returns false
        while(std::getline(csvFile,line))
{       // std::cout <<"File open"<< std::endl;
        std::cout<<"Read line from the file"<<std::endl<<line<<std::endl;

                tokens=tokenise(line,',');
                //input checking
                if(tokens.size()!=5)
                {//skip to the next line
                    continue;
                }

                /* 
                   Adding exceptions here so that we 
                   can handle unexpected values in there.
                   try-catch 
                */

               try{

                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout<<price<<":"<<amount<<std::endl;

                  }


                catch(std::exception& e){

                    // std::cout <<"Bad float! " <<tokens[3]<<std::endl;
                    std::cout <<"Bad float! " <<tokens[4]<<std::endl;
                    //throw e; why not throw? Is this a design choice?
                    break;


                }

                // for(std::string& t: tokens)
                // {
                //         std::cout <<t<<std::endl;

                // }

}

        csvFile.close();
    }

    else{

        std::cout<<"Could not open the file"<<std::endl;

        }









}