#ifndef _ROS_motor_msg_cmd_light_h
#define _ROS_motor_msg_cmd_light_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace motor_msg
{

  class cmd_light : public ros::Msg
  {
    public:
      typedef int16_t _cmd_type;
      _cmd_type cmd;

    cmd_light():
      cmd(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_cmd;
      u_cmd.real = this->cmd;
      *(outbuffer + offset + 0) = (u_cmd.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_cmd.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->cmd);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_cmd;
      u_cmd.base = 0;
      u_cmd.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_cmd.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->cmd = u_cmd.real;
      offset += sizeof(this->cmd);
     return offset;
    }

    const char * getType(){ return "motor_msg/cmd_light"; };
    const char * getMD5(){ return "e12b32aac6266778a9aa3b101cf7c33e"; };

  };

}
#endif
