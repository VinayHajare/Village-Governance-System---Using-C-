/**
  PROJECT TITLE - Village Governance System
  Version - 2.0
  LANGUAGE USED - C++
  IDE USED      - Code::Blocks
  PLATFORM USED - Windows 11 64-Bit Architecture
  CREATED BY    - Vinay Arjun Hajare
*/

#include<iostream>
#include<windows.h>
#include<string.h>
#include<vector>
#include<fstream>
#include<nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Village
{
   public:
         int id,primary_school,secondary_school,PHC,PDS;

         string any,name,address,transportation_infra,water_res_infra,banking_communication_infra,remark;

         long int population,f_population,m_population,literate_people,illiterate_people,BPL,APL,teen_population,young_population,old_population,area,farming_land,non_farming_land,SM_farmer,LM_farmer;

         float rate_of_immunization,death_ratio,birth_ratio,literacy_rate;


         void show_details(void);

         void edit_details(void);

         void list_villages(void);


};

// Vector to store Village objects
vector<Village> villages;

// Function to load data from JSON file
void loadDataFromFile(void){
    system("cls");
    system("color 02");
    villages.clear(); // Clear the existing data

    ifstream file("villages_data.json");
        if (file.is_open()) {
        json data;
        try {
            file >> data; // Read JSON data from the file
            for (const auto& villageData : data) {
                Village village;
                village.id = villageData["id"];
                village.name = villageData["name"];
                village.address = villageData["address"];
                village.primary_school = villageData["primarySchool"];
                village.secondary_school = villageData["secondarySchool"];
                village.PHC = villageData["PHC"];
                village.BPL = villageData["BPL"];
                village.APL = villageData["APL"];
                village.PDS = villageData["PDS"];
                village.transportation_infra = villageData["transportationInfra"];
                village.water_res_infra = villageData["waterResInfra"];
                village.banking_communication_infra = villageData["bankingCommunicationInfra"];
                village.population = villageData["population"];
                village.m_population = villageData["malePopulation"];
                village.f_population = villageData["malePopulation"];
                village.literate_people = villageData["literatePepole"];
                village.illiterate_people = villageData["illiteratePeople"];
                village.teen_population = villageData["teenPopulation"];
                village.young_population = villageData["youngPopulation"];
                village.old_population = villageData["oldPopulation"];
                village.area = villageData["area"];
                village.farming_land = villageData["farmingLand"];
                village.non_farming_land = villageData["nonFarmingLand"];
                village.SM_farmer = villageData["smFarmer"];
                village.LM_farmer = villageData["lmFarmer"];
                village.rate_of_immunization = villageData["rateOfImmunization"];
                village.death_ratio = villageData["deathRatio"];
                village.birth_ratio = villageData["birthRatio"];
                village.literacy_rate = villageData["literacyRate"];
                village.remark = villageData["remark"];
                villages.push_back(village);
            }
            cout << "Data loaded from file." << endl;
        } catch (json::parse_error& e) {
            cerr << "Error: Unable to parse JSON data. " << e.what() << endl;
        }
        file.close();
    } else {
        // Create a new JSON file if it doesn't exist
        ofstream newFile("villages_data.json");
        if (newFile.is_open()) {
            cout << "Data file created." << endl;
            newFile.close();
        } else {
            cerr << "Error: Unable to create data file." << endl;
        }
    }
    Sleep(1000);
    system("cls");
}

// Function to save data to JSON file
void saveDataToFile(void){
    system("cls");
    system("color 02");
    json data;

    for(const Village& village : villages){
        json villageData;
        villageData["id"] = village.id;
        villageData["name"] = village.name;
        villageData["address"] = village.address;
        villageData["primarySchool"] = village.primary_school;
        villageData["secondarySchool"] = village.secondary_school;
        villageData["PHC"] = village.PHC;
        villageData["BPL"] = village.BPL;
        villageData["APL"] = village.APL;
        villageData["PDS"] = village.PDS;
        villageData["transportationInfra"] = village.transportation_infra;
        villageData["waterResInfra"] = village.water_res_infra;
        villageData["bankingCommunicationInfra"] = village.banking_communication_infra;
        villageData["population"] = village.population;
        villageData["malePopulation"] = village.m_population;
        villageData["malePopulation"] = village.f_population;
        villageData["literatePepole"] = village.literate_people;
        villageData["illiteratePeople"] = village.illiterate_people;
        villageData["teenPopulation"] = village.teen_population;
        villageData["youngPopulation"] = village.young_population;
        villageData["oldPopulation"]  = village.old_population;
        villageData["area"] = village.area;
        villageData["farmingLand"] = village.farming_land;
        villageData["nonFarmingLand"] = village.non_farming_land;
        villageData["smFarmer"] = village.SM_farmer;
        villageData["lmFarmer"]= village.LM_farmer;
        villageData["rateOfImmunization"] = village.rate_of_immunization;
        villageData["deathRatio"] = village.death_ratio;
        villageData["birthRatio"] = village.birth_ratio;
        villageData["literacyRate"] = village.literacy_rate;
        villageData["remark"] = village.remark;
        data.push_back(villageData);
    }

    ofstream file("villages_data.json");
    if (file.is_open()) {
        file << data.dump(4); // Save JSON data with indentation for readability
        file.close();
        cout << "Data saved to file." << endl;
    } else {
        cerr << "Error: Unable to save data to file." << endl;
    }
    Sleep(1000);
    system("cls");
}

// Function to add village details
void add_village(void)
{
  Village village;
  system("cls");
  cout<<"\t\t\t\t================================================\n";
  cout<<"\t\t\t\t\tBasic Details of Village\n";
  cout<<"\t\t\t\t================================================\n";
  cout<<"\n\tEnter Village Id :";
  cin>>village.id;
  getline(cin,village.any);
  cout<<"\n\tEnter Village Name : ";
  getline(cin,village.name);
  cout<<"\n\tEnter Village Address : ";
  getline(cin,village.address);
  cout<<"\n\tEnter number of primary and secondary schools in the village: ";
  cin>>village.primary_school>>village.secondary_school;
  cout<<"\n\tEnter the number of primary health care center in the village : ";
  cin>>village.PHC;
  cout<<"\n\tEnter the number of people Below Poverty Line : ";
  cin>>village.BPL;
  cout<<"\n\tEnter the number of people Above Poverty Line : ";
  cin>>village.APL;
  cout<<"\n\tEnter the number of PDS Fair Price Shop :";
  cin>>village.PDS;
  getline(cin,village.any);
  cout<<"\n\tEnter the condition of transportation infrastructure in the village :";
  getline(cin,village.transportation_infra);
  cout<<"\n\tEnter the condition of Water Resoureces in the village :";
  getline(cin,village.water_res_infra);
  cout<<"\n\tEnter the condition of Banking and Communication infrastructure in the village :";
  getline(cin,village.banking_communication_infra);
  cout<<endl;
  cout<<"\t\t\t\t================================================\n";
  cout<<"\t\t\t\t\tDemographic Data of Village\n";
  cout<<"\t\t\t\t================================================\n";
  cout<<"\n\tEnter the Population of village :";
  cin>>village.population;
  cout<<"\n\tEnter the Male Population of Village :";
  cin>>village.m_population;
  cout<<"\n\tEnter the Female Population of Village :";
  cin>>village.f_population;
  cout<<"\n\tEnter the number of Literate and Illiterate peoples in the village : ";
  cin>>village.literate_people>>village.illiterate_people;
  cout<<"\n\tEnter the number of Teenagers in the Village :";
  cin>>village.teen_population;
  cout<<"\n\tEnter the number of Youngster in the Village :";
  cin>>village.young_population;
  cout<<"\n\tEnter the number of Old peoples in the Village :";
  cin>>village.old_population;
  cout<<endl;
  cout<<"\t\t\t\t================================================\n";
  cout<<"\t\t\t\t\tGeographical Details of Village\n";
  cout<<"\t\t\t\t================================================\n";
  cout<<"\n\tEnter the Area of Village : ";
  cin>>village.area;
  cout<<"\n\tEnter the Area of farming Land & Non-farming Land in the village :";
  cin>>village.farming_land>>village.non_farming_land;
  cout<<"\n\tEnter the population of Small Marginal Farmers and Large Marginal Farmers :";
  cin>>village.SM_farmer>>village.LM_farmer;
  cout<<endl;
  cout<<"\t\t\t\t================================================\n";
  cout<<"\t\t\t\t\tImportant ratios of Village\n";
  cout<<"\t\t\t\t================================================\n";
  cout<<"\n\tEnter the rate of immunization in the village :";
  cin>>village.rate_of_immunization;
  cout<<"\n\tEnter the Death ratio of the village :";
  cin>>village.death_ratio;
  cout<<"\n\tEnter the Birth ratio of the village :";
  cin>>village.birth_ratio;
  cout<<"\n\tEnter the Literacy ratio of the village :";
  cin>>village.literacy_rate;
  getline(cin,village.any);
  cout<<"\n\tRemarks :";
  getline(cin,village.remark);
  cout<<endl;
  villages.push_back(village);
  cout<<"\n\n\n\n\t\t\t\t Village details added successfully!"<<endl;
  Sleep(1000);
  system("cls");
}

// Function to display details of village
void show_details(void)
{
 system("cls");
 int id;
 cout<<"Enter the village Id of which you want to see details :";
 cin>>id;
 for(const Village& village : villages)
  {
  	if(village.id == id )
  	{
  	 cout<<"\t\t\t\t================================================\n";
     cout<<"\t\t\t\t\tBasic Details of Village\n";
     cout<<"\t\t\t\t================================================\n";
     cout<<"\n\tVillage id : "<<village.id;
     cout<<"\n\tVillage Name : "<<village.name;
     cout<<"\n\tVillage Address : "<<village.address;
     cout<<"\n\tNumber of primary Schools in the village : "<<village.primary_school;
     cout<<"\n\tNumber of Secondary Schools village : "<<village.secondary_school;
     cout<<"\n\tNumber of Primary Health Care(PHC) in the village : "<<village.PHC;
     cout<<"\n\tPeoples Above Poverty Line(APL) in the village : "<<village.APL;
     cout<<"\n\tPeoples Below Poverty Line(BPL) in the village : "<<village.BPL;
     cout<<"\n\tNumber of Public Distribution System Fair Price Shop : "<<village.PDS;
     cout<<"\n\tCondition of transportation infrastructure in the village : "<<village.transportation_infra;
     cout<<"\n\tCondition of Water Resources in the village : "<<village.water_res_infra;
     cout<<"\n\tCondition of Banking and Communication infrastructure in the village : "<<village.banking_communication_infra;
     cout<<endl;
     cout<<"\t\t\t\t================================================\n";
     cout<<"\t\t\t\t\tDemographic Data of Village\n";
     cout<<"\t\t\t\t================================================\n";
     cout<<"\n\tTotal Population of village : "<<village.population;
     cout<<"\n\tMale Population of village : "<<village.m_population;
     cout<<"\n\tFemale Population of village : "<<village.f_population;
     cout<<"\n\tTotal number of Teenagers in the village : "<<village.teen_population;
     cout<<"\n\tTotal number of Youngsters in the village : "<<village.young_population;
     cout<<"\n\tTotal number of Old peoples in the village : "<<village.old_population;
     cout<<"\n\tTotal number of literate peoples in the village : "<<village.literate_people;
     cout<<"\n\tTotal number of Illiterate peoples in the village : "<<village.illiterate_people;
     cout<<endl;
     cout<<"\t\t\t\t================================================\n";
     cout<<"\t\t\t\t\tGeographical Details of Village\n";
     cout<<"\t\t\t\t================================================\n";
     cout<<"\n\tTotal area of village : "<<village.area;
     cout<<"\n\tArea of Farming land in the village :  "<<village.farming_land;
     cout<<"\n\tArea of Non-farming land in the village : "<<village.non_farming_land;
     cout<<"\n\tTotal number of Large Marginal farmers in the village : "<<village.LM_farmer;
     cout<<"\n\tTotal number of Small Marginal farmers in the village : "<<village.SM_farmer;
     cout<<endl;
     cout<<"\t\t\t\t================================================\n";
     cout<<"\t\t\t\t\tImportant ratios of Village\n";
     cout<<"\t\t\t\t================================================\n";
     cout<<"\n\tRate of immunization in the village : "<<village.rate_of_immunization;
     cout<<"\n\tDeath ratio of the village : "<<village.death_ratio;
     cout<<"\n\tBirth ratio of the village : "<<village.birth_ratio;
     cout<<"\n\tLiteracy ratio of the village : "<<village.literacy_rate;
     cout<<"\n\tRemarks about village  : "<<village.remark;
     cout<<endl;
     return;
	}
  }
}

// Function to modify details of village
void edit_details(void)
{
system("cls");
 int id, ch;
  cout<<"Enter the village I'd of which you want to edit details : ";
  cin>>id;
  for(Village& village : villages)
   {
     if(village.id == id)
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
             getline(cin,village.name);
             cout<<"\n\tEnter Village Address : ";
             getline(cin,village.address);
             cout<<"\n\tEnter number of primary and secondary schools in the village: ";
             cin>>village.primary_school>>village.secondary_school;
             cout<<"\n\tEnter the number of primary health care center in the village : ";
             cin>>village.PHC;
             cout<<"\n\tEnter the number of people Below Poverty Line : ";
             cin>>village.BPL;
             cout<<"\n\tEnter the number of people Above Poverty Line : ";
             cin>>village.APL;
             cout<<"\n\tEnter the number of PDS Fair Price Shop :";
             cin>>village.PDS;
             cout<<"\n\tEnter the condition of transportation infrastructure in the village :";
             getline(cin,village.transportation_infra);
             cout<<"\n\tEnter the condition of Water Resoureces in the village :";
             getline(cin,village.water_res_infra);
             cout<<"\n\tEnter the condition of Banking and Communication infrastructure in the village :";
             getline(cin,village.banking_communication_infra);

           case 2:
             cout<<"\t\t\t\t================================================\n";
             cout<<"\t\t\t\t\tDemographic Data of Village\n";
             cout<<"\t\t\t\t================================================\n";
             cout<<"\n\tEnter the Population of village :";
             cin>>village.population;
             cout<<"\n\tEnter the Male Population of Village :";
             cin>>village.m_population;
             cout<<"\n\tEnter the Female Population of Village :";
             cin>>village.f_population;
             cout<<"\n\tEnter the number of Literate and Iliterate peoples in the village : ";
             cin>>village.literate_people>>village.illiterate_people;
             cout<<"\n\tEnter the number of Teenagers in the Village :";
             cin>>village.teen_population;
             cout<<"\n\tEnter the number of Youngster in the Village :";
             cin>>village.young_population;
             cout<<"\n\tEnter the number of Old peoples in the Village :";
             cin>>village.old_population;

           case 3:
             cout<<"\t\t\t\t================================================\n";
             cout<<"\t\t\t\t\tGeographical Details of Village\n";
             cout<<"\t\t\t\t================================================\n";
             cout<<"\n\tEnter the Area of Village : ";
             cin>>village.area;
             cout<<"\n\tEnter the Area of farming Land & Non-farming Land in the village :";
             cin>>village.farming_land>>village.non_farming_land;
             cout<<"\n\Enter the population of Small Marginal Farmers and Large Marginal Farmers :";
             cin>>village.SM_farmer>>village.LM_farmer;

           case 4:
             cout<<"\t\t\t\t================================================\n";
             cout<<"\t\t\t\t\tImportant ratios of Village\n";
             cout<<"\t\t\t\t================================================\n";
             cout<<"\n\tEnter the rate of immunization in the village :";
             cin>>village.rate_of_immunization;
             cout<<"\n\tEnter the Death ratio of the village :";
             cin>>village.death_ratio;
             cout<<"\n\tEnter the Birth ratio of the village :";
             cin>>village.birth_ratio;
             cout<<"\n\tEnter the Literacy ratio of the village :";
             cin>>village.literacy_rate;
          }
          saveDataToFile();
          return;
        }
   }

}

// Function to enlist villages in the database
void list_villages(void)//function for listing the name of villages in the system
{
  system("cls");
  cout<<"====================================\n";
  cout<<"| Village I'd   |  Village Name    |\n";
  cout<<"====================================\n";
 for(Village& village : villages)
 {
  cout<<"| "<<village.id<<"             | "<<village.name<<"          |\n";
  cout<<"====================================\n";
 }
}

// Function to remove village from the system
void remove_village(void)
{
 system("cls");
 int id;
 cout<<"Enter the village Id of which you want to remove details :";
 cin>>id;

 for(auto it = villages.begin();it!=villages.end();++it){
    if(it->id == id){
        villages.erase(it);
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t\tPlease enter a valid choice \n\n\n"<<endl;
        Sleep(1000);
        system("cls");
        saveDataToFile();
        return;
    }
 }
 cout<<"Village details not found. No removal performed."<<endl;
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
  loadDataFromFile();
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
     cout<<"\t\t\t\t\t 5] Remove Village"<<endl;
     cout<<"\t\t\t\t\t 6] Exit "<<endl;
     cout<<endl;
     cout<<"\t\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
     cout<<endl;
     cout<<"\t\t\t\t\tEnter your choice : ";
     cin>>choice;
     switch(choice)
     {
      case 1:
        add_village();
        break;

      case 2:
        edit_details();
        break;

      case 3:
        show_details();
        break;

      case 4:
      	list_villages();
      	break;

      case 5:
        remove_village();
        break;

      case 6:
         system("cls");
         saveDataToFile();
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

      default:
         cout<<"\n\n\n\n\n\n\n";
         cout<<"\t\t\t\tPlease enter a valid choice \n\n\n";
         system("cls");
     }

    }while(1);

  return 0;
}

