#include <kipr/wombat.h>
void lturn(int angle); //the angles allow 45 or 90, positive int
void rturn(int angle);
void back();
void fore();
void plowup();
void plowdown();
int t();
// planned void for flip flopping here 

//misc
int nm= 150; //nm stands for normal speed 
//1st servo
int flickservo = 0;
int center= 1028;
int flip= 1900;  //flip flop to knock out the poms
int flop= 150;
//2nd servo 
int armservo = 1;
int armtop = 1;
int pomlevel = 1382;
int pombot = 1471; 
//insert pombottom here 
int plowservo = 2;
int plowtop = 2047;
int plowbot = 70;

int main()
{
    create_connect();
    set_create_distance(0);
    set_create_total_angle(0);
    enable_servos();
    shut_down_in(118);
    //0-15 Drives forward to moon rock by lava tubes
    plowdown();
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
    plowup();
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
 while (abs(get_create_total_angle())<angle)
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
 while (abs(get_create_total_angle())<angle)
 {
   create_drive_direct(nm, -nm);
    msleep(10);
 }
    create_stop();
    set_create_total_angle(0);
} 

void fore(int t)
{
  while (abs(get_create_distance()) < t) {
           create_drive_direct(nm, nm);
        msleep(10);
    }
    create_stop();
    set_create_distance(0);
}

void back(int t)
{
    while (abs(get_create_distance()) < t) {
           create_drive_direct(-nm, -nm);
        msleep(10);
    }
    create_stop();
    set_create_distance(0);
}
void plowup()
{
    set_servo_position(plowservo, plowtop); 
    msleep(10);
}
void plowdown()
{
    set_servo_position(plowservo, plowbot);
    msleep(10);
}