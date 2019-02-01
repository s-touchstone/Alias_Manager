#include <iostream>
#include <fstream>
#include <string>
#include "lis_alias.h"

using namespace std;

void lis_alias(){
	string line;
	string trigger="off";
	fstream file;
	file.open("test.txt");
//	file.open("~/.bashrc");
	while(getline(file,line)){
		if(line=="#Custom aliases"){
			trigger="on";
			continue;
		}//end if
		if(trigger=="on"){
			cout<<line<<endl;
		}//end if
	}//end while
	cout<<endl;
}//end lis_alias
