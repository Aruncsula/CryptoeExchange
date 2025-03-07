#pragma once


/*
  The specification for the AirQualityEntry class is 
  defined here.

*/
#include<string>

class AirQualityEntry
{
    public:





      AirQualityEntry(  uint64_t _uid,
                        uint64_t _indicator,
                        std::string _name,
                        std::string _meas,
                        std::string _meas_info,
                        std::string _geo_type_name,
                        uint64_t _geo_join_id,
                        std::string _geo_place_name,
                        std::string _time_period,
                        std::string _start_date,
                        double _data_val);    


                        uint64_t uid;
                        uint64_t indicator;
                        std::string name;
                        std::string meas;
                        std::string meas_info;
                        std::string geo_type_name;
                        uint64_t    geo_join_id;
                        std::string geo_place_name;
                        std::string time_period;
                        std::string start_date;
                        double data_val;    




};