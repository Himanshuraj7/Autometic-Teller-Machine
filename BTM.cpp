#include<bits/stdc++.h>
using namespace std;

void balance_inquary(){	
	//ifstream 
}

void withdrawal(){
}

void money_depoist(){
}

void change_pin(){
}

void mini_statement(){
}

void add_aadhar_card(){
}

void add_PAN(){
}

int main(){
	int choice;
	
	cout<<" 1. Balance inquary\n";
	cout<<" 2. Withdrawal\n";
	cout<<" 3. Money depoist\n";
	cout<<" 4. Change pin\n";
	cout<<" 5. Mini statement\n";
	cout<<" 6. Add aadhar card\n";
	cout<<" 7. Add PAN\n";
	
	cout<<"\nEnter your choice: ";
	cin>>choice;
	
	
	
	switch(choice){
		case 1: 
			balance_inquary();
			break;
			
		case 2:
			withdrawal();
			break;
			
		case 3:
			money_depoist();
			break;
			
		case 4:
			change_pin();
			break;
			
		case 5:
			mini_statement();
			break;
			
		case 6:
			add_aadhar_card();
			break;
			
		case 7:
			add_PAN();
			break;
			
	}
	
	return 0;
}
