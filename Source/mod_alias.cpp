#include <iostream>
#include <string>
#include <fstream>
#include "mod_alias.h"

using namespace std;

void mod_alias(){
	int each=0,selection,selection2;
	string line,commands[100],names[100],trigger="off",lines[100],exit="false",first="alias ",quote="\'",new_line,old_line,temp_line;
	char new_info[100];
	fstream file;
//	ifstream ifile("~/.bashrc");
	ifstream ifile("test.txt");
//	ofstream ofile("bashrc_tmp.txt");
	ofstream ofile("test2.txt");
//	file.open("~/.bashrc");
	file.open("test.txt");

	//Find lines under the #Custom Aliases marker in the file and copy those lines into an array
	
	while(getline(file,line)){
		if(line=="#Custom Aliases"){
			trigger="on";
			continue;
		}
		if(trigger=="on"){
			lines[each]=line;
			each+=1;
			continue;
		}
	}
	file.close();

	//Cut the lines into the the names and commands and place into new arrays
	
	for(int i=0;i<each;i++){
		size_t pos=lines[i].find("=");
		commands[i]=lines[i].substr(pos+2);
		commands[i]=commands[i].erase(commands[i].size()-1);
		names[i]=lines[i].substr(6,pos-6);

	}

	//Prompt to change either the name or the command then reassemble the original line to put back into file

	while(exit!="true"){
		cout<<"1. Change name"<<endl<<"2. Edit the command"<<endl<<"#";
		cin>>selection;
		if(selection==1){
			for(int i=0;i<each;i++){
				cout<<i+1<<". "<<names[i]<<endl;
			}
		}
		else if(selection==2){
			for(int i=0;i<each;i++){
				cout<<i+1<<". "<<commands[i]<<endl;
			}
		}
		else{
			cout<<"That selection was incorrect"<<endl;
			continue;
		}
		cout<<"Which one would you like to change?"<<endl<<"#";
		cin>>selection2;
		cin.ignore();
		cout<<"Enter new information"<<endl<<"#";
		cin.getline(new_info,sizeof(new_info));
		old_line=first+names[selection2-1]+"="+quote+commands[selection2-1]+quote;
		cout<<"OLD: "<<old_line<<endl;
		if(selection==1){
			new_line=first+new_info+"="+quote+commands[selection2-1]+quote;
		}
		else if(selection==2){
			new_line=first+names[selection2-1]+"="+quote+new_info+quote;
		}
		exit="true";
	}

	//Write all lines back into a new file only changing the modified line

	while(getline(ifile,temp_line)){
		for(int i=0;i<=temp_line.length();i++)	//Testing
			cout<<temp_line[i]<<"-";      	//Testing
		cout<<endl;
		if(temp_line==old_line){		//Problem here: temp_line!=old_line when it should
			temp_line=new_line;
			cout<<"Created new line"<<endl;	//Testing
		}
		temp_line+="\n";
		ofile << temp_line;
	}

	//Replace original file with the newly generated one

//	rename("bashrc_tmp.txt","~/.bashrc");
//	rename("test2.txt","test.txt");
	cout<<"NEW: "<<new_line<<endl<<endl;
}
