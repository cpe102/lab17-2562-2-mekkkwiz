#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

string upper (string x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i] = toupper(x[i]);
    }
    return x;
    
}

int main()
{
    ifstream file("name_score.txt");                
    string text;
    vector <string> nameAll;
    vector <int> scoreAll;
    vector <string> GradeAll;
    int score1,score2,score3;
    char name[100];
    // input and calculate grade
    while (getline(file,text))
    {
        
        sscanf(text.c_str(),"%[^:]: %d %d %d",name,&score1,&score2,&score3);
        nameAll.push_back(name);
        int total = score1+score2+score3;
        string grade = (total>=80) ? "A" : (total>=70) ? "B" : (total>=60) ? "C" : (total>=50) ? "D" : "F" ;
        scoreAll.push_back(score1);
        scoreAll.push_back(score2);
        scoreAll.push_back(score3);
        GradeAll.push_back(grade);
    }
    int j = 0;
    string s;



    // for (int i = 0; i < GradeAll.size(); i++)
    // {
    //     cout << GradeAll[i];
    // }


    
    while (1)
    {
        cout << "Please input your command: ";
        getline(cin,s);
        int idx = s.find_first_of(" ");
        string s1 = upper(s.substr(0,idx));
        string s2 = upper(s.substr(idx+1,idx+(s.size()-idx)));

    
       // cout << idx << " " << s1 << " " << s2;
        if (s1 == "NAME")
        {
            cout << "-------------------------------\n";
            for (int i = 0; i < nameAll.size(); i++)
            {
                if (s2 == upper(nameAll[i]))
                {
                    cout << nameAll[i] << "'s grade = " << GradeAll[i] << endl;
                    cout << "-------------------------------\n";
                    break;
                }
                else if (i == nameAll.size()-1)
                {
                    cout << "cannot found." << endl;
                    cout << "-------------------------------\n";
                }
            }
            
            
        }
        else if (s1 == "GRADE")
        {
            cout << "-------------------------------\n";
            for(int i=0;i<GradeAll.size();i++){
                string s3=GradeAll[i];
                if(upper(s3)==s2){
                    cout << nameAll[i] << "\n";
                }
            }
            cout << "-------------------------------\n";
        }
        else if (s1 == "EXIT")
        {
            break;
        }
        else
        {
            cout << "-------------------------------\n";
            cout << "Invalid command." << endl;
            cout << "-------------------------------\n";
        }
    }
    

    
  
  
    
   return 0;
}

