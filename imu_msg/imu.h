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
      typedef std_msgs::Int16 _checksum_type;
      _checksum_type checksum;
      typedef std_msgs::Float64 _temperature_type;
      _temperature_type temperature;

    imu():
      time(),
      accelerometer(),
      gyroscope(),
      control_regs(),
      status(),
      checksum(),
      temperature()
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
      offset += this->checksum.serialize(outbuffer + offset);
      offset += this->temperature.serialize(outbuffer + offset);
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
      offset += this->checksum.deserialize(inbuffer + offset);
      offset += this->temperature.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "imu_msg/imu"; };
    const char * getMD5(){ return "2b5c8fe04daacafb6a6d6f2e07557a19"; };

  };

}
#endif
