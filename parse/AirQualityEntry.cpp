#include"AirQualityEntry.h"

/*
  The implementation for the AirQualityEntry class 
  is done here.

*/



 AirQualityEntry::AirQualityEntry(  uint64_t _uid,
                                    uint64_t _indicator,
                                    std::string _name,
                                    std::string _meas,
                                    std::string _meas_info,
                                    std::string _geo_type_name,
                                    uint64_t _geo_join_id,
                                    std::string _geo_place_name,
                                    std::string _time_period,
                                    std::string _start_date,
                                    double _data_val)    


                            :uid(_uid),
                            indicator(_indicator),
                            name(_name),
                            meas(_meas),
                            meas_info(_meas_info),
                            geo_type_name(_geo_type_name),
                            geo_join_id(_geo_join_id),
                            geo_place_name(_geo_place_name),
                            time_period(_time_period),
                            start_date(_start_date),
                            data_val(_data_val)
{






}   