#include <iostream>
#include <string>
#include "add_alias.h"
#include <fstream>

using namespace std;

void add_alias(){
	char name[10];
	cout<<"Enter alias's call name"<<endl;
	cin.getline(name,sizeof(name));
	cout<<"Enter the command (in parentheses)"<<endl;
	char command[100];
	cin.getline(command,sizeof(command));
	string first="alais ";
	string second="=\'";
	string third="\'";
	string new_line=first+name+second+command+third;
	fstream file;
	file.open("test.txt",ios::app);
//	file.open("~/.bashrc",ios::app);
	file<<new_line<<endl;
	cout<<new_line<<endl<<endl;
}//end add_alias
