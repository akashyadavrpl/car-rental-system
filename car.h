#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include<time.h>
struct user
{
    char userid[20];
    char pwd[20];
    char name[20];
};
/*struct pwd
{
 char car_name[50];
 int car_id;
 int capacity;
 int car_count;
 int price;
};*/
struct Car
{
    int car_id;
    char car_name[50];
    int capacity;
    int car_count;
    int price;
};
struct customer_car_details
{
    int car_id;
    char cust_name[30];
    char pick[30];
    char drop[30];
    struct tm sd,ed;
};
typedef struct user User;
typedef struct pwd pwd;
typedef struct customer_car_details customer_car_details;
typedef struct Car Car;

void addAdmin();
User* getInput();
int checkUserExist(User,char*);
int adminMenu();
void addEmployee();
void viewEmlpoyee();
void addCarDetails();
void showCarDetails();
int deleteEmp();
int deleteCarModel();
void sub_str(char*,char*,char);
int empMenu();
int rentCar();
int selectCarModel();
void updateCarCount(int);
void bookedCarDetails();
char * getCarName(int);
int isValidDate(struct tm);
void welcomeDisplay();
void userOption();



#endif // CAR_H_INCLUDED
