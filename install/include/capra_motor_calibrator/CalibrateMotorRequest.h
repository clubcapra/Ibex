// Generated by gencpp from file capra_motor_calibrator/CalibrateMotorRequest.msg
// DO NOT EDIT!


#ifndef CAPRA_MOTOR_CALIBRATOR_MESSAGE_CALIBRATEMOTORREQUEST_H
#define CAPRA_MOTOR_CALIBRATOR_MESSAGE_CALIBRATEMOTORREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace capra_motor_calibrator
{
template <class ContainerAllocator>
struct CalibrateMotorRequest_
{
  typedef CalibrateMotorRequest_<ContainerAllocator> Type;

  CalibrateMotorRequest_()
    : calibration_distance(0.0)  {
    }
  CalibrateMotorRequest_(const ContainerAllocator& _alloc)
    : calibration_distance(0.0)  {
    }



   typedef float _calibration_distance_type;
  _calibration_distance_type calibration_distance;




  typedef boost::shared_ptr< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CalibrateMotorRequest_

typedef ::capra_motor_calibrator::CalibrateMotorRequest_<std::allocator<void> > CalibrateMotorRequest;

typedef boost::shared_ptr< ::capra_motor_calibrator::CalibrateMotorRequest > CalibrateMotorRequestPtr;
typedef boost::shared_ptr< ::capra_motor_calibrator::CalibrateMotorRequest const> CalibrateMotorRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace capra_motor_calibrator

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "49bd955ce067a1823b2bf83fe76fc084";
  }

  static const char* value(const ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x49bd955ce067a182ULL;
  static const uint64_t static_value2 = 0x3b2bf83fe76fc084ULL;
};

template<class ContainerAllocator>
struct DataType< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "capra_motor_calibrator/CalibrateMotorRequest";
  }

  static const char* value(const ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 calibration_distance\n\
";
  }

  static const char* value(const ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.calibration_distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct CalibrateMotorRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::capra_motor_calibrator::CalibrateMotorRequest_<ContainerAllocator>& v)
  {
    s << indent << "calibration_distance: ";
    Printer<float>::stream(s, indent + "  ", v.calibration_distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAPRA_MOTOR_CALIBRATOR_MESSAGE_CALIBRATEMOTORREQUEST_H