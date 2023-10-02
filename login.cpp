#include <iostream>
#include<string>

#include<fstream>
using namespace std;





bool ln()
{
    
std::string user;
std::string password;
cout<<"enter the user name:";
cin>>user;
cout<<"enter the password:";
cin>>password;


std::ifstream fin;
    
    std::string s[100];

    
   
    

    fin.open("teacher.txt");

       if(!fin.is_open())
       {
        cerr<<"ERROR:not opened!!";
       }
       for(int i=0;!fin.eof();i++)
       {
        fin>>s[i];
        if((user+password)==s[i])
        {
          return true;
           fin.close();

        }
       }
        fin.close();
       return false;
      

   
   
    
    
}
bool is_valid_date(int date,string mn)
{
         
    if (date >= 1 && date <= 31) {
        string months[12] = {"jan", "feb", "mar", "april", "may", "june", "july", "aug", "sept", "oct", "nov", "dec"};
        
        for (const auto& m : months) {
            if (mn == m) {
                return true;
            }
        }
    }
    
    return false; // Return false for all other cases
}

             
         
       
       

       

       
       


    





