// Generated by gencpp from file capra_controlpanel/SetRequest.msg
// DO NOT EDIT!


#ifndef CAPRA_CONTROLPANEL_MESSAGE_SETREQUEST_H
#define CAPRA_CONTROLPANEL_MESSAGE_SETREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace capra_controlpanel
{
template <class ContainerAllocator>
struct SetRequest_
{
  typedef SetRequest_<ContainerAllocator> Type;

  SetRequest_()
    : name()
    , state(false)  {
    }
  SetRequest_(const ContainerAllocator& _alloc)
    : name(_alloc)
    , state(false)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;

   typedef uint8_t _state_type;
  _state_type state;




  typedef boost::shared_ptr< ::capra_controlpanel::SetRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::capra_controlpanel::SetRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SetRequest_

typedef ::capra_controlpanel::SetRequest_<std::allocator<void> > SetRequest;

typedef boost::shared_ptr< ::capra_controlpanel::SetRequest > SetRequestPtr;
typedef boost::shared_ptr< ::capra_controlpanel::SetRequest const> SetRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::capra_controlpanel::SetRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::capra_controlpanel::SetRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace capra_controlpanel

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'capra_controlpanel': ['/home/capra/Ibex/src/capra_controlpanel/msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::capra_controlpanel::SetRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::capra_controlpanel::SetRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_controlpanel::SetRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_controlpanel::SetRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_controlpanel::SetRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_controlpanel::SetRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::capra_controlpanel::SetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a02bbd4704518df654c6d45037dfc59f";
  }

  static const char* value(const ::capra_controlpanel::SetRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa02bbd4704518df6ULL;
  static const uint64_t static_value2 = 0x54c6d45037dfc59fULL;
};

template<class ContainerAllocator>
struct DataType< ::capra_controlpanel::SetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "capra_controlpanel/SetRequest";
  }

  static const char* value(const ::capra_controlpanel::SetRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::capra_controlpanel::SetRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string name\n\
bool state\n\
";
  }

  static const char* value(const ::capra_controlpanel::SetRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::capra_controlpanel::SetRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.name);
      stream.next(m.state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SetRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::capra_controlpanel::SetRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::capra_controlpanel::SetRequest_<ContainerAllocator>& v)
  {
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
    s << indent << "state: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.state);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAPRA_CONTROLPANEL_MESSAGE_SETREQUEST_H
