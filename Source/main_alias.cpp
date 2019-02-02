#include <iostream>
#include "add_alias.h"
#include "add_alias.cpp"
#include "mod_alias.h"
#include "mod_alias.cpp"
#include "del_alias.h"
#include "del_alias.cpp"
#include "lis_alias.h"
#include "lis_alias.cpp"
#include "init_alias.h"
#include "init_alias.cpp"

using namespace std;

int main(){
	init_alias();
	int menu_sel=5;

	//Main menu propt on what to do

	while(menu_sel!=0){
		cout<<"1. Add a new alias"<<endl;
		cout<<"2. Modify an exising alias"<<endl;
		cout<<"3. Delete an alias"<<endl;
		cout<<"4. List current aliases"<<endl;
		cout<<"0. EXIT"<<endl<<"#";
		cin>>menu_sel;
		cin.ignore();//prep for getline in other functions
		cout<<endl;
		switch(menu_sel){
			case 0:
				break;
			case 1:
				add_alias();
				break;
			case 2:
				mod_alias();
				break;
			case 3:
//				del_alias();
				break;
			case 4:
				lis_alias();
				break;
			default:
				cout<<"Incorrect selection.";
			       	cout<<" Please try again!"<<endl;
				break;
		}
	}
	return 0;
}
