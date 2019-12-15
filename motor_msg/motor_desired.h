#ifndef _ROS_motor_msg_motor_desired_h
#define _ROS_motor_msg_motor_desired_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Float32.h"

namespace motor_msg
{

  class motor_desired : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef std_msgs::UInt8 _motor_id_type;
      _motor_id_type motor_id;
      typedef std_msgs::Float32 _desired_force_type;
      _desired_force_type desired_force;
      typedef std_msgs::Float32 _torque_constant_type;
      _torque_constant_type torque_constant;

    motor_desired():
      header(),
      motor_id(),
      desired_force(),
      torque_constant()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->motor_id.serialize(outbuffer + offset);
      offset += this->desired_force.serialize(outbuffer + offset);
      offset += this->torque_constant.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->motor_id.deserialize(inbuffer + offset);
      offset += this->desired_force.deserialize(inbuffer + offset);
      offset += this->torque_constant.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "motor_msg/motor_desired"; };
    const char * getMD5(){ return "05995bef51f65c606062467b9efc109a"; };

  };

}
#endif
