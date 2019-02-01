#include <iostream>
#include <string>
#include <fstream>
#include "mod_alias.h"

using namespace std;

void mod_alias(){
	int each=0,selection,selection2;
	string line,commands[100],names[100],trigger="off",lines[100],exit="false",first="alias ",quote="\'",new_line,old_line,temp_line;
	char new_info[100];
//	fstream file;
	ifstream ifile("test.txt");
	ofstream ofile("test.txt");
//	file.open("test.txt");
//	ifile.open();
//	file.open("~/.bashrc");
//	while(getline(file,line)){
	while(getline(ifile,line)){
		if(line=="#Custom aliases"){
			trigger="on";
			continue;
		}//end if
		if(trigger=="on"){
			lines[each]=line;
			each+=1;
			continue;
		}//end if
	}//end while
//	file.close();
	for(int i=0;i<each;i++){
		size_t pos=lines[i].find("=");
		commands[i]=lines[i].substr(pos+2);
		commands[i]=commands[i].erase(commands[i].size()-1);
		names[i]=lines[i].substr(6,pos-6);
	}//end for
	while(exit!="true"){
		cout<<"1. Change name"<<endl<<"2. Edit the command"<<endl<<"#";
		cin>>selection;
		if(selection==1){
			for(int i=0;i<each;i++){
				cout<<i+1<<". "<<names[i]<<endl;
			}//end for
		}//end if
		else if(selection==2){
			for(int i=0;i<each;i++){
				cout<<i+1<<". "<<commands[i]<<endl;
			}//end for
		}//end else if
		else{
			cout<<"That selection was incorrect"<<endl;
			continue;
		}//end else
		cout<<"Which one would you like to change?"<<endl<<"#";
		cin>>selection2;
		cin.ignore();
		cout<<"Enter new information"<<endl<<"#";
		cin.getline(new_info,sizeof(new_info));
		old_line=first+names[selection2-1]+"="+quote+commands[selection2-1]+quote;
		cout<<"OLD: "<<old_line<<endl;
		if(selection==1){
			new_line=first+new_info+"="+quote+commands[selection2-1]+quote;
		}//end if
		else{
			new_line=first+names[selection2-1]+"="+quote+new_info+quote;
		}//end else
		exit="true";
	}//endwhile
//	file.open("test.txt");
//	ifile.open();
//	ofile.open();
//	file.open("~/.bashrc",ios::app);
	while(ifile >> temp_line){
		if(temp_line==old_line){
//			cout<<"Found match: "<<line<<endl;
//			line.replace(0,line.length(),new_line);
			temp_line=old_line;
		}//end if
		temp_line+="\n";
		ofile << temp_line;
//		line.replace(line.find("alias "+names[selection2-1]),line.length()-1,new_line);
	}//end while
//	ifile.close();
//	ofile.close();
	cout<<"NEW: "<<new_line<<endl<<endl;
}//end mod_alias
