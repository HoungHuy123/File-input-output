//program 1
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std; 

struct  PERSON {
    char  Name[20];
    float Balance; }; 

int countN(){

    int num=0;
    string tmp;
    ifstream infile; 
    infile.open("data.txt");
    while(!infile.eof()){
        getline(infile, tmp);
        num++;  
    }
    infile.close();

return num; 
}

PERSON * readData(int &N){
    PERSON * P;
    P = new PERSON[N];
    string firstname;
    string lastname;
    string temp;
    ifstream infile;
    infile.open("data.txt");
    for (int i= 0; i < N; i++){
        infile >> firstname >> lastname >> P[i].Balance;
        getline(infile, temp);
        string name = firstname + " " + lastname;
        strcpy(P[i].Name, name.c_str());
    }
    infile.close();
    return P;
}

/*
void readfile(int N, PERSON P[]){
    string firstname;
    string lastname;
    double num;

    ifstream infile;
    string temp;
    infile.open("data.txt");
    for (int i= 0; i< N; i++){
    infile >> firstname >> lastname >> num;
    getline(infile, temp);
    string name = firstname + " " + lastname;
    strcpy(P[i].Name, name.c_str());
    P[i].Balance = num;
    }
    infile.close();
}
*/

void Display(int N, PERSON P[]){
    cout << "       " << "Name" << "            " << "Balance" << endl;
    cout << "---------------------------------------------" << endl;
    for (int i= 0; i < N; i++){
        cout << setw(18) << left << P[i].Name << setw(10) << left << P[i].Balance << endl;
    }
}

void FindRichest(int N, PERSON P[]){
    int richest;
    double tmp;
    for (int i=0; i<N; i++){
        if (P[i].Balance > tmp){
            tmp = P[i].Balance;
            richest = i;
        }
    }
    cout << "The Customer with maximum balance is " << P[richest].Name << endl; 
}
/*
//void Deposit(arr, N, custName, amount){
void Deposit(string CustName, int N, PERSON P[], float amount){

    CustName.c_str();
    int i = N;
    double deposite;
  
    while (CustName != P[i].Name){
        i--;
    }
    cout << P[i].Name << ", how much would you like to deposite? ";
    cin >> deposite;
    
    P[i].Balance += deposite;
    cout << "\nNow your new balance is " << P[i].Balance << endl;


}
*/
void Deposit(string CustName, int N, PERSON P[]){

    CustName.c_str();
    int i = N;
    double deposite;
  
    while (CustName != P[i].Name){
        i--;
    }
    cout << P[i].Name << ", how much would you like to deposite? ";
    cin >> deposite;
    
    P[i].Balance += deposite;
    cout << "\nNow your new balance is " << P[i].Balance << endl;


}

void NewCopy(string s, int N, PERSON P[]){
    //string s = "data.txt"
    ofstream outfile;
    outfile.open("data.txt");
    for (int i = 0; i < N; i++ ){
        outfile << P[i].Name << " " << P[i].Balance << endl;
    }
    outfile.close();
}


int main (){

    int N = countN();
    PERSON P[N];
    string name;
    

    //readfile(N, P);
    readData(N);
    Display(N,P);
    FindRichest(N,P);

    cout << "Enter your full name to deposite money: ";
    getline(cin, name);

    Deposit(name, N,P);
    //Display(N, P);
    NewCopy("data.txt", N, P);

    return 0;
}

