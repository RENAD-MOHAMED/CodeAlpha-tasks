#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
float points(string grade) {
    if (grade == "A+" || grade == "a+")
    return 4.00;
    else if(  grade == "a" || grade == "A")
    return 4.00;
    else if (grade == "A-" || grade == "a-")
        return 3.70;
    else if (grade == "B+" || grade == "b+")
        return 3.30;
    else if (grade == "B" || grade == "b")
        return 3.00;
    else if (grade == "B-" || grade == "b-")
        return 2.70;
    else if (grade == "C+" || grade == "c+")
        return 2.30;
    else if (grade == "C" || grade == "c")
        return 2.00;
    else if (grade == "C-" || grade == "c-")
        return 1.70;
    else if (grade == "D+" || grade == "d+")
        return 1.30;
    else if (grade == "D" || grade == "d")
        return 1.00;
    else if (grade == "F" || grade == "f")
        return 0.00;
    else {
        cout << "Invalid grade: " << grade << endl;
        return 0.0;
    }

}
void display(string courses[], string grades[],int hours[],int totalHours,int num){
   cout<<"Course Name\t Grade\t Credit hours ";
   int totalpoints=0;
    for (int i=0;i<num;i++){
       transform(grades[i].begin(), grades[i].end(), grades[i].begin(), ::toupper);
        cout<<courses[i]<<"\t"<<grades[i]<<"\t"<<hours[i]<<"\n";
        totalpoints+=points(grades[i]);
    }
    cout<<"Total hours earned ="<<totalHours;
    cout<<"\nTotal points earned= "<<totalpoints;
    
}
float cCalculator(int n){ float cgpa=0.0, gpa,sum;
int hours,totalHours=0;
    for (int index=1;index<=n;index++)
    {
        cout<<"Please enter the GPA and hours earned At semester  "<<index<<": ";
   cin >>gpa>>hours;
   sum+=gpa*hours;
             totalHours+=hours;
    }
    return (float)sum/(float)totalHours;
}
    float gcalc(int num){ int totalHours=0,hour;
    string grade;
    float sum=0.0;
    string courses[12];
    string grades[12];
    int hours[12];
     
       
           cout<<"Please enter course's name, grade and credit hours: ";
           for (int i=0;i<num;i++){
       
       cin.ignore(); 
getline(cin, courses[i]);
cin >> grades[i] >> hours[i];
       totalHours+=hours[i];
           sum+=hours[i]*points(grades[i]);
          
       }
       display (courses,grades,hours,totalHours,num);
       return sum/(float)totalHours;
    }
    

int main()
{ int num, option,totalHours=0;
cout << fixed << setprecision(2);
do{
    cout<<"CGPA Calculator\n 1-GPA Calculator\n 2-CGPA Calculator\n 3-Exit\n";
    cin>>option;
    if (cin.fail()) {
    cin.clear();
    cin.ignore(1000, '\n');
    option = -1;
}
    switch(option){
        case 1: {
        cout<<"Enter number of courses";
        cin>>num; 
        float gpa=gcalc(num);
     cout << "\nYour GPA is: " << gpa << endl;
                break;}
        case 2:{
                cout << "Enter number of semesters: ";
                cin >> num;
                float cgpa=cCalculator(num);
                cout << "\nYour CGPA is: " << cgpa << endl;
        break;}
        case 3:{
        cout<<"Exiting now ,Thanks for using our GPA Calculator";
        exit(1);}
        default:{
        cout<<"Please choose a valid option\n";
        break;}
    }}while (option!=3);
 
 
    return 0;
}
