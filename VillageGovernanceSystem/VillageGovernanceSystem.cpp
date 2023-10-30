/**
  PROJECT TITLE - Village Governance System
  Version - 2.0
  LANGUAGE USED - C++
  IDE USED      - Code::Blocks
  PLATFORM USED - Windows 10 64-Bit Architecture
  CREATED BY    - Vinay Arjun Hajare
*/
#include<iostream>
#include<windows.h>
#include<string.h>
#include<nlohmann/json.hpp>

using namespace std;
static int i=1; //For storing number of villages in the system

using namespace std;
class village
{
   private:
         int village_id,primary_school,secondary_school,PHC,PDS;

         char any[10],village_name[25],village_address[25],transportation_infra[45],water_res_infra[45],banking_communication_infra[45],remark[50];

         long int population,f_population,m_population,literate_people,illiterate_people,BPL,APL,teen_population,young_population,old_population,area,farming_land,non_farming_land,SM_farmer,LM_farmer;

         float rate_of_immunization,death_ratio,birth_ratio,literacy_rate;

   public:
         void add_village(void);//function to add village details
         void show_details(void);//function to display details of village
         void edit_details(void);//function to modify details of village
         void list_villages(void);//function to enlist villages in the database

}p[50];

void village::add_village(void)
{
  system("cls");
  cout<<"\t\t\t\t================================================\n";
  cout<<"\t\t\t\t\tBasic Details of Village\n";
  cout<<"\t\t\t\t================================================\n";
  cout<<"\n\tEnter Village Id :";
  cin>>p[i].village_id;
  cin.getline(p[i].any,10);
  cout<<"\n\tEnter Village Name : ";
  cin.getline(p[i].village_name,25);
  cout<<"\n\tEnter Village Address : ";
  cin.getline(p[i].village_address,25);
  cout<<"\n\tEnter number of primary and secondary schools in the village: ";
  cin>>p[i].primary_school>>p[i].secondary_school;
  cout<<"\n\tEnter the number of primary health care center in the village : ";
  cin>>p[i].PHC;
  cout<<"\n\tEnter the number of people Below Poverty Line : ";
  cin>>p[i].BPL;
  cout<<"\n\tEnter the number of people Above Poverty Line : ";
  cin>>p[i].APL;
  cout<<"\n\tEnter the number of PDS Fair Price Shop :";
  cin>>p[i].PDS;
  cin.getline(p[i].any,10);
  cout<<"\n\tEnter the condition of transportation infrastructure in the village :";
  cin.getline(p[i].transportation_infra,35);
  cout<<"\n\tEnter the condition of Water Resoureces in the village :";
  cin.getline(p[i].water_res_infra,35);
  cout<<"\n\tEnter the condition of Banking and Communication infrastructure in the village :";
  cin.getline(p[i].banking_communication_infra,35);
  cout<<endl;
  cout<<"\t\t\t\t================================================\n";
  cout<<"\t\t\t\t\tDemographic Data of Village\n";
  cout<<"\t\t\t\t================================================\n";
  cout<<"\n\tEnter the Population of village :";
  cin>>p[i].population;
  cout<<"\n\tEnter the Male Population of Village :";
  cin>>p[i].m_population;
  cout<<"\n\tEnter the Female Population of Village :";
  cin>>p[i].f_population;
  cout<<"\n\tEnter the number of Literate and Illiterate peoples in the village : ";
  cin>>p[i].literate_people>>p[i].illiterate_people;
  cout<<"\n\tEnter the number of Teenagers in the Village :";
  cin>>p[i].teen_population;
  cout<<"\n\tEnter the number of Youngster in the Village :";
  cin>>p[i].young_population;
  cout<<"\n\tEnter the number of Old peoples in the Village :";
  cin>>p[i].old_population;
  cout<<endl;
  cout<<"\t\t\t\t================================================\n";
  cout<<"\t\t\t\t\tGeographical Details of Village\n";
  cout<<"\t\t\t\t================================================\n";
  cout<<"\n\tEnter the Area of Village : ";
  cin>>p[i].area;
  cout<<"\n\tEnter the Area of farming Land & Non-farming Land in the village :";
  cin>>p[i].farming_land>>p[i].non_farming_land;
  cout<<"\n\tEnter the population of Small Marginal Farmers and Large Marginal Farmers :";
  cin>>p[i].SM_farmer>>LM_farmer;
  cout<<endl;
  cout<<"\t\t\t\t================================================\n";
  cout<<"\t\t\t\t\tImportant ratios of Village\n";
  cout<<"\t\t\t\t================================================\n";
  cout<<"\n\tEnter the rate of immunization in the village :";
  cin>>p[i].rate_of_immunization;
  cout<<"\n\tEnter the Death ratio of the village :";
  cin>>p[i].death_ratio;
  cout<<"\n\tEnter the Birth ratio of the village :";
  cin>>p[i].birth_ratio;
  cout<<"\n\tEnter the Literacy ratio of the village :";
  cin>>p[i].literacy_rate;
  cin.getline(p[i].any,10);
  cout<<"\n\tRemarks :";
  cin.getline(remark,40);
  cout<<endl;
  i++;
  system("cls");
}

void village::show_details(void)
{
 system("cls");
 int id;
  cout<<"Enter the village I'd of which you want to see details :";
  cin>>id;
  for(int j;j<i;j++)
  {
  	if(p[j].village_id == id )
  	{
  	 cout<<"\t\t\t\t================================================\n";
     cout<<"\t\t\t\t\tBasic Details of Village\n";
     cout<<"\t\t\t\t================================================\n";
     cout<<"\n\tVillage id : "<<p[j].village_id;
     cout<<"\n\tVillage Name : "<<p[j].village_name;
     cout<<"\n\tVillage Address : "<<p[j].village_address;
     cout<<"\n\tNumber of primary Schools in the village : "<<p[j].primary_school;
     cout<<"\n\tNumber of Secondary Schools village : "<<p[j].secondary_school;
     cout<<"\n\tNumber of Primary Health Care(PHC) in the village : "<<p[j].PHC;
     cout<<"\n\tPeoples Above Poverty Line(APL) in the village : "<<p[j].APL;
     cout<<"\n\tPeoples Below Poverty Line(BPL) in the village : "<<p[j].BPL;
     cout<<"\n\tNumber of Public Distribution System Fair Price Shop : "<<p[j].PDS;
     cout<<"\n\tCondition of transportation infrastructure in the village : "<<p[j].transportation_infra;
     cout<<"\n\tCondition of Water Resources in the village : "<<p[j].water_res_infra;
     cout<<"\n\tCondition of Banking and Communication infrastructure in the village : "<<p[j].banking_communication_infra;
     cout<<endl;
     cout<<"\t\t\t\t================================================\n";
     cout<<"\t\t\t\t\tDemographic Data of Village\n";
     cout<<"\t\t\t\t================================================\n";
     cout<<"\n\tTotal Population of village : "<<p[j].population;
     cout<<"\n\tMale Population of village : "<<p[j].m_population;
     cout<<"\n\tFemale Population of village : "<<p[j].f_population;
     cout<<"\n\tTotal number of Teenagers in the village : "<<p[j].teen_population;
     cout<<"\n\tTotal number of Youngsters in the village : "<<p[j].young_population;
     cout<<"\n\tTotal number of Old peoples in the village : "<<p[j].old_population;
     cout<<"\n\tTotal number of literate peoples in the village : "<<p[j].literate_people;
     cout<<"\n\tTotal number of Illiterate peoples in the village : "<<p[j].illiterate_people;
     cout<<endl;
     cout<<"\t\t\t\t================================================\n";
     cout<<"\t\t\t\t\tGeographical Details of Village\n";
     cout<<"\t\t\t\t================================================\n";
     cout<<"\n\tTotal area of village : "<<p[j].area;
     cout<<"\n\tArea of Farming land in the village :  "<<p[i].farming_land;
     cout<<"\n\tArea of Non-farming land in the village : "<<p[j].non_farming_land;
     cout<<"\n\tTotal number of Large Marginal farmers in the village : "<<p[j].LM_farmer;
     cout<<"\n\tTotal number of Small Marginal farmers in the village : "<<p[j].SM_farmer;
     cout<<endl;
     cout<<"\t\t\t\t================================================\n";
     cout<<"\t\t\t\t\tImportant ratios of Village\n";
     cout<<"\t\t\t\t================================================\n";
     cout<<"\n\tRate of immunization in the village : "<<p[j].rate_of_immunization;
     cout<<"\n\tDeath ratio of the village : "<<p[j].death_ratio;
     cout<<"\n\tBirth ratio of the village : "<<p[j].birth_ratio;
     cout<<"\n\tLiteracy ratio of the village : "<<p[j].literacy_rate;
     cout<<"\n\tRemarks about village  : "<<p[j].remark;
     cout<<endl;
	}
  }
}

void village::edit_details(void)
{
system("cls");
 int n, ch;
  cout<<"Enter the village I'd of which you want to edit details : ";
  cin>>n;
  for(int b=1;b<i;b++)
   {
     if(p[b].village_id == n)
        {
         cout<<"\nEnter which details you want to edit :\n";
         cout<<"1] Basic Details\n";
         cout<<"2] Demographic Data\n";
         cout<<"3] Geographical Details\n";
         cout<<"4] Important Ratios\n";
         cin>>ch;
         switch(ch)
          {
           case 1:
             cout<<"\t\t\t\t================================================\n";
             cout<<"\t\t\t\t\tBasic Details of Village\n";
             cout<<"\t\t\t\t================================================\n";
             cout<<"\n\tEnter Village Name : ";
             cin.getline(p[b].village_name,25);
             cout<<"\n\tEnter Village Address : ";
             cin.getline(p[b].village_address,25);
             cout<<"\n\tEnter number of primary and secondary schools in the village: ";
             cin>>p[b].primary_school>>p[b].secondary_school;
             cout<<"\n\tEnter the number of primary health care center in the village : ";
             cin>>p[b].PHC;
             cout<<"\n\tEnter the number of people Below Poverty Line : ";
             cin>>p[b].BPL;
             cout<<"\n\tEnter the number of people Above Poverty Line : ";
             cin>>p[b].APL;
             cout<<"\n\tEnter the number of PDS Fair Price Shop :";
             cin>>p[b].PDS;
             cout<<"\n\tEnter the condition of transportation infrastructure in the village :";
             cin.getline(p[b].transportation_infra,35);
             cout<<"\n\tEnter the condition of Water Resoureces in the village :";
             cin.getline(p[b].water_res_infra,35);
             cout<<"\n\tEnter the condition of Banking and Communication infrastructure in the village :";
             cin.getline(p[b].banking_communication_infra,35);

           case 2:
             cout<<"\t\t\t\t================================================\n";
             cout<<"\t\t\t\t\tDemographic Data of Village\n";
             cout<<"\t\t\t\t================================================\n";
             cout<<"\n\tEnter the Population of village :";
             cin>>p[b].population;
             cout<<"\n\tEnter the Male Population of Village :";
             cin>>p[b].m_population;
             cout<<"\n\tEnter the Female Population of Village :";
             cin>>p[b].f_population;
             cout<<"\n\tEnter the number of Literate and Iliterate peoples in the village : ";
             cin>>p[b].literate_people>>p[b].illiterate_people;
             cout<<"\n\tEnter the number of Teenagers in the Village :";
             cin>>p[b].teen_population;
             cout<<"\n\tEnter the number of Youngster in the Village :";
             cin>>p[b].young_population;
             cout<<"\n\tEnter the number of Old peoples in the Village :";
             cin>>p[b].old_population;

           case 3:
             cout<<"\t\t\t\t================================================\n";
             cout<<"\t\t\t\t\tGeographical Details of Village\n";
             cout<<"\t\t\t\t================================================\n";
             cout<<"\n\tEnter the Area of Village : ";
             cin>>p[b].area;
             cout<<"\n\tEnter the Area of farming Land & Non-farming Land in the village :";
             cin>>p[b].farming_land>>p[b].non_farming_land;
             cout<<"\n\Enter the population of Small Marginal Farmers and Large Marginal Farmers :";
             cin>>p[b].SM_farmer>>LM_farmer;

           case 4:
             cout<<"\t\t\t\t================================================\n";
             cout<<"\t\t\t\t\tImportant ratios of Village\n";
             cout<<"\t\t\t\t================================================\n";
             cout<<"\n\tEnter the rate of immunization in the village :";
             cin>>p[b].rate_of_immunization;
             cout<<"\n\tEnter the Death ratio of the village :";
             cin>>p[b].death_ratio;
             cout<<"\n\tEnter the Birth ratio of the village :";
             cin>>p[b].birth_ratio;
             cout<<"\n\tEnter the Literacy ratio of the village :";
             cin>>p[b].literacy_rate;
          }
        }
   }

}

void village::list_villages(void)//function for listing the name of villages in the system
{
  system("cls");
  cout<<"====================================\n";
  cout<<"| Village I'd   |  Village Name    |\n";
  cout<<"====================================\n";
 for(int a=1;a<i;a++)
 {
  cout<<"| "<<p[a].village_id<<"             | "<<p[a].village_name<<"          |\n";
  cout<<"====================================\n";
 }
}
//function for checking username and password
void security(void)
{
 system("cls");
 system("Color 0B");
 char pass[10]="admin";
 char user[10]="admin";
 char password[10];
 char username[10];
 cout<<"\n\n\t\t\t\t\t\tLogin Please -";
 cout<<"\n\n\n\t\t\t\tEnter Username :";
 cin>>username;
 cout<<endl;
 cout<<"\t\t\t\tEnter Password :";
 cin>>password;
 cout<<endl;
 if(strcmp(username,user)==0 && strcmp(password,pass)==0)
   {
    cout<<"\n\n\n\n\t\t\t\tLogin Successful . . . ."<<endl;
   }
 else
  {
    cout<<"\n\n\n\n\t\t\t\tIncorrect username or password\n";
    exit(0);
  }
}

//Loading function used for starting the system
void loading(void)
{
	system("cls");
    SetConsoleTitle(" Village Governance System ");//setting console title to Village Governance System
    system("Color 04");//setting color of text to red
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t LOADING....\n\n" ;
    cout<<"\t\t\t\t";
    char x = 219;//A Special character printing sequence
    for(int i=0;i<35;i++)
     {
      cout<<x;
      if(i<10)
        Sleep(300);//stops execution of the system for 300 ms
      if(i>=10&&i<20)
        Sleep(150);
      if(i>=10)
        Sleep(25);
     }
  system("cls");//for clearing console
  cout<<"\n\n\n\n";
  system("Color 02");//setting text color to green after loading happens
  cout<<"\t\t\t\t------ WEL-COME TO VILLAGE GOVERENANCE SYSTEM ------- \n\n\n" ;
  Sleep(500);
}

//Driver Code

int main()
{
	security();
    loading();

    do
    {

     int choice;//Storing choice number enter by user
     cout<<"\t\t\t\t\t*-*-*-*-*-*-* MENU *-*-*-*-*-*-*"<<endl;//printing main menu
     cout<<endl;
     cout<<"\t\t\t\t\t 1] Add Village Details"<<endl;
     cout<<"\t\t\t\t\t 2] Edit Village Details"<<endl;
     cout<<"\t\t\t\t\t 3] Show Village Details"<<endl;
     cout<<"\t\t\t\t\t 4] List Villages"<<endl;
     cout<<"\t\t\t\t\t 5] Exit "<<endl;
     cout<<endl;
     cout<<"\t\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
     cout<<endl;
     cout<<"\t\t\t\t\tEnter your choice : ";
     cin>>choice;
     switch(choice)
     {
      case 1:

        p[i].add_village();

        break;

      case 2:
        p[i].edit_details();
        break;

      case 3:
        p[i].show_details();
        break;

      case 4:
      	p[i].list_villages();
      	break;
      case 5:
         system("cls");
         cout<<"\n\n\n\n\n\n\n";
         cout<<"\t\t\t\tPreparing for Exiting The System ...\n\n\n"<<endl;
         system("Color 04");//Again setting color of text to red
         Sleep(1000);
         cout<<"\t\t\t\t EXITING : ";
         for(int i;i<5;i++)
         {
          cout<<" *_* ";
          Sleep(1000);
         }
         cout<<"\n\n\n\n\n";
         exit(0);//Terminating the program execution
         break;
     }

    }while(1);

  return 0;
}

