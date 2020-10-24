#ifndef _ROS_imu_msg_imu_h
#define _ROS_imu_msg_imu_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Time.h"

namespace imu_msg
{

  class imu : public ros::Msg
  {
    public:
      typedef std_msgs::Time _time_type;
      _time_type time;
      float accelerometer[3];
      float gyroscope[3];
      int16_t control_regs[3];
      typedef bool _status_type;
      _status_type status;

    imu():
      time(),
      accelerometer(),
      gyroscope(),
      control_regs(),
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->time.serialize(outbuffer + offset);
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
      for( uint32_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_control_regsi;
      u_control_regsi.real = this->control_regs[i];
      *(outbuffer + offset + 0) = (u_control_regsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_control_regsi.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->control_regs[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->time.deserialize(inbuffer + offset);
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
      for( uint32_t i = 0; i < 3; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_control_regsi;
      u_control_regsi.base = 0;
      u_control_regsi.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_control_regsi.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->control_regs[i] = u_control_regsi.real;
      offset += sizeof(this->control_regs[i]);
      }
      union {
        bool real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return "imu_msg/imu"; };
    const char * getMD5(){ return "da7f23abfd15c5f6de7b240ca5c6aed3"; };

  };

}
#endif
