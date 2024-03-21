#include <kipr/wombat.h>
// void loops
void lturn(); 
void rturn(); 
void back(); 
void fore(); 
void moveplowup(); 
void moveplowdown();
//variables
int dist();
int angle();
//misc
int nm= 150; //nm stands for normal speed 
// wrist
int wristservo = 0;
int wristcenter= 1028;
int wristleft= 1900;
int wristright= 150;
//arm
int armservo = 1;
int armtop = 1;
int armpomtop = 1382;
int armdown = 1471; 
//plow
int plowservo = 2;
int plowup = 2047;
int plowdown = 70;

int main()
{
    create_connect();
    set_create_distance(0);
    set_create_total_angle(0);
    enable_servos();
    shut_down_in(118);
    //0-15 To Rock Heap
    moveplowdown();
    back(650); //exits bay
    lturn(15);
    back(200);
    rturn(15);
    back(260);
    rturn(20);
    back(230);
    msleep(500);
    lturn(90);
    back(450);
    rturn(15);
    back(50); //in rock heap
    msleep(2000);
    moveplowup();
    msleep(1000);
    //15-30 Drive to rock heap
    //30-45 Flip solar panel 
    //~=+5 sec
    //50-65 knock around fuel  
    //65-80 knock around fertilizer food 
    //80-95 move other collected rocks to heap
    //95-110 return to start
    //game ends ~= 8 seconds later (cushion)
    create_disconnect();
    camera_close();
    disable_servos();
    return 0;
}

void lturn(int angle)
{
 set_create_total_angle(0);
 while (abs(get_create_total_angle()) < angle)
 {
   create_drive_direct(-nm, nm);
    msleep(10);
 }
     create_stop();
    set_create_total_angle(0);
}

void rturn(int angle)
{
   set_create_total_angle(0);
 while (abs(get_create_total_angle()) < angle)
 {
   create_drive_direct(nm, -nm);
    msleep(10);
 }
    create_stop();
    set_create_total_angle(0);
} 

void fore(int dist)
{
  while (abs(get_create_distance()) < dist) {
           create_drive_direct(nm, nm);
        msleep(10);
    }
    create_stop();
    set_create_distance(0);
}

void back(int dist)
{
    while (abs(get_create_distance()) < dist) {
           create_drive_direct(-nm, -nm);
        msleep(10);
    }
    create_stop();
    set_create_distance(0);
}
void moveplowup()
{
    set_servo_position(plowservo, plowup); 
    msleep(10);
}
void moveplowdown()
{
    set_servo_position(plowservo, plowdown);
    msleep(10);
}
