// Generated by gencpp from file capra_ai/AddGoal.msg
// DO NOT EDIT!


#ifndef CAPRA_AI_MESSAGE_ADDGOAL_H
#define CAPRA_AI_MESSAGE_ADDGOAL_H

#include <ros/service_traits.h>


#include <capra_ai/AddGoalRequest.h>
#include <capra_ai/AddGoalResponse.h>


namespace capra_ai
{

struct AddGoal
{

typedef AddGoalRequest Request;
typedef AddGoalResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct AddGoal
} // namespace capra_ai


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::capra_ai::AddGoal > {
  static const char* value()
  {
    return "0b3960086158a5efbef97244ca7ac745";
  }

  static const char* value(const ::capra_ai::AddGoal&) { return value(); }
};

template<>
struct DataType< ::capra_ai::AddGoal > {
  static const char* value()
  {
    return "capra_ai/AddGoal";
  }

  static const char* value(const ::capra_ai::AddGoal&) { return value(); }
};


// service_traits::MD5Sum< ::capra_ai::AddGoalRequest> should match 
// service_traits::MD5Sum< ::capra_ai::AddGoal > 
template<>
struct MD5Sum< ::capra_ai::AddGoalRequest>
{
  static const char* value()
  {
    return MD5Sum< ::capra_ai::AddGoal >::value();
  }
  static const char* value(const ::capra_ai::AddGoalRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::capra_ai::AddGoalRequest> should match 
// service_traits::DataType< ::capra_ai::AddGoal > 
template<>
struct DataType< ::capra_ai::AddGoalRequest>
{
  static const char* value()
  {
    return DataType< ::capra_ai::AddGoal >::value();
  }
  static const char* value(const ::capra_ai::AddGoalRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::capra_ai::AddGoalResponse> should match 
// service_traits::MD5Sum< ::capra_ai::AddGoal > 
template<>
struct MD5Sum< ::capra_ai::AddGoalResponse>
{
  static const char* value()
  {
    return MD5Sum< ::capra_ai::AddGoal >::value();
  }
  static const char* value(const ::capra_ai::AddGoalResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::capra_ai::AddGoalResponse> should match 
// service_traits::DataType< ::capra_ai::AddGoal > 
template<>
struct DataType< ::capra_ai::AddGoalResponse>
{
  static const char* value()
  {
    return DataType< ::capra_ai::AddGoal >::value();
  }
  static const char* value(const ::capra_ai::AddGoalResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // CAPRA_AI_MESSAGE_ADDGOAL_H
