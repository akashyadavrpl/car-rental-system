#include <stdio.h>
#include <stdlib.h>
#include"conio2.h"
#include"car.h"

int main()
{
    gotoxy(25,10);
    textcolor(YELLOW);
    printf("WELCOME TO CAR RENTAL SYSTEM");
    gotoxy(20,13);
    textcolor(LIGHTGREEN);
    printf("* RENT A CAR AND GO WHEREVER YOU NEED *");
    _getch();
    textcolor(YELLOW);
    addAdmin();
    User *usr;
    int result;
    int choice,type,i;
    while(1)
    {
        clrscr();
        textcolor(LIGHTRED);
        gotoxy(32,2);
        printf("CAR RENTAL SYSTEM");
        //UPPER LINE
        gotoxy(1,8);
        textcolor(YELLOW);
        for(i=0;i<80;i++)
            printf("*");
        //LOWER LINE
        gotoxy(1,17);
        for(i=0;i<80;i++)
            printf("*");
        gotoxy(32,10);
        textcolor(YELLOW);
        printf("1.ADMIN");
        gotoxy(32,12);
        printf("2.EMPLOYEE");
        gotoxy(32,14);
        textcolor(WHITE);
        int k;
        printf("select your role:");
        do
        {
            scanf("%d",&type);
            k=0;
            if(type==1)
            {
                do
                {
                    usr=getInput();
                    if(usr!=NULL)
                    {
                        k=checkUserExist(*usr,"admin");
                    }
                    else
                    {
                        break;
                    }
                }while(k==0);
                if(k==1)
                {
                    gotoxy(30,14);
                    textcolor(LIGHTGREEN);
                    printf("Login Accepted!");
                    gotoxy(1,20);
                    textcolor(WHITE);
                    printf("Press any key to continue");
                    _getch();
                    while(1)
                    {

                        clrscr();
                        choice=adminMenu();
                        if(choice==7)
                        {
                            clrscr();
                            break;
                        }
                        switch(choice)
                        {
                            case 1:
                                clrscr();
                                addEmployee();
                                break;
                            case 2:
                                addCarDetails();
                                break;
                            case 3:
                                clrscr();
                                viewEmployee();
                                break;
                            case 4:
                                showCarDetails();
                                break;
                            case 5:
                                clrscr();
                                result=deleteEmp();
                                if(result==0)
                                {
                                    gotoxy(15,14);
                                    textcolor(LIGHTRED);
                                    printf("Sorry! No employee found with the given Employee ID");

                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main menu");
                                    _getch();
                                }
                                    else if(result==1)
                                    {
                                        gotoxy(25,14);
                                        textcolor(LIGHTGREEN);
                                        printf("Record Delete Successfully");
                                        textcolor(WHITE);
                                        printf("*\n\nPress any key to go back to the main menu ");
                                        _getch();
                                    }

                                break;
                            case 6:
                                result=deleteCarModel();
                                if(result==0)
                                {
                                    gotoxy(15,14);
                                    textcolor(LIGHTRED);
                                    printf("Sorry! No car found with the given CAR-ID");
                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main menu");
                                    _getch();
                                }
                                else if(result==1)
                                {
                                    gotoxy(25,14);
                                    textcolor(LIGHTGREEN);
                                    printf("Record Deleted successfully");
                                    textcolor(WHITE);
                                    printf("\n\nPress any key to go back to the main menu");
                                    _getch();

                                }
                                break;
                            default:
                                printf("Incorrect Choice:");
                                _getch();
                                break;
                        }//switch close
                    }
                }
            }

                //code for handling admin login

            else if(type==2)
            {
                do
                {
                    usr=getInput();
                    if(usr!=NULL)
                    {
                        k=checkUserExist(*usr,"emp");
                    }
                    else
                    {
                        break;
                    }
                   } while(k==0);
                        if(k==1)
                    {
                        gotoxy(30,14);
                        textcolor(LIGHTGREEN);
                        printf("Login Accepted!");
                        gotoxy(1,20);
                        textcolor(WHITE);
                        printf("press any key to continue");
                        _getch();
                        while(1)
                        {
                            clrscr();
                            choice=empMenu();
                            if(choice==5)
                            {
                                clrscr();
                                break;
                            }
                            switch(choice)
                            {
                            case 1:
                                clrscr();
                                int j;
                                do
                                {
                                    clrscr();
                                    j=rentCar();
                                    if(j==0)
                                        printf("Booking Cancelled\nTry again...");
                                    _getch();
                                }while(j==0);
                                _getch();

                                 break;
                            case 2:
                                clrscr();
                               // bookedCarDetails();
                                break;
                            case 3:
                                clrscr();
                                break;
                            case 4:
                                clrscr();
                                break;
                            default:
                                printf("Incorrect choice:");
                            }
                        }
                    }


            }
            else
            {
                textcolor(LIGHTRED);
                gotoxy(30,20);
                printf("Invalid User Type");
                _getch();
                gotoxy(30,20);
                printf("\t\t\t");
                gotoxy(50,14);
                printf("\t");
                gotoxy(50,14);
                textcolor(WHITE);
            }

        }
        while(type!=1&&type!=2);
    }

    return 0;
}
