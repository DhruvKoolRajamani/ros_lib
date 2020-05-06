#ifndef _ROS_imu_msg_imu_light_h
#define _ROS_imu_msg_imu_light_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace imu_msg
{

  class imu_light : public ros::Msg
  {
    public:
      int16_t accelerometer[3];
      int16_t gyroscope[3];

    imu_light():
      accelerometer(),
      gyroscope()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_accelerometeri;
      u_accelerometeri.real = this->accelerometer[i];
      *(outbuffer + offset + 0) = (u_accelerometeri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelerometeri.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->accelerometer[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_gyroscopei;
      u_gyroscopei.real = this->gyroscope[i];
      *(outbuffer + offset + 0) = (u_gyroscopei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyroscopei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->gyroscope[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_accelerometeri;
      u_accelerometeri.base = 0;
      u_accelerometeri.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accelerometeri.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->accelerometer[i] = u_accelerometeri.real;
      offset += sizeof(this->accelerometer[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_gyroscopei;
      u_gyroscopei.base = 0;
      u_gyroscopei.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyroscopei.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gyroscope[i] = u_gyroscopei.real;
      offset += sizeof(this->gyroscope[i]);
      }
     return offset;
    }

    const char * getType(){ return "imu_msg/imu_light"; };
    const char * getMD5(){ return "0070330febf44d88d21e1d8326ef9576"; };

  };

}
#endif
