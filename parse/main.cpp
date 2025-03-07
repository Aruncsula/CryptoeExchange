#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"AirQualityEntry.h"


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

int main(void)
{

    uint64_t valid_lines=0;
    std::ifstream csvFile{"Air_Quality.csv"};
    std::string line;
    std::vector<std::string> tokens;
    std::vector<AirQualityEntry> copy;
    // AirQualityEntry entry;
    

    std::cout<<"Hello, World!!!"<<std::endl;


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
        // std::cout<<"Read line from the file"<<std::endl<<line<<std::endl;

                tokens=tokenise(line,',');
                //input checking
                valid_lines++;
                if(tokens.size()!=11)
                {//skip to the next line
                    continue;
                }
                

                /* 
                   Adding exceptions here so that we 
                   can handle unexpected values in there.
                   try-catch 
                */

               try{

                uint64_t price = std::stod(tokens[0]);
                uint64_t amount = std::stod(tokens[1]);
                std::string name= tokens[2];
                std::string meas= tokens[3];
                std::string meas_info= tokens[4];
                std::string geo_type_info= tokens[5];
                uint64_t geo_join_id= std::stoi(tokens[6]);
                std::string geo_place_name= tokens[7];
                std::string time_period = tokens[8];
                std::string start_date = tokens[9];
                double val=stod(tokens[10]);

                // std::cout<<price<<":"<<amount<<std::endl;
                AirQualityEntry entry{price,
                                      amount,
                                      name,
                                      meas,
                                      meas_info,
                                      geo_type_info,
                                      geo_join_id,
                                      geo_place_name,
                                      time_period,
                                      start_date,
                                      val
                                            };


                copy.push_back(entry);
                // std::cout<<copy[1].data_val<<":"<<copy[1].start_date<<std::endl;

}


                catch(std::exception& e){

                    // std::cout <<"Bad float! " <<tokens[3]<<std::endl;
                    std::cout <<"Bad float! " <<tokens[0]<<std::endl;
                    //throw e; why not throw? Is this a design choice?
                    break;


                }

                // for(std::string& t: tokens)
                // {
                //         std::cout <<t<<std::endl;

                // }

}
    std::cout<<copy[0].data_val<<":"<<copy[0].start_date<<std::endl;
    std::cout<<"The valid lines in the csv file is:"<<valid_lines<<std::endl;    

        csvFile.close();
    }

    else{

        std::cout<<"Could not open the file"<<std::endl;

        }











}