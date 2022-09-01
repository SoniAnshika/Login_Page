#include<bits/stdc++.h>
#include<ctime>
#include<conio.h>
using namespace std;
/*Parent Class that is Registering information of candidate.*/
class Sign_in
{
   /*Data members and methods of Parent Class Sign_in*/
   protected:
   string name,Phone_No;
   char password[10],Aadhaar_No[12],DOB[10];
   string email_id;

   public:
   Sign_in();
   void Input_Password();
   void check_name();
   void check_DOB();
   void check_Aadhaar_No();
   void check_Phone_No();
   void check_email_id();
};

Sign_in::Sign_in()
{
   cout<<"\nEnter Your Information:\n";
   cout<<"Name: ";
   cin.ignore();
   getline(cin,name);
   check_name();
   cout<<"Date of Birth  in form(DD-MM-YYYY): ";
   check_DOB();
   cout<<"Aadhaar No.: ";
   for(int i=0;i<12;i++)
    cin>>Aadhaar_No[i];
   check_Aadhaar_No();
   cout<<"Phone Number: ";
   cin>>Phone_No;
   check_Phone_No();
   cout<<"email_id: ";
   check_email_id();
   Input_Password();
}
/*Entering Password in secure form so that no one can see what user is entering.*/
void  Sign_in::Input_Password()
{
    int index;
    char keyAscii;
    cout<<"\nEnter Password: ";
    for(index=0;index<10;index++)
    {
      keyAscii=getch();
      password[index]=keyAscii;
      if(keyAscii!=13)
      {
       cout<<"*";
      }
      if(keyAscii==13)
        break;
    }
    password[index]='\0';
    cout<<"\n";
}
/*Checking Validation of name.*/
void Sign_in::check_name()
{
    int flag;
    while(1)
    {
    for(int index=0;index<name.length();index++)
    {
        flag=0;
        if((name[index]>=97 && name[index]<=122)||(name[index]>=65 && name[index]<=90)||name[index]==32)
        {
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"ERROR!!\nPlease, Enter your name again: ";
        cin.ignore();
        getline(cin,name);
    }
    else
    {
        cout<<"Name Registered Successfully \n"<<endl;
        break;
    }
    }
}
/*Checking Validation of Date of Birth.*/
void Sign_in::check_DOB()
{
    char DOB[10];
    /*Infinite loop to enter DOB until and unless user enter the correct DOB.*/
    while(1)
    {
    int flag,flag_Year,flag_age,flag_lp;
    int current_date,current_month,current_year;
    int  months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int index=0;index<10;index++)
        cin>>DOB[index];
    /*To calculate current date,month,year we are fetching them from system only by using time.h library.*/
    time_t t=time(0);
    tm* now=localtime(&t);
    /*Here, we got current date,month,year.*/
    current_date=now->tm_mday;
    current_month=(now->tm_mon + 1);
    current_year=(now->tm_year + 1900);
    /*This gives us birth date,month,year stored separately in different variables.*/
    string BD="";
    int birth_date;
    BD=(BD+DOB[0]+DOB[1]);
    birth_date=stoi(BD);
    string BM="";
    int birth_month;
    BM=(BM+DOB[3]+DOB[4]);
    birth_month=stoi(BM);
    string BY="";
    int birth_year;
    BY=(BY+DOB[6]+DOB[7]+DOB[8]+DOB[9]);
    birth_year=stoi(BY);
    /*Checking for Leap Year.*/
    if(birth_year%400==0)
    {
        flag_lp=1;
        months[1]=29;
    }
    else
        flag_lp=0;
    /*Finding Age of the user by finding difference between current and entered one*/
    if(birth_date> current_date)
    {
        birth_date=current_month + months[birth_month-1];
        current_month=current_month-1;
    }
    if(birth_month>current_month)
    {
       current_year=current_year-1;
       current_month=current_month +12;
    }
    int age=current_year-birth_year;
    if(age>100 || age<=0)
        flag_age=0;
    else
        flag_age=1;
     cout<<"Your Age is: "<<age<<endl;
     /*Verifying Entered Date.*/
     if(DOB[3]=='0')
     {
         if(DOB[4]=='1'||DOB[4]=='3'||DOB[4]=='5'||DOB[4]=='7'||DOB[4]=='8')
         {
             if((DOB[0]>='0' && DOB[0]<='3')&&(DOB[1]>='0' && DOB[1]<='9'))
             {
                if(DOB[0]!='0'&&DOB[1]!='0')
                 flag=1;
                 if(DOB[0]=='3')
                 {
                     flag=0;
                     if(DOB[1]=='0'||DOB[1]=='1')
                         flag=1;
                 }
             }
         }
         else if(DOB[4]=='4'||DOB[4]=='6'||DOB[4]=='9')
         {
             if((DOB[0]>='0' && DOB[0]<='3')&&(DOB[1]>='0' && DOB[1]<='9'))
             {
                if(DOB[0]!='0'&&DOB[1]!='0')
                 flag=1;
                 if(DOB[0]=='3')
                 {
                     flag=0;
                     if(DOB[1]=='0')
                        flag=1;
                 }
             }
         }
         else if(DOB[4]=='2')
         {
            if(flag_lp==1)
            {
             flag_lp=0;
             if((DOB[0]>='0' && DOB[0]<='2')&&(DOB[1]>='0' && DOB[1]<='9'))
             {
                 if(DOB[0]!='0'&&DOB[1]!='0')
                  flag_lp=1;
             }
            }
            else
            {
             if((DOB[0]>='0' && DOB[0]<='2')&&(DOB[1]>='0' && DOB[1]<='8'))
             {
                if(DOB[0]!='0'&&DOB[1]!='0')
                 flag_lp=1;
             }
            }
         }
     }
     else if((DOB[3]=='1')&&(DOB[4]=='0'||DOB[4]=='1'||DOB[4]=='2'))
     {
        if(DOB[4]=='0'||DOB[4]=='2')
         {
             if((DOB[0]>='0' && DOB[0]<='3')&&(DOB[1]>='0' && DOB[1]<='9'))
             {
                if(DOB[0]!='0'&&DOB[1]!='0')
                 flag=1;
                 if(DOB[0]=='3')
                 {
                     flag=0;
                     if(DOB[1]=='0'||DOB[1]=='1')
                         flag=1;
                 }
             }
         }
         else if(DOB[4]=='1')
         {
             if((DOB[0]>='0' && DOB[0]<='3')&&(DOB[1]>='0' && DOB[1]<='9'))
             {
                if(DOB[0]!='0'&&DOB[1]!='0')
                 flag=1;
                 if(DOB[0]=='3')
                 {
                     flag=0;
                     if(DOB[1]=='0')
                        flag=1;
                 }
             }
         }
     }
     else
        flag=0;
     if((DOB[0]=='2'&&DOB[1]=='0')||(DOB[0]=='1'&&DOB[1]=='0'))
        flag=1;
    /*Condition for Registering DOB or asking user to re-entering the DOB*/
    if((flag==1 || flag_lp==1) && flag_age==1)
    {
        cout<<"Date of Birth Registered Successfully\n"<<endl;
        break;
    }
    else
        cout<<"ERROR!!\nPlease, Enter your Date of Birth again: ";
   }
}
/*Checking Validation of Aadhaar Number.*/
void Sign_in::check_Aadhaar_No()
{
    int flag;
    /*Should be of 12 digits and contain digits only.And if not then user had to enter the aadhaar number again until he/she enters the aadhaar number in correct form.*/
    while(1)
    {
    if(strlen(Aadhaar_No)==12)
    {
    for(int index=0;index<12;index++)
    {
        flag=0;
        if(Aadhaar_No[index]>=48 && Aadhaar_No[index]<=57)
        {
            flag=1;
        }
    }
    }
    else
       flag=0;
    if(flag==0)
    {
        cout<<"ERROR!!\nPlease, Enter your Aadhaar Number again: ";
        cin>>Aadhaar_No;
    }
    else
    {
        cout<<"Aadhaar Number Registered Successfully\n"<<endl;
        break;
    }
    }
}
/*Checking Validation of Phone Number.*/
void Sign_in::check_Phone_No()
{
    int flag;
    /*Should be of 10 digits and contain digits only.And if not then user had to enter the phone number again until he/she enters the phone number in correct form.*/
    while(1)
    {
    if(Phone_No.length()==10)
    {
    for(int index=0;index<Phone_No.length();index++)
    {
        flag=0;
        if(Phone_No[index]>=48 && Phone_No[index]<=57)
        {
            flag=1;
        }
    }
    }
    else
        flag=0;
    if(flag==0)
    {
        cout<<"ERROR!!\nPlease, Enter your Phone Number again: ";
        cin>>Phone_No;
    }
    else
    {
        cout<<"Phone Number Registered Successfully\n"<<endl;
        break;
    }
    }
}
/*Checking Validation of email id.*/
void Sign_in::check_email_id()
{
    int index;
while (1)
{
    int flag1=1,flag2=1,count1=0,count2=0;

cin>>email_id;
if(email_id[0]=='@')
{
   flag1=0;
   flag2=0;
}
else
    {
for (index=0; index<email_id.length();index++)
{
if (email_id[index]!='@')
{
continue;
}
   else
   {
index++;
if(email_id[index]!='.')
{
              if(((email_id[index]>=65 && email_id[index]<=90)|| (email_id[index]>=97 && email_id[index] <=122))&&(email_id[index]!='@'))
continue;
              else
                flag1=0;
}
   else
   {
    index++;
     if (((email_id[index]>=65 && email_id[index]<=90)|| (email_id[index]>=97 && email_id[index] <=122))&&(email_id[index]!='@'))
   continue;
              else
                flag2=0;
       }
     }
        }
      }

       for(int index=0;index<email_id.length();index++)
        {
            if(email_id[index]=='@')
                count1++;
            if(email_id[index]=='.')
                count2++;
        }

        if(flag1==1 && flag2==1 && count1==1 && count2>=1)
        {
          cout<<"Email id Registered Successfully"<<endl;
          break;
   }
   else
        {
        cout<<"ERROR!!\nPlease, Enter your Email id again: "<<endl;
        }
    }
}
/*Child Class of Sign_in class. */
class log_in : public Sign_in
{
    /*Data members and methods. */
    string Email_id;
    public:
    void Enter_email(log_in l[],int n);
    void Enter_password(log_in l[],int i);
};
/*Function for input of email at the time of logging in.*/
void log_in::Enter_email(log_in l[],int n)
{
    /*Applying loop for searching that entered email id is already present i.e registered in the community or not ? if YES then will move to the further procedure to login in and if NO then will ask for  your choice. */
    while(1)
    {
        int flag=0;
        cout<<"\n-------------LOGIN PAGE-------------\n";
        cout<<"Enter User Email Id : ";
        cin>>Email_id;//Inputting email.

        int index;
        /*Here, we are searching for the entered email id.*/
        for(index=0;index<n;index++)
        {
            /*This will check that entered email id is already registered or not if not then user will enter the id again until he/she enter the registered email id.*/
            if(l[index].email_id==Email_id)
            {
                flag=1;
                //Calling function Enter_password(l,i).
                Enter_password(l,index);
            }
        }
        /*Asking for Choice.*/
        if(flag==0)
        {
            cout<<"\n-----------NO MATCH FOUND-----------\n";
            cout<<"Press 1. To enter email again.\nPress Any Key. To exit page.\n";
            cin>>flag;
            /*Condition for exiting the page.*/
            if(flag!=1)
                exit(0);
        }
    }
}
/*Function for input of Password at the time of logging in.*/
void log_in::Enter_password(log_in l[],int index)
{
    int choice;
    char KeyAscii,p[10];

    START://LABEL FOR GOTO.
    cout<<"\nPress 1 to Enter USER PASSWORD.\nPress any key to RESET PASSWORD if you have forgotten your password.\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
         cout<<"Enter PASSWORD: ";
         while(1)
         {
             int j;
         for(j=0;j<10;j++)
         {
            KeyAscii=getch();
             p[j]=KeyAscii;
             if(KeyAscii!=13)
             {
                cout<<"*";
             }
             if(KeyAscii==13)
                break;
         }
         p[j]='\0';
         cout<<"\n";
         /*Comparing Entered Password and Registered Password.*/
         if(strcmp(l[index].password,p)==0)
        {
            cout<<"\n-----------------LOGIN SUCCESSFULL:)-----------------\n";
            cout<<"----------WELCOME TO SOAR HIGH COMMUNITY-------------\n\n";
            cout<<"Press any key to exit..\n";
            exit(0);
        }
        else
        {
            int flag=0;
            cout<<"DO YOU REMEMBER THE PASSWORD ? if YES then you can again enter the password for That PRESS 1 but if you have FORGOTTEN the password then PRESS 2 TO GO TO THE SETTING OF RESET PASSWORD then PRESS ANY KEY TO RESET IT..\n";
            cin>>flag;
            if(flag==2)
              goto START;
        }
        }
        break;

        default:
          string AN;
          cout<<"Enter Aadhaar Number to RESET PASSWORD: ";
          cin>>AN;

          if(AN==l[index].Aadhaar_No)
          {
             cout<<"Enter NEW PASSWORD: ";
             Input_Password();
             goto START;
          }
          else
          {
              cout<<"YOUR ID IS LOCKED...NO MORE TRIALS LEFT...EXIT THE WINDOW AND AGAIN OPEN THE PORTAL THEN TRY AGAIN TO LOGIN....\n";
              cout<<"---------BETTER LUCK NEXT TIME----------\n";
              exit(0);
          }
          break;

   }
}
/*Main Function*/
int main()
{
    int n,flag;
    /*Asking for input of number of people to be registered in the community. */
    cout<<"Enter the number of user to be registered: ";
    cin>>n;
    cin.ignore();
    /*Making Array of objects of child class log_in of size n which is number of people to be registered in the community. */
    log_in l[n];
    for(int index=0;index<n;index++)
    {
        while(1)
        {
        cout<<"ENTER 1 : FOR ENTRY IN LOGIN PAGE OR ENTER 2 : FOR EXIT FROM LOGIN PAGE\n";
        cin>>flag;
        if(flag==1)
        {
            l[index].Enter_email(l,n);
            break;
        }
        else if(flag==2)
            break;
        else
            cout<<"WRONG INPUT...ENTER AGAIN!!\n";
        if(flag==2)
            break;
        }
    }
    return 0;
}
