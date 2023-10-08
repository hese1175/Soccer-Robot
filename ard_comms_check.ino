#include <NewPing.h>

// USS
#define SONAR_NUM 1      // Number of sensors.
#define MAX_DISTANCE 30 // Maximum distance (in cm) to ping.

float factor = sqrt(1.00 + 25.00 / 273.15) / 60.368; // Speed of sound calculation based on temperature.

NewPing sonar[SONAR_NUM] = {
NewPing(6, 7, MAX_DISTANCE)};


// Initialize buffers

#define ACT_REQ_LENGTH 9
#define OBS_RPL_LENGTH 25

byte act_req_buffer[ACT_REQ_LENGTH];
byte obs_rpl_buffer[OBS_RPL_LENGTH];

void setup() 
{
  // SERIAL
  Serial.begin(115200);
}

byte req_id[1];

void loop() {  
  while (Serial.available() > 0) {
    Serial.readBytes(req_id, 1); 

    if (req_id[0] == 0xaa) {
      Serial.readBytes(act_req_buffer, ACT_REQ_LENGTH);
      act_request(act_req_buffer);  
      return;
    } 
    else if (req_id[0] == 0xbb) {
      obs_request();
      return;
    }
  }
  delay(100);
}

void act_request(byte act_req_buffer[ACT_REQ_LENGTH]) {    
  Serial.write(0x1a);
}

// ISSUE: returns all zeros, make sure bit-shifting is correct
void obs_request() {
  // ultra sonic sensor 1
  int d_r0 = getRange(0);
  obs_rpl_buffer[0] = d_r0;
  obs_rpl_buffer[1] = d_r0 >> 8;


  Serial.write(obs_rpl_buffer, 2);
}

int getRange(int ID) {
  //sending data in mm
  int distance = sonar[ID].ping_median(5) * factor * 10;
  delay(60);  

  Serial.println(result);
}


