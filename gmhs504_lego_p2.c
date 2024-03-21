#include <kipr/wombat.h>
//speeds
int ns=800; //normal speed
int hs=400; //half speed
//motors and servos(ports & values)
int lm=0; // left motor is the 0 port
int rm=3; // right motor is the 3 port
int arm=0; // main servo that moves the arm up and down, port 0
int claw=1; // claw servo that opens and closes the claw, port 1
int light=2; // light sensor 
//values
int up= 1024; //arm value 
int down= 223; //arm value
int airlock= 137; //arm value
int close= 2000; // claw value
int open= 1028; //claw value
int clawlock= 1747; //claw value
int main() 
{
// 0-15: Open airlock & flips switch (about 55cm away for the first move, then about 35cm for the light switch+area for cube)

  //  wait_for_light(light);
  //  shut_down_in(118);
  enable_servos();
    //set_servo_position(arm, up);
    //set_servo_position(claw, close);
   //driven(4000);
    //msleep(10);
    //lturn(210);
   // set_servo_position(arm, airlock);
    //msleep(100);
    //set_servo_position(claw, clawlock);
    //msleep(100);
   // set_servo_position(arm, airlock);
    //msleep(1000);
    //set_servo_position(claw, clawlock);
    //msleep(1000);
   //driven(1000);
   // msleep(1000);
    set_servo_position(claw, close);
    msleep(1000);
    bdriven(2000);
//15-30: Takes 1st multiplier cube, places it in area 3 (about 50cm away)
    
    
// 30-45: Takes 2nd multiplier cube, places it in rock keep, starts moving towards lava tubes (back 50cm, then 80cm to rock keep, and then about 52cm away to get to the lava tube)
    
    
// 45-60: Takes ice out of 1st lava tube(closest to rock keep), moves towards next lava tube 
    
    
// 60-75: Takes ice out 2nd lava tube, starts advancing towards the airlock (about 90-120cm)
    
    
// 75-90: Moves to the air lock  (about 90-120cm)
    
    
//90-105: Dumps all ice into the airlock and closes it, while knocking and other multiplier cubes in (if nescessary)
    
    
//105-120: Return to the start (about 55cm away)
    
    return 0;
}
void driven (int distance)
{
    cmpc(lm);
    cmpc(rm); 
    while(gmpc(0) < distance)
    {
    	 mav(lm,ns);
     	 mav(rm,ns);
    }
    cmpc(lm);
    cmpc(rm);
}
void drives (int distance)
{
    cmpc(lm);
    cmpc(rm); 
    while(gmpc(0) < distance)
    {
    	 mav(lm,hs);
     	 mav(rm,hs);
    }
    cmpc(lm);
    cmpc(rm);
}
void lturn (int distance)
{
    cmpc(lm);
    cmpc(rm); 
    while(abs(gmpc(0)) < distance)
    {
    	 mav(lm,-ns);
     	 mav(rm,ns);
    } 
    cmpc(lm);
    cmpc(rm);
}
void rturn (int distance)
{
    cmpc(lm);
    cmpc(rm); 
    while(abs(gmpc(0)) < distance)
    {
    	 mav(lm,ns);
     	 mav(rm,-ns);
    } 
    cmpc(lm);
    cmpc(rm);
}
void bdriven (int distance)
{
    cmpc(lm);
    cmpc(rm); 
    while(gmpc(0) < distance)
    {
    	 mav(lm,-ns);
     	 mav(rm,-ns);
    }
    cmpc(lm);
    cmpc(rm);
}

//side notes
//250 g weight in back, will be replaced by pennies 
