#include <fstream>
#include <string>
#include <iostream>
#include "init_alias.h"

void init_alias(){
//	ifstream ifile("~/.bashrc");
	ifstream ifile("test.txt");
//	ofstream ofile ("bashrc_tmp.txt");
	ofstream ofile("test2.txt");
	string line,cust_line="#Custom Aliases",trigger="on";

	//Read the lines in the file and look for a #Custom Aliases line

	while(getline(ifile,line)){
		if(line!=cust_line){
			line+="\n";
			ofile << line;
//			trigger="off";
			continue;
		}
		else if(line==cust_line & trigger=="on"){
			ofile  << line;
			ofile << "\n";
			trigger="off";
			continue;
		}
	}

	//If a #Custom Alias line is not found the trigger will be set and a #Custom Aliases line will be added to the end of the file

	if(trigger=="on"){
		ofile << cust_line;
		ofile << "\n";
	}

	//Rewrite the file to ensure there is a #Custom Aliases line in it

//	rename("bashrc_tmp.txt","~/.bashrc");
	rename("test2.txt","test.txt");
}
