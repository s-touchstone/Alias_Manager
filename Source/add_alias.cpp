#include <iostream>
#include <string>
#include "add_alias.h"
#include <fstream>

using namespace std;

void add_alias(){
	char name[10],command[100];
	string first="alais ",second="=\'",third="\'"new_line;

	//Prompt for input and then create command syntax to add to file

	cout<<"Enter alias's call name"<<endl;
	cin.getline(name,sizeof(name));
	cout<<"Enter the command as you would in bash"<<endl;
	cin.getline(command,sizeof(command));
	new_line=first+name+second+command+third;
	fstream file;
	file.open("test.txt",ios::app);
//	file.open("~/.bashrc",ios::app);
	file<<new_line<<endl;
	cout<<"New: "<<new_line<<endl<<endl;
}
