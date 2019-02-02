#include <iostream>
#include <fstream>
#include <string>
#include "lis_alias.h"

using namespace std;

void lis_alias(){
	string line,trigger="off";
	fstream file;
	file.open("test.txt");
//	file.open("~/.bashrc");

	//Generate a list of commands found after the #Custom Aliases line in the file and output them

	while(getline(file,line)){
		if(line=="#Custom Aliases"){
			trigger="on";
			continue;
		}
		if(trigger=="on"){
			cout<<line<<endl;
		}
	}
	cout<<endl;
}
