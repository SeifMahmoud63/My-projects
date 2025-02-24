
#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include <ctime>
using namespace std;
class clsp
{
	string _FN, _LN,_gmail;
	int _phone,_pin,_AccBalance;
	 int _AccNumber;
	string fullname = _FN + _LN;
public:
	int number;
	  vector<clsp> Vnames;
	clsp() : _FN(""), _LN(""), _gmail(""), _phone(0),_pin(0),_AccBalance(0) {}
clsp(string fn,string ln,string gmail,int phone,int pin,int Accb):_FN(fn),_LN(ln),_gmail(gmail),_phone(phone),_pin(pin),_AccBalance(Accb){
	_AccNumber++;
}
void setfn(string fn);
string getfn();
void setln(string ln);
string getln();
void setgmail(string gmail);
string getgmail();
void setphone(int phone);
int getphone();
void setpin(int pinn);
int getpin();
string getfullname();
void setAccNumber(int accn);
int getAccNumber();
void setAccBalance(int accb);
int getAccB();
  void addClient();
  void findclient();
  void listAllClientsInFile(string filename);
  void MAINSCREEN();
  string getCurrentDateTime();
  void Edit();
  void editgmail();
  void editphone();
  void editpin();
  void ADDNEWBALANCE();
  void DeleteClient();
   
};
