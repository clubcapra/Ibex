// Generated by gencpp from file ros_vision/FilterStatistics.msg
// DO NOT EDIT!


#ifndef ROS_VISION_MESSAGE_FILTERSTATISTICS_H
#define ROS_VISION_MESSAGE_FILTERSTATISTICS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_vision
{
template <class ContainerAllocator>
struct FilterStatistics_
{
  typedef FilterStatistics_<ContainerAllocator> Type;

  FilterStatistics_()
    : name()
    , average_execution_time(0.0)
    , last_execution_time(0.0)  {
    }
  FilterStatistics_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , average_execution_time(0.0)
    , last_execution_time(0.0)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef float _average_execution_time_type;
  _average_execution_time_type average_execution_time;

   typedef float _last_execution_time_type;
  _last_execution_time_type last_execution_time;




  typedef boost::shared_ptr< ::ros_vision::FilterStatistics_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_vision::FilterStatistics_<ContainerAllocator> const> ConstPtr;

}; // struct FilterStatistics_

typedef ::ros_vision::FilterStatistics_<std::allocator<void> > FilterStatistics;

typedef boost::shared_ptr< ::ros_vision::FilterStatistics > FilterStatisticsPtr;
typedef boost::shared_ptr< ::ros_vision::FilterStatistics const> FilterStatisticsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_vision::FilterStatistics_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_vision::FilterStatistics_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ros_vision

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'ros_vision': ['/home/capra/Ibex/src/ros_vision/msg', '/home/capra/Ibex/src/ros_vision/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::FilterStatistics_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_vision::FilterStatistics_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::FilterStatistics_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_vision::FilterStatistics_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::FilterStatistics_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_vision::FilterStatistics_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_vision::FilterStatistics_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a8b6d5ea7d644a18e4b5d9cfcc65d084";
  }

  static const char* value(const ::ros_vision::FilterStatistics_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa8b6d5ea7d644a18ULL;
  static const uint64_t static_value2 = 0xe4b5d9cfcc65d084ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_vision::FilterStatistics_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_vision/FilterStatistics";
  }

  static const char* value(const ::ros_vision::FilterStatistics_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_vision::FilterStatistics_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n\
float32 average_execution_time\n\
float32 last_execution_time\n\
";
  }

  static const char* value(const ::ros_vision::FilterStatistics_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_vision::FilterStatistics_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.average_execution_time);
      stream.next(m.last_execution_time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct FilterStatistics_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_vision::FilterStatistics_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_vision::FilterStatistics_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "average_execution_time: ";
    Printer<float>::stream(s, indent + "  ", v.average_execution_time);
    s << indent << "last_execution_time: ";
    Printer<float>::stream(s, indent + "  ", v.last_execution_time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_VISION_MESSAGE_FILTERSTATISTICS_H
