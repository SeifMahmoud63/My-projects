#include "BANK.h"
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include <ctime>
#include <limits>
#include <sstream>
#include <iomanip>
using namespace std;
void clsp::setfn(string fn)
{
	_FN = fn;
}

string clsp::getfn()
{
	return _FN;
}

void clsp::setln(string ln)
{
	_LN = ln;
}

string clsp::getln()
{
	return _LN;
}

void clsp::setgmail(string gmail)
{
	_gmail = gmail;
}

string clsp::getgmail()
{
	return _gmail;
}

void clsp::setphone(int phone)
{
	_phone = phone;
}

int clsp::getphone()
{
	return _phone;
}

void clsp::setpin(int pinn)
{
    _pin = pinn;
}

int clsp::getpin()
{
    return _pin;
}

string clsp::getfullname()
{
    return _FN + " " + _LN;
}

int clsp::getAccNumber()
{
   
    _AccNumber = _AccBalance % 10 + 789546%15+35795;
    return _AccNumber;
}

void clsp::setAccBalance(int accb)
{
    _AccBalance = accb;
}

int clsp::getAccB()
{
    return _AccBalance;
}


void clsp::addClient() {
    string firstnamee;
  string lastnamee;
     string gmaill;
    int phonee;
    int pinn,ACCB;
 
   cout << "\t\t\tWhat is your First Name: ";
    cin >> firstnamee;

    cout << "\t\t\tWhat is your Last Name: ";
    cin >> lastnamee;

  cout << "\t\t\tWhat is your Gmail: ";
    cin >> gmaill;

    cout << "\t\t\tWhat is your Phone Number: ";
    cin >> phonee;

    cout << "\t\t\tWhat is your pin code: ";
    cin >> pinn;

    cout << "\t\t\tWhat is your Balance Do you want put it ? ";
    cin >> ACCB;
    clsp client;

    client.setfn(firstnamee);
    client.setln(lastnamee);
    client.setgmail(gmaill);
    client.setphone(phonee);
    client.setpin(pinn);
    client.setAccBalance(ACCB);
    client.getAccNumber();
    Vnames.push_back(client);

    fstream file;
    
    file.open("ADDCLIENT.txt", ios::out | ios::app);
    if (file.is_open()) {
        file << client.getfn()<<" ";
        file << client.getln()<<" ";
        file << client.getgmail()<<" ";
        file << client.getphone()<<" ";
        file << client.getpin()<<" ";
        file << client.getAccB()<<" ";
        file << client.getAccNumber()<<" ";
        file << "  " << getCurrentDateTime()<<" \n";
            file.close();
    }
   
    int YYN;
    cout << "\t\t\tDo You want to continue ? 1-Yes,2-NO\n";
    cin >> YYN;
    if (YYN == 1)
    {
        MAINSCREEN();
    }
    else {
        cout << "\n\t\t\tEND\n";
        return;
    }
}
void clsp::findclient()
{
    int num;
    string name1, name2;

    cout << "\t\t\tWhat is the first name to search for? ";
    cin >> name1;
    cout << "\t\t\tAND What is the second name? ";
    cin >> name2;
    cout << "\t\t\tWhat is the pin code? ";
    cin >> num;

    ifstream file("ADDCLIENT.txt"); 
    if (!file.is_open()) {
        cout << "\t\t\tError opening file!\n";
        return;
    }

    string line;
    bool clientFound = false; 

    while (getline(file, line)) {
        istringstream iss(line);
        string fn, ln, gmail;
        int phone, pin, accNumber, accBalance;
        string dateTime;

      
        iss >> fn >> ln >> gmail >> phone >> pin >> accBalance >> accNumber;
        getline(iss, dateTime); 

        if (pin == num && fn == name1 && ln == name2) {
            cout << "\t\t\t\nYOUR First Name is      : " << fn;
            cout << "\t\t\t\nYOUR Second Name is     : " << ln;
            cout << "\t\t\t\nYOUR Full Name is       : " << fn + " " + ln;
            cout << "\t\t\t\nYour Gmail is           : " << gmail;
            cout << "\t\t\t\nYour Phone is           : " << phone;
            cout << "\t\t\t\nYOUR ACCOUNT NUMBER IS  : " << accNumber;
            cout << "\t\t\t\nYOUR ACCOUNT BALANCE IS : " << accBalance;
            cout << "\t\t\t\nDate and Time of Entry   : " << dateTime << endl;

            clientFound = true; 
            break; 
        }
    }

    if (!clientFound) {
        cout << "\t\t\tClient not found.\n";
    }

    file.close(); 
    int YN;
    cout << "\t\t\tDo you want to continue? 1-Yes, 2-No\n";
    cin >> YN;
    if (YN == 1) {
        MAINSCREEN(); 
    }
    else {
        cout << "\n\t\t\tEND\n";
        return;
    }
}
void clsp:: listAllClientsInFile(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!\n";
        return;
    }

   string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        while (getline(ss, token)) { 
            cout << token << endl;
            cout << " ";
        }
    }

    file.close();
}

void clsp::MAINSCREEN() {
    try {
        int x;
        cout << "\t\t\t================================================================\n";
        cout << "\t\t\t\t\t\t MAIN SCREEN         ";
        cout << getCurrentDateTime();
        cout << endl;
        cout << "\t\t\t================================================================\n";
        cout << "\t\t\t[1] ADD CLIENT \n";
        cout << "\t\t\t[2] FIND CLIENT\n";
        cout << "\t\t\t[3] LIST OF CLIENTS ALL\n";
        cout << "\t\t\t[4] EDIT\n";
        cout << "\t\t\t[5] DELETE CLIENT\n";
        cin >> x;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
            throw string("Invalid input, please enter a number.\n");
        }

        if (x == 1) {
            addClient();
        }
        else if (x == 2) {
            findclient();
        }
        else if (x == 3) {
            listAllClientsInFile("ADDCLIENT.txt");
        }
        else if (x == 4) {
            Edit();
        }
        else if (x == 5) {
            DeleteClient();
        }
        else {
            throw string("Invalid choice, please try again.\n");  
        }
    }
    catch (const string& e) { 
        cout << e;
        MAINSCREEN();  
    }
}
 string clsp::getCurrentDateTime() {
     time_t currentTime =  time(nullptr);
     tm localTime;
    localtime_s(&localTime, &currentTime);
     ostringstream dateTimeStream;
    dateTimeStream <<  put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return dateTimeStream.str();
}

void clsp::Edit()
{
    int rkm;
    cout << "\t\t\t================================================================\n";
    cout << "\t\t\t\t\t\t    EDIT !         "; 
    cout << endl;
    cout << "\t\t\t================================================================\n";
    cout << "\t\t\tWhat do you want to Edit it ?\n";
    cout << "\t\t\t[1] Gmail\n";
    cout << "\t\t\t[2] Pin Code\n";
    cout << "\t\t\t[3] Phone Number\n";
    cout << "\t\t\t[4] Add More Balance in My Account\n";
    cout << "\t\t\t[5] BACK TO MENU\n";
    cin >> rkm;
    
    if (rkm == 1)
        editgmail();
    else if (rkm == 2)
        editpin();
    else if (rkm == 3)
        editphone();
    else if (rkm == 4)
        ADDNEWBALANCE();
 
else {
        MAINSCREEN();
}
}
 

void clsp::editgmail() {
     string oldg, newg;
     string name1, name2;
    int pinn;

     cout << "\t\t\tWhat is your first name?\n";
     cin >> name1;
     cout << "\t\t\tWhat is last name ?\n";
     cin >> name2;
     cout << "\t\t\tWhat is your pin Code ?\n";
     cin >> pinn;
     cout << "\t\t\tWhat is old Gmail ?\n";
     cin >> oldg;
     cout << "\t\t\tWhat is new gmail ?\n";
     cin >> newg;

    ifstream file("ADDCLIENT.txt");
    if (!file.is_open()) {
         cout << "\t\t\tError opening file!\n";
        return;
    }

     string line;
     vector< string> lines;
    bool clientFound = false;

    while ( getline(file, line)) {
         istringstream iss(line);
         string fn, ln, gmail;
        int phone, pin, accNumber, accBalance;
         string dateTime;

        iss >> fn >> ln >> gmail >> phone >> pin >> accBalance >> accNumber;
         getline(iss, dateTime);
        if (pin == pinn && fn == name1 && ln == name2) {
            gmail = newg;
            clientFound = true;
        }

       
         ostringstream oss;
        oss << fn << ' ' << ln << ' ' << gmail << ' ' << phone << ' ' << pin << ' ' << accBalance << ' ' << accNumber << dateTime;
        lines.push_back(oss.str());
    }

    file.close();

    if (!clientFound) {
         cout << "\t\t\tClient not found.\n";
    }
    else {
     
         ofstream outFile("ADDCLIENT.txt");
        if (!outFile.is_open()) {
             cout << "\t\t\tError opening file for writing!\n";
            return;
        }
        for (const auto& l : lines) {
            outFile << l << '\n';
        }
        outFile.close();
    }

    int YN;
     cout << "\t\t\tDo you want to continue? 1-Yes, 2-No\n";
     cin >> YN;
    if (YN == 1) {
        MAINSCREEN();
    }
    else {
         cout << "\n\t\t\tEND\n";
        return;
    }
}

void clsp::editphone() {
    int pinn, oldphone, newphone;
     string name1, name2;
     vector< string> V;
     cout << "\t\t\tWhat is your first Name ?\n";
     cin >> name1;
     cout << "\t\t\tWhat is your second Name ?\n";
     cin >> name2;
     cout << "\t\t\tWhat is your pin code ?\n";
     cin >> pinn;
     cout << "\t\t\tWhat is your old phone ?\n";
     cin >> oldphone;
     cout << "\t\t\tWhat is your new phone ?\n";
     cin >> newphone;

     ifstream file("ADDCLIENT.txt");
    if (!file.is_open()) {
         cout << "\t\t\tError opening file!\n";
        return;
    }

     string fn, ln, gmail, dt;
    int phone, pin, accb, accn;
     string line;
    bool clientFound = false;

    while ( getline(file, line)) {
         istringstream iss(line);
        iss >> fn >> ln >> gmail >> phone >> pin >> accb >> accn;
         getline(iss, dt);

        if (pinn == pin && fn == name1 && name2 == ln) {
            phone = newphone;
            clientFound = true;
        }

         ostringstream oss;
         oss << fn << ' ' << ln << ' ' << gmail << ' ' << phone << ' ' << pin << ' ' << accb << ' ' << accn << ' ' << dt;
        V.push_back(oss.str());
    }

    file.close();

    if (!clientFound) {
        int a;
         cout << "The information you uploaded does not match with any client! Do you want to try again? 1-Yes 2-No\n";
         cin >> a;
        if (a == 1) {
            editphone();
        }
        else {
             cout << "\t\t\tEnd\n";
            return;
        }
    }
    else {
         ofstream outFile("ADDCLIENT.txt");
        if (!outFile.is_open()) {
             cout << "\t\t\tError opening file for writing!\n";
            return;
        }
        for (const auto& lines : V) {
            outFile << lines << '\n';
        }
        outFile.close();
    }

    int YN;
     cout << "\t\t\tDo you want to continue? 1-Yes, 2-No\n";
     cin >> YN;
    if (YN == 1) {
        MAINSCREEN();
    }
    else {
         cout << "\n\t\t\tEND\n";
        return;
    }
}
 
void clsp::editpin() {
    int pinn, oldpin, newpin;
     string name1, name2;
     vector< string> V;
     cout << "\t\t\tWhat is your first Name ?\n";
     cin >> name1;
     cout << "\t\t\tWhat is your second Name ?\n";
     cin >> name2;
     cout << "\t\t\tWhat is your old pin code ?\n";
     cin >> oldpin;
     cout << "\t\t\tWhat is your new pin ?\n";
     cin >> newpin;

     ifstream file("ADDCLIENT.txt");
     string fn, ln, gm, dt;
    int phone, pin, accn, accb;
     string line;
    bool found = false;

    if (!file.is_open()) {
         cout << "FILE DOESN'T OPEN\n";
        return;
    }

    while ( getline(file, line)) {
         istringstream iss(line);
        iss >> fn >> ln >> gm >> phone >> pin >> accb >> accn;
         getline(iss, dt);

        if (fn == name1 && name2 == ln && pin == oldpin) {
            pin = newpin; 
            found = true;
        }

         ostringstream os;
        os << fn << " " << ln << " " << gm << " " << phone << " " << pin << " " << accb << " " << accn << " " << dt;
        V.push_back(os.str());
    }

    file.close();

    if (!found) {
        int a;
         cout << "The information you uploaded does not match with any client! Do you want to try again? 1-Yes 2-No\n";
         cin >> a;
        if (a == 1) {
            editpin();
        }
        else {
             cout << "\t\t\tEnd\n";
            return;
        }
    }
    else {
         ofstream filee("ADDCLIENT.txt");
        if (!filee.is_open()) {
             cout << "FILE DOESN'T OPEN FOR WRITING\n";
            return;
        }
        for (const auto& line : V) {
            filee << line << '\n';
        }
        filee.close();
    }

    int YN;
     cout << "\t\t\tDo you want to continue? 1-Yes, 2-No\n";
     cin >> YN;
    if (YN == 1) {
        MAINSCREEN();
    }
    else {
         cout << "\n\t\t\tEND\n";
        return;
    }
}

void clsp::ADDNEWBALANCE() {
    bool found = false;
    int pinnn, NEWBALANCE;
     string name1, name2;
     vector< string> V;

     cout << "\t\t\tWhat is your first Name ?\n";
     cin >> name1;
     cout << "\t\t\tWhat is your second Name ?\n";
     cin >> name2;
     cout << "\t\t\tWhat is your old pin code ?\n";
     cin >> pinnn;
     cout << "What is New Balance Want added ?\n";
     cin >> NEWBALANCE;

     ifstream file("ADDCLIENT.txt");
    if (!file.is_open()) {
         cout << "File doesn't open..\n";
        return;
    }

     string line;
    while ( getline(file, line)) {
        int accn, accb, pin, phone;
         string fn, ln, dt, gm;
         istringstream iss(line);
        iss >> fn >> ln >> gm >> phone >> pin >> accb >> accn;
         getline(iss, dt);

        if (fn == name1 && name2 == ln && pin == pinnn) {
            accb += NEWBALANCE;
            found = true;
        }

         ostringstream os;
        os << fn << " " << ln << " " << gm << " " << phone << " " << pin << " " << accb << " " << accn << " " << dt;
        V.push_back(os.str());
    }

    file.close();

    if (!found) {
        int num;
         cout << "THE INFORMATION IS WRONG. DO YOU WANT TO TRY AGAIN? 1-Yes, 2-No\n";
         cin >> num;
        if (num == 1) {
            ADDNEWBALANCE();
        }
        else {
             cout << "END\n";
            return;
        }
    }
    else {
         ofstream filee("ADDCLIENT.txt");
        if (!filee.is_open()) {
             cout << "File doesn't open for writing..\n";
            return;
        }
        for (const auto& line : V) {
            filee << line << '\n';
        }
        filee.close();
    }
    int YN;
     cout << "\t\t\tDo you want to continue? 1-Yes, 2-No\n";
     cin >> YN;
    if (YN == 1) {
        MAINSCREEN();
    }
    else {
         cout << "\n\t\t\tEND\n";
        return;
    }
}

void clsp::DeleteClient() {
    string firstN, lastN;
    int pinC;
    vector<string> tempVector;
    bool found = false;
    cout << "Enter the first Name: ";
    cin >> firstN;
    cout << "Enter the last Name: ";
    cin >> lastN;
    cout << "What is your pin code? ";
    cin >> pinC;

    ifstream file("ADDCLIENT.txt");
    if (!file.is_open()) {
        cout << "Error in opening File..\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string fn, ln, gm, dt;
        int phone, pin, accn, accb;


        iss >> fn >> ln >> gm >> phone >> pin >> accn >> accb;
        getline(iss, dt);
        if (fn == firstN && ln == lastN && pin == pinC) {
            found = true;
            continue;
        }
        tempVector.push_back(line);
    }
    file.close();
    ofstream outFile("ADDCLIENT.txt");
    if (!outFile.is_open()) {
        cout << "Error in opening File for writing..\n";
        return;
    }

    for (const auto& entry : tempVector) {
        outFile << entry << '\n';
    }
    outFile.close();  
    
    if (!found) {
        int a;
        cout << "Invalid information. Do you want to try again? 1-Yes, 2-No\n";
        cin >> a;
        if (a == 1) {
      
            cout << "Wrong information .. Again \n";
            DeleteClient();
        }
        else {
            cout << "\t\t\tEnd\n";
        }
    }
    else {
        cout << "Client deleted successfully.\n";
    }
    int YN;
    cout << "\t\t\tDo you want to continue? 1-Yes, 2-No\n";
    cin >> YN;
    if (YN == 1) {
        MAINSCREEN();
    }
    else {
        cout << "\n\t\t\tEND\n";
        return;
    }
}
 
