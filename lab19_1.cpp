#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

 void importDataFromFile(string filename,vector<string> name,vector<int> scores,vector<char> grade){
    ifstream file;
    file.open(filename);
    string temp;
    char nam[20];
    for(int i=0;getline(file,temp);i++){
    getline(file,temp);
    const char * tem = temp.c_str();
    int A,B,C,sum = 0;
    sscanf(tem,"%[^:]:%d,%d,%d",nam ,&A,&B,&C);
    sum = A+B+C;
    scores[i] = sum;
    name[i] = nam;
    }
    file.close();
    return;
}

string getCommand(string command,string key){
    cout << " Please input your command: ";
    cin >> command >> key;
    return command,key;
}

void searchName(vector<string> names,vector<int> scores,vector<char> grades,string key){
    cout << "---------------------------------";
    for(int i=0;i==100;i++){
        if(names[i] == key){
        cout << names[i] << "'s score = " << scores[i] << endl;
        score2grade(scores[i]);
        cout << names[i] << "'s grade = " << grades[i];
        } 
    cout << "---------------------------------";
    }
}

void searchGrade(vector <string> names,vector<int> scores,vector<char> grades,string key){
    cout << "---------------------------------";
    char ke = key[0];
    for(int i=0;i == 100;i++){
        if(grades[i] == ke){
        cout << names[i] << " (" << scores[i] << ")" << endl;
        } 
    cout << "---------------------------------";
    }
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
