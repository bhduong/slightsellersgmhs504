#include <kipr/wombat.h>
// void loops
void lturn(); 
void rturn();
void arcleft();
void arcright();
void backarcleft();
void backarcright();

void fore(); 
void back();

void meetline();
void meetlineback();

void linetrackfore();
void linetrackback();

void moveplowup(); 
void moveplowdown();

void movearmup();
void movearmpomtop();
void movearmdown();

void movewristleft();
void movewristcenter();
void movewristright();

void thereset();
//variables
int dist();
int ltdist();
int angle();
int nm= 150; //nm stands for normal speed 
// wrist
int wristservo = 0;
int wristcenter= 1028;
int wristleft= 150;
int wristright= 1900;
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

    //0-20 To Rock Heap

    moveplowdown();
    movearmup();
    movewristcenter();

    meetlineback();
    msleep(100);
    back(100);
    meetlineback();
    msleep(100);
    back(340);
    lturn(90);
    meetlineback();
    fore(50);
    meetlineback();
    msleep(500);
    fore(20);
    msleep(100);

    rturn(35);
    back(470);
    msleep(100);
    moveplowup();
    msleep(500);
    back(20);
    msleep(100);
    rturn(45);
    msleep(100);
    back(200);

    // 20-40 sort fuel
    
    movewristleft();
    linetrackfore(5);
    msleep(250);
    movearmdown();
    msleep(500);
    movewristright();
    msleep(250);
    movewristleft();
    msleep(250);

    linetrackfore(150);
    msleep(250);
    movewristright();
    msleep(250);
    movewristleft();
    msleep(250);

    linetrackfore(150);
    msleep(250);
    movewristright();
    msleep(250);
    
    //collect remaining rocks
    
    movearmup();
    linetrackfore(200);
    lturn(210);
    moveplowdown();
    msleep(400);
    backarcleft(450);
    lturn(35);
    backarcleft(300);
    msleep(250);
    back(500);
    lturn(75);
    fore(100);
    meetline();
    
    //30-45 Flip solar panel 
    //~=+5 sec
    //65-80 knock around fertilizer food 
    //80-95 move other collected rocks to heap
    //95-110 return to start
    //game ends ~= 8 seconds later (cushion)
    thereset();
    create_disconnect();
    camera_close();
    disable_servos();
    msleep(50);
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
    set_create_distance(0);
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
    set_create_distance(0);
} 

void fore(int dist)
{
  while (abs(get_create_distance()) < dist) {
           create_drive_direct(nm, nm);
        msleep(10);
    }
    create_stop();
    set_create_total_angle(0);
    set_create_distance(0);
}

void back(int dist)
{
    while (abs(get_create_distance()) < dist) {
           create_drive_direct(-nm, -nm);
        msleep(10);
    }
    create_stop();
    set_create_total_angle(0);
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

void movearmup()
{
    set_servo_position(armservo, armtop);
    msleep(10);
}

void movearmpomtop()
{
    set_servo_position(armservo, armpomtop);
    msleep(10);
}

void movearmdown()
{
    set_servo_position(armservo, armdown);
    msleep(10);
}

void movewristleft()
{
    set_servo_position(wristservo, wristleft);
    msleep(10);
}
void movewristcenter()
{
    set_servo_position(wristservo, wristcenter);
    msleep(10);
}

void movewristright()
{
    set_servo_position(wristservo, wristright);
    msleep(10);
}

void linetrackfore(int ltdist)
{
      while (abs(get_create_distance()) < ltdist) {
           while(get_create_lfcliff_amt() > 2000)
           {
               create_drive_direct(100,25);
               msleep(10);
               }
       while(get_create_lfcliff_amt() < 2000)
           {
               create_drive_direct(25,100);
               msleep(10);
           }
        msleep(10);
    }
    create_stop();
    set_create_distance(0);
    set_create_total_angle(0);
}

void linetrackback(int ltdist)
{
      while (abs(get_create_distance()) < ltdist) {
           while(get_create_rfcliff_amt() < 2000)
           {
               create_drive_direct(-100,-25);
               msleep(10);
           }
       while(get_create_rfcliff_amt() > 2000)
           {
               create_drive_direct(-25,-100);
               msleep(10);
           }
        msleep(10);
    }
    create_stop();
     set_create_distance(0);
    set_create_total_angle(0);
}

void meetline() 
{
    while((get_create_lfcliff_amt() > 2000) || (get_create_rfcliff_amt() > 2000))
    {
        if(get_create_lfcliff_amt() > 2000 && get_create_rfcliff_amt() > 2000)
        {
            create_drive_direct(nm,nm);
           msleep(10);
        }
           if(get_create_lfcliff_amt() < 2000 && get_create_rfcliff_amt() > 2000)
        {
           create_drive_direct(-50, 50);
           msleep(10);
        }
        if(get_create_lfcliff_amt() > 2000 && get_create_rfcliff_amt() < 2000)
        {
           create_drive_direct(50, -50);
           msleep(10);
        }
    }
        create_stop();      
    set_create_distance(0);
    set_create_total_angle(0);
}        

void meetlineback() 
{
    while((get_create_lfcliff_amt() > 2000) || (get_create_rfcliff_amt() > 2000))
    {
        if(get_create_lfcliff_amt() > 2000 && get_create_rfcliff_amt() > 2000)
        {
            create_drive_direct(-nm,-nm);
        }
           if(get_create_lfcliff_amt() < 2000 && get_create_rfcliff_amt() > 2000)
        {
           create_drive_direct(50, -50);
        }
        if(get_create_lfcliff_amt() > 2000 && get_create_rfcliff_amt() < 2000)
        {
           create_drive_direct(-50, 50);
        }
    }
        create_stop();     
            set_create_distance(0);
            set_create_total_angle(0);
}       

void thereset() 
{
    movewristcenter();
    movearmup();
    moveplowup();
    msleep(250);
}

void arcleft(int dist)
{
   set_create_total_angle(0);
 while (abs(get_create_distance()) < dist)
 {
   create_drive_direct(55, 150);
    msleep(10);
 }
    create_stop();
    set_create_total_angle(0);
    set_create_distance(0);
} 

void arcright(int dist)
{
   set_create_total_angle(0);
 while (abs(get_create_distance()) < dist)
 {
   create_drive_direct(150, 55);
    msleep(10);
 }
    create_stop();
    set_create_total_angle(0);
    set_create_distance(0);
} 

void backarcleft(int dist)
{
   set_create_total_angle(0);
 while (abs(get_create_distance()) < dist)
 {
   create_drive_direct(-150, -55);
    msleep(10);
 }
    create_stop();
    set_create_total_angle(0);
    set_create_distance(0);
} 

void backarcright(int dist)
{
   set_create_total_angle(0);
 while (abs(get_create_distance()) < dist)
 {
   create_drive_direct(-55, -150);
    msleep(10);
 }
    create_stop();
    set_create_total_angle(0);
    set_create_distance(0);
} 
