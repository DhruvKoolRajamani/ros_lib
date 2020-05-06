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
      float accelerometer[3];
      float gyroscope[3];

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
        float real;
        uint32_t base;
      } u_accelerometeri;
      u_accelerometeri.real = this->accelerometer[i];
      *(outbuffer + offset + 0) = (u_accelerometeri.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_accelerometeri.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_accelerometeri.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_accelerometeri.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->accelerometer[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_gyroscopei;
      u_gyroscopei.real = this->gyroscope[i];
      *(outbuffer + offset + 0) = (u_gyroscopei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_gyroscopei.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_gyroscopei.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_gyroscopei.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gyroscope[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_accelerometeri;
      u_accelerometeri.base = 0;
      u_accelerometeri.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_accelerometeri.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_accelerometeri.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_accelerometeri.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->accelerometer[i] = u_accelerometeri.real;
      offset += sizeof(this->accelerometer[i]);
      }
      for( uint32_t i = 0; i < 3; i++){
      union {
        float real;
        uint32_t base;
      } u_gyroscopei;
      u_gyroscopei.base = 0;
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_gyroscopei.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->gyroscope[i] = u_gyroscopei.real;
      offset += sizeof(this->gyroscope[i]);
      }
     return offset;
    }

    const char * getType(){ return "imu_msg/imu_light"; };
    const char * getMD5(){ return "f0257b4b31db476ff957a2cf40e373be"; };

  };

}
#endif
