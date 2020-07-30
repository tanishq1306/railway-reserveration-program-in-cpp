/**
    "Program for railway reservation"

     Made by - @tanishq
**/

#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>
#include<fstream>   //  header file for goto (x, y)
#include<time.h>

using namespace std;

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

COORD coord= {0,0}; // this is global variable
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int flag = 0, price = 0;

class person
{
    private:
        char lname[15];
        int tamt;
        char st1[10];
        char st2[10];
        char fname[15];
        char tckt[10];
        int noft;
        char mno[10];
        void pay();

    public:
        char* re_fname()
        {
            return fname;
        }

        char* re_mno()
        {
            return mno;
        }

        int re_noft()
        {
            return noft;
        }

        void getdata()
        {
            cin.ignore();

            cout << "\nEnter Your First Name:";
            gets(fname);
            delay(100);

            cout << "\nEnter Your Last Name:";
            gets(lname);
            delay(100);

            cout << "\nEnter Your Contact No.:";
            gets(mno);
            delay(100);

            cout << "\nBoarding point:";
            gets(st1);

            cout << "\nDestination pt:";
            gets(st2);

            pay();
        }

        void display()
        {
            cout << "\nFull Name Of Passenger:  "<< fname << " " << lname;
            cout << "\n\nMobile No : "<< mno;
            cout << "\n\nType Of Ticket Booked : "<< tckt;
            cout << "\n\nBoarding point : " << st1;
            cout << "\n\nDestination pt : " << st2;
            cout << "\n\nNo Of Tickets : " << noft;
            cout << "\n\nTotal Amount : " << tamt;
            cout << "\n========================================================\n";
        }
};

void write(person &p)
{
    ofstream fout;
    fout.open("person.txt",ios::out|ios::binary|ios::ate|ios::app);
    fout.write((char*)&p,sizeof(person));
    fout.close();
}

void records()
{
    ifstream fin;

    int num = 1;
    fin.open("person.txt",ios::in|ios::binary);
    person p;

    while(!fin.eof())
    {
        fin.read((char*)&p,sizeof(p));

        if(fin.eof())
        {
            break;
        }

        cout << "\t \t ("<< num << ")";

        p.display();
        num++;
    }
    fin.close();
}


void person::pay()
{
    int m, price = 50;

    cout << "\n1.Ticket for Local\n2.Ticket For Sleeper\n3.Ticket For A.C";
    cout << "\nEnter Your Choice:";
    cin >> m;
    cout << "\nEnter No Of Tickets: ";
    cin >> noft;

    if(m == 1)
    {
        cout << "Price for one ticket " << price;
        strcpy(tckt, "Local");
    }

    else if(m == 2)
    {
        price = price * 3;
        cout << "Price for one ticket " << price;
        strcpy(tckt, "sleeper");
    }

    else if(m == 3)
    {
        price = price * 5;
        cout << "Price for one ticket " << price;
        strcpy(tckt, "A.C");
    }

    tamt = price * noft;
    cout << "\nYour Total Amount Is: " << tamt;

    cout << "\nEnter The Mode Of Payment";
    cout << "\n\n1.Paytm";
    cout << "\n\n2.Debit/Credit";
    cout << "\n\nEnter Your Choice:";
    cin >> m;

    if(m == 1)
    {
        char mn[10];
        cout<<"\nEnter Your Mobile No.";
        gets(mn);

        cout<<"\nPayment Confirmed";
        cout<<"\tTHANK YOU FOR USING............";
    }

    else if(m == 2)
    {
        int acno;
        cout<<"Enter your Account No.";
        cin>>acno;

        cout<<"\nPayment Confirmed";
        cout<<"\tTHANK YOU FOR USING............";
    }
}

void login()
{
    int choice;
    do
    {
        system("cls");

        gotoxy(30,0);
        printf("ENTER YOUR MODE:\n");
        printf("\n1. Administrator");
        printf("\n2. User\n");

        cin >> choice;

        if(choice == 1)
        {
            string pass;

            printf("\nPlease Enter Your Password : ");
            cin.ignore();

            int i = 0;
            char ch;

            ch = getch();
            while(ch != 13)     //13 - ASCII value for Enter
            {
                pass += ch;
                cout << '*';
                ch = getch();
            }

            if(pass == "india")
            {
                flag = 1;
                printf("\nPassword confirmed");
                cout<<"\n\nPress enter to continue";
                getch();
            }
            else
            {
                printf("\nIncorrect Password SORRY!!!!!");
                printf("\nENDING PROCESS....................");
                delay(1000);
                cout<<"\ntry again";
            }
        }
    }while(choice == 1 and flag == 0);
}

int main()
{
    //starting page
    gotoxy(30, 0);
    cout << "COMPUTER PROJECT\n";
    gotoxy(30, 1);
    cout << "================";
    delay(1000);

    cout << "\n\nSUBMITTED BY - TANISHQ SAINI";
    delay(1000);

    cout << "\nSUBMITTED TO - SHEKHAR SIR";
    delay(1000);

    printf("\n\nPress ENTER T0 Continue....................");
    getch();

    //login as user or admin
    login();

    //next page
    string welcomeStr = "WELCOME TO WESTERN RAILWAYS";

    system("cls");
    gotoxy(30, 0);

    do
    {
        system("cls");
        gotoxy(20, 0);

        for(int i = 0; i < (int)welcomeStr.size(); i++)
        {
            cout << welcomeStr[i] ;
            delay(50);
        }
        cout << "\n";
        gotoxy(20, 1);
        cout << "===========================";


        cout << "\n";

        int choice;
        int i = 3;

        gotoxy(20, i = i + 2);
        printf("1.Book Ticket");

        gotoxy(20, i = i + 2);
        printf("2.Booking Records");

        gotoxy(20, i = i + 2);
        printf("3.Cancel Ticket");

        gotoxy(20, i = i + 2);
        printf("4.Details Of Various Trains");

        gotoxy(20, i = i + 2);
        printf("5.Search For Your Record");

        gotoxy(20, i = i + 2);
        printf("6.Exit");

        gotoxy(20, i = i + 3);
        printf("Enter Your Choice: ");

        cin >> choice;

        system("cls");

        switch(choice)
        {

            case 1:
            {
                person p;
                p.getdata();
                write(p);
                getch();
                break;
            }

            case 2:
            {
                if(flag == 1)
                {
                    cout<<"                       Welcome Administrator\n";
                    cout<<"                       =====================\n";

                    cout<<"\nRecords Are:\n\n";

                    records();

                    cout<<"\n\nPress enter to exit..............";
                    getch();
                }
                else
                {
                    cout<<"\n                     SORRY ONLY FOR ADMINISTRATOR";
                    cout<<"\n                     ============================";

                    cout<<"\n\nPress enter to exit..............";
                    getch();
                }

                break;
            }

            case 3:
            {
                ifstream file("person.txt", ios::in | ios::binary|ios::ate); // ios::ate
                cout<<" Enter your first name: ";

                string nm;
                cin >> nm;

                cout<<"\n \n \n";

                file.clear();
                file.seekg(0,ios::beg);

                ofstream temp("temp.txt",ios::binary|ios::out); //ios::app

                person p;
                int f = 0;

                while(file.read((char*)&p,sizeof(p)))
                {
                    if(nm == p.re_fname())
                    {
                        f = 1;
                        p.display();

                        cout<<"\n \n Do you really want to delete this record \? (y/n) \n";
                        char choice;
                        cin >> choice;

                        if(choice == 'n' || choice == 'N')
                        {
                            temp.write((char*)&p,sizeof(p));
                        }

                        else
                        {
                            cout<<"\n .................Record deleted successfully..............";
                        }
                    }
                    else
                    {
                        temp.write((char*)&p,sizeof(p));
                    }
                }

                if(f == 1)
                {
                    remove("person.txt");
                    rename("temp.txt","person.txt");
                }
                else
                {
                    cout<<"\n ..............Sorry, student not found..............";
                }

                cout<<"\n \n \t \t......Press any key to continue.......";
                getch();

                temp.close();
                file.close();

                break;
            }

            case 4:
            {

                char str[120];
                ifstream fin("r_list.txt",ios::in);

                while(!fin.eof())
                {
                    fin.getline(str,120);

                    cout << str <<'\n';

                    if(fin.eof())
                        break;
                }

                fin.close();
                getch();
                break;
            }

            case 5:
            {
                ifstream fin;
                fin.open("person.txt",ios::in|ios::binary);
                person p;

                int flg = 0;
                string nm;

                cout << "\nEnter the name to be searched ";
                cin >> nm;

                while(fin.read((char*)&p,sizeof(p)))
                {
                    if(nm == p.re_fname())
                    {
                        p.display();
                        flg = 1;
                    }
                }

                if(flg == 0)
                    cout<<"\nSORRY RECORD NOT FOUND ";

                fin.close();
                getch();
                break;
            }

            case 6:
            {
                gotoxy(40,10);
                cout<<"............EXIT.................\n\n\n\n\n\n\n\n";
                exit(0);
            }

            default:
            {
                gotoxy(20, i = i + 2);
                printf("Invalid key, try again !! ");
                getch();
            }
        };
    }   while(1);

    return 0;
}











































































