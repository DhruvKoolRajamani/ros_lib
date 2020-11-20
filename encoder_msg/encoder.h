#ifndef _ROS_encoder_msg_encoder_h
#define _ROS_encoder_msg_encoder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float32.h"

namespace encoder_msg
{

  class encoder : public ros::Msg
  {
    public:
      typedef std_msgs::Float32 _joint_angle1_type;
      _joint_angle1_type joint_angle1;
      typedef std_msgs::Float32 _joint_angle2_type;
      _joint_angle2_type joint_angle2;

    encoder():
      joint_angle1(),
      joint_angle2()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_angle1.serialize(outbuffer + offset);
      offset += this->joint_angle2.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_angle1.deserialize(inbuffer + offset);
      offset += this->joint_angle2.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "encoder_msg/encoder"; };
    const char * getMD5(){ return "3a041897f477b1b7d11ef4760d61dc27"; };

  };

}
#endif
