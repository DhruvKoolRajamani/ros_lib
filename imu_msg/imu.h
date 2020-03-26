#ifndef _ROS_imu_msg_imu_h
#define _ROS_imu_msg_imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Time.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Int16.h"
#include "std_msgs/Bool.h"

namespace imu_msg
{

  class imu : public ros::Msg
  {
    public:
      typedef std_msgs::Time _time_type;
      _time_type time;
      std_msgs::Float64 accelerometer[3];
      std_msgs::Float64 gyroscope[3];
      std_msgs::Int16 control_regs[3];
      typedef std_msgs::Bool _status_type;
      _status_type status;

    imu():
      time(),
      accelerometer(),
      gyroscope(),
      control_regs(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->time.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      offset += this->accelerometer[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += this->gyroscope[i].serialize(outbuffer + offset);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += this->control_regs[i].serialize(outbuffer + offset);
      }
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->time.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      offset += this->accelerometer[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += this->gyroscope[i].deserialize(inbuffer + offset);
      }
      for( uint32_t i = 0; i < 3; i++){
      offset += this->control_regs[i].deserialize(inbuffer + offset);
      }
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "imu_msg/imu"; };
    const char * getMD5(){ return "7f0d8ed48d62f4f2f395c20714ea09be"; };

  };

}
#endif
