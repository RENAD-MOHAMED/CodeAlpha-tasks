#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;
void userRegister()
{string name, password, confirmed,line,storedUserName,storedPassword;
    fstream ff;
    ff.open("users.txt",ios::in);
    cout<<"Enter Username: ";
    cin>>name;
             while (getline(ff, line)) { 
             stringstream ss(line);
      ss >> storedUserName >> storedPassword;
         if(name==storedUserName){
             cout<<"username is already taken\n";
             return;
         }
         
             } 
             ff.close();
ff.open("users.txt", ios::out | ios::app);
    cout<<"Enter password: ";
    cin>>password;
    cout<<"confirm password: ";
    cin>>confirmed;
    if (confirmed==password){
        ff << name<<" "<<password<<"\n";
        ff.close();
        cout<<"Registered successfully.\n";
    }
    else {
    cout<<"Erorr registering,password and confirmed password don't match.\n";
    ff.close();
    return;
    }
//ff.close();
}
int login(){
   fstream file;
    file.open("users.txt",ios::in);
    if (!file.is_open()) {
    cout << "Error opening file.\n";
    return 0;
}

    string username,storedUserName;
    string password,storedPassword;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
   string line;
       file.clear(); 
   file.seekg(0); 
         while (getline(file, line)) { 
             stringstream ss(line);
ss >> storedUserName >> storedPassword;
   if(username==storedUserName) {
       if(password==storedPassword){
           cout<<"Login Successfully\n";
           ofstream filee(username+".txt");

    if (filee.is_open()) {
        filee <<username<<" "<<password<< "\n";
       filee.close();
        cout << "File created and written successfully.\n";
    } else {
        cout << "Failed to create the file.\n";
    }
           return 1;
       }
       else 
       {
           cout<<"incorrect password \n";
           return 0;
       }}}
      if (username!=storedUserName){
       cout<<"Username not found\n";
       return 0;}
   
    file.close();
    return 0;
}
int main()
{ 
    /* fstream fptr;
    fptr.open("users.txt",ios::in|ios::app|ios::out);
    if(fptr.fail())
    {
        cout<<"Couldn't open file";
        return 0;
        
    } */
    int option;
    cout<<"Welcome to the login system\n";
    do{
    cout<<"Main menu\n 1-Login\n 2-Register (for new users)\n 3-Exit\n";

 cin>>option;
     if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    option = -1;
}
 switch (option){
     case 1:
     login();
     break;
     case 2:
     userRegister();
     break;
     case 3:
     {
        cout<<" Exiting system, Have a good day!";
         exit(1);
         break;
     }
     default:
     cout <<"invalid option , please try again\n";
     
 }}while (option!=3);
   // fptr.close();
    return 0;
}
