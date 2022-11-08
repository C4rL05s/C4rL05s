#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

typedef int *IntPtr;
const int LABS = 4;
int lab_size[] = {5, 6, 4, 3};


class ComputerLab
{

public:
    int ID, lab, station;
    

    ComputerLab(){}
    
    
    IntPtr Labs[LABS];
    
    void createStructure();
    void printLabs();
    void login();
    void logOff(); 
    void searchUser(int myID); 
    int printMenu(int myOpt);

};


int main()
{   
    ComputerLab myLab; 
    int opt;

    myLab.createStructure();
    myLab.printMenu(opt);
   
    
    return 0;
}


void ComputerLab::createStructure() //creates the structure for the lab station's status 
{                                   //also sets value of stations to 0

 

    for (int i = 0; i < LABS; i++)
        Labs[i] = new int[lab_size[i]];

    for (int i = 0; i < LABS; i++)
    {

        for (int k = 0; k < lab_size[i]; k++)
        {
            
            Labs[i][k] = 0;
        }
    }
}

void ComputerLab::printLabs() // prints the lab number with its stations and user ID (if there is one)
{

    cout << endl;
    cout << "Labs" << setw(15) << "Stations" << endl;

    for (int i = 0; i < LABS; i++)
    {
        cout << endl;
        cout << "Lab#" << i + 1 << setw(8);
        for (int k = 0; k < lab_size[i]; k++)
        {
            if (Labs[i][k] == 0){
                cout << k + 1 << ". " << "empty" << "   "; 
            } else {
                cout << k + 1 << ". " << Labs[i][k] << "   "; 
            }
            //cout << k + 1 << ". " << Labs[i][k] << "   ";
        }        
    }
    cout << endl; 
}

void ComputerLab::login() //sets the ID to the specific Lab and station/ will implement future dynamic array here
{
    
    
        cout << "Please enter your ID: "; 
            cin >> ID; 
        cout << endl; 

        cout << "Please enter the lab to join: ";
            cin >> lab; 
        cout << endl; 

        cout << "Please enter station: "; 
            cin >> station; 
        cout << endl;  

        Labs[lab - 1][station - 1] = ID; //logs info into user, used to search the user and login to a station 

             printLabs();
             cout << endl;
}

int ComputerLab::printMenu(int myOpt){
        //Here are all the options for the program 
         
    do {
        
        
         cout << "Welcome to the Computer Lab" << endl; 
        cout << "1. Login\n2. Search User\n3. View Connected\n4. Log Off\n5. Exit" << endl;
        cout << "Enter option(Ex: \"1\"): "; 
            cin >> myOpt; 
        
        

        switch(myOpt){
            case 1: //Login option
                cout << "======Login Page======" << endl;
                login(); //call to login function 
                break;

            case 2: //Search User by ID
                cout << "======Search User=====" << endl;
                cout << "Please enter user's 5-digit ID: "; 
                 cin >> ID;
                searchUser(ID);  
                break;

            case 3: //Displays all values/ID's in all stations 
                cout << "======View Connected======" << endl;
                printLabs(); 
                    cout << endl;  
                break;

             case 4: //Sets the value of specified ID to 0 "logging off"
                cout << "======Log Off======" << endl; 
                logOff(); 
                
                break;

             default: //Any number >1 or <5 will cause the program to exit 
                cout << "EXITING" << endl; 
        }
        
    } while (myOpt != 5);
       
        return myOpt; 
}

void ComputerLab::searchUser(int myID){

    //searches for inputted ID and displays in which Lab and station the value is stored

    bool flag = false; 
    
    cout << endl; 
    cout << "=====Searching User=====" << endl << endl; 
    

    for(int i = 0; i < LABS; i++){
        for(int k = 0; k < lab_size[i]; k++){ //searches through array to find ID inputted/user
            if (Labs[i][k] == myID){
                    flag = true; 
                        if (flag == true){
                            cout << "User found in Lab#" << i + 1 << " station #" << k + 1 << endl << endl; 
                                cout << "=====EOF=====" << endl << endl;  
                        } else if (flag != true) {
                            flag = false; 
                            cout << "User not found :(" << endl;
                        }
            } else {
                flag = false; 
            }   
        }
    }
}

void ComputerLab::logOff(){

        int tmpID; 
        bool flag = false; 
        cout << "Enter ID of the user you want to log off: "; 
        cin >> tmpID; 

            for(int i = 0; i < LABS; i++){
        for(int k = 0; k < lab_size[i]; k++){ //searches through array to find ID inputted/user
            if (Labs[i][k] == tmpID){
                    flag = true; 
                        if (flag == true){
                            Labs[i][k] = 0; //if flag is true then selected ID will = 0
                            printLabs(); 
                            cout << "Logged Off..." << endl << endl; 
                        } else if (flag == false){
                            flag = false; //No supe como implementar este mensaje de error
                            cout << "User not found :(" << endl;
                            printLabs(); 
                        }
            } else {
                flag = false; //if previous error message is placed here it appears many times
            }                   //and I did not like that
        }
    }
}