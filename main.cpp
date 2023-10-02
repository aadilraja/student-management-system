#include <iostream>
#include<windows.h>
#include <fstream>
#include <string>
#include<vector>
#include <cstdlib>
#include <ctime>
#include "login.cpp"



using namespace std;

using std::cout;
using std::cin;
using std::string;
using std::getline;
bool serch(int value);




class student
{
    public:
    //date of birth
     int day_ob;
    string mn_ob;
    int year_ob;
    //date of admission

    int day_ad;
    string mn_ad;
    int year_ad;

   
    int phone_number{0};

    string Sname;
    string father_name;
    string mother_name;

    ofstream fout;
    ifstream fin;
    
   
     int reg_no{0};

    void input_file()
    {

        
       
        
        cout<<"enter the student name:";
        getline(cin,Sname);
        cout<<"enter the student father  name:";
        getline(cin,father_name);
        cout<<"enter the student  mother name:";
        getline(cin,mother_name);
         cout<<"enter the date of birth in day/month(as string)/year format:";
      while (!(cin >> day_ob >> mn_ob >> year_ob) || !is_valid_date(day_ob, mn_ob)) {
        cout << "Invalid date. Please try again: ";
        cin.clear();  // Clear the error state.
        cin.ignore();  // Ignore invalid input.
    }

         cout<<"enter the date of admission in day/month(as string)/year format:";
         
         while (!(cin >> day_ob >> mn_ob >> year_ob) || !is_valid_date(day_ob, mn_ob)) {
        cout << "Invalid date. Please try again: ";
        cin.clear();  // Clear the error state.
        cin.ignore();  // Ignore invalid input.
    }
         cout<<"enter the phone number:";
        cin>>phone_number;
         
        
    






        fout.open("C:/coding/cpp_project/cpp_project/student_mangement_system/studentdata/"+to_string(reg_no)+".txt");
        fout<<"register no:"<<reg_no<<"\tname:"<<Sname<<"\nfather name:"<<father_name<<"\tmother name:"<<mother_name<<endl;
        fout<<"date of birth:"<<day_ob<<"/"<<mn_ob<<"/"<<year_ob<<"\nyear of admission:"<<day_ad<<"/"<<mn_ad<<"/"<<year_ad;
        fout<<"\nphone number:"<<phone_number;
        fout.close();

        
       
       }
    void existing_input()
    {
     cout<<"enter registeration number of the student:";
    cin>>reg_no;
    if(serch(reg_no))
    {
        int op,i{0};
        vector<string>lines;
        
        string file_nm="C:/coding/cpp_project/cpp_project/student_mangement_system/studentdata/"+to_string(reg_no)+".txt";
        
       
        
           
        ifstream fin(file_nm);
        if (fin) {
            cin.ignore();

            string line;
            while (getline(fin, line)) {
                lines.push_back(line);
            }
            fin.close();
        } 
        else {
            cerr << "Error opening file for reading." << endl;
            return;
        }

           while(i!=1){
            cout << "Choose the action:\n 1) Name\t2) Father name\t3) Mother name\n";
            cout << "4) D.O.B 5) D.O.A 6) Phone number\n";
            cin >> op;
            cin.ignore();

            switch (op) {
                case 1:
                    cout << "Enter name: ";
                    getline(cin, Sname);
                    // Update the appropriate line in the vector
                    lines[0] = "Name: " + Sname;
                    break;
                case 2:
                    cout << "Enter father's name: ";
                    getline(cin, father_name);
                    // Update the appropriate line in the vector
                    lines[1] = "Father's Name: " + father_name;
                    break;
                case 3:
                    cout << "Enter mother's name: ";
                    getline(cin, mother_name);
                    // Update the appropriate line in the vector
                    lines[2] = "Mother's Name: " + mother_name;
                    break;
                
                default:
                    cout << "Error: Invalid choice!!" << endl;
                    break;
            }
            
    
        

        // Write the modified data back to the file
        ofstream fout(file_nm);
        if (fout) {
            for (const string& line : lines) {
                fout << line << endl;
            }
            fout.close();
        } 
        else {
            cerr << "Error opening file for writing." << endl;
        }
        cout<<"press 1 to exit:-";
        cin>>i;

        }
        
    
    }
    }     
        

   
 
    
}s;






bool serch(int value)
{
    string num=to_string(value)+".txt";
    string path="C:/coding/cpp_project/cpp_project/student_mangement_system/studentdata/";
    string srch=path+num;

    WIN32_FIND_DATAA findFileData;
     HANDLE hFind = FindFirstFileA(srch.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        FindClose(hFind);
        
        return false ;
        
    }
        FindClose(hFind);
        
        return true;
    
}
int gen_reg()
{
   
    const int minRegNumber = 10000;
    const int maxRegNumber = 99999;

    int x;
   do {
        x = minRegNumber + (rand() % (maxRegNumber - minRegNumber + 1));
    } while (serch(x));



    return x;
    
}
 void view()
 {
    int x;
    string read;
    cout<<"enter the registeration number:";
    cin>>x;
    if(serch(x))
    {
        s.fin.open("C:/coding/cpp_project/cpp_project/student_mangement_system/studentdata/"+to_string(x)+".txt");
        while(getline(s.fin,read))
        {
            cout<<read<<"\n";

        }
        



    }
    else
    {
        cerr<<"error:no file with that name";
    }

 }
 void remove_file()
 {
    cout<<"enter the registeration number of student u want to remove\n-->";
    cin>>s.reg_no;
    string path="C:/coding/cpp_project/cpp_project/student_mangement_system/studentdata/"+to_string(s.reg_no)+".txt";
     if (DeleteFileA(path.c_str())== 0) {
        cerr << "failed to delete student data!!" <<endl;
     }
      else {
        std::cout << "student data deleted successfully!! " <<endl;
    }
 }









 
    

int main() {
     srand(static_cast<unsigned>(time(nullptr)));
    if(ln())
    {
        int ch;
        cout<<"-------WELCOME TO STUDENT MANGEMENT SYSTEM-----\n\n";
       again:cout<<"1)update student record\t2)view student record\n-->";
        cin>>ch;
        
        if(ch==1)
        {
            int o;
            cout<<"1)add new student\t2)update existing student\t 3)delete student\n=>";
            cin>>o;
            cin.ignore();
            switch(o){

              case 1:
               s.reg_no=gen_reg();
               s.input_file();
               
               break;
              case 2:
               s.existing_input();
               break;
               case 3:
               remove_file();
              default:
               cerr<<"something went wrong!!";
              
            }
        }  
        else if(ch==2)
        {  
          view();
        }

        else
        {
            cout<<"ERROR:enter 1 or 2";
            goto again;
        }
        
    }
    else
    {
        cerr<<"ERROR:wrong username and password";
    }
    return 0;

}