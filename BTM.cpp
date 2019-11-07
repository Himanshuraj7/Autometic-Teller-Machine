#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

string word, filename;
ifstream infile;
fstream iofile;

void account_nontrivial(int pin){
	if(pin==5432){
	iofile.open("Amardeep.txt");
	filename="Amardeep.txt";
	}
	else if(pin==4321){
	iofile.open("Dimple.txt");
	filename="Dimple.txt";
	}
	else if(pin==5176){
	iofile.open("Himanshu.txt");
	filename="Himanshu.txt";
	}
	else if(pin==5378){
	iofile.open("Sharad.txt");	
	filename="Sharad.txt";
	}
	else if(pin==4001){
	iofile.open("Yash.txt");
	filename="Yash.txt";
	}
	else{
		cout<<"No Account exist for the entered PIN";
		exit(0);
	}
}

void account_trivial(int pin){
	if(pin==2345){
	infile.open("Amardeep.txt");
	filename="Amardeep.txt";
	}
	else if(pin==1234){
	infile.open("Dimple.txt");
	filename="Dimple.txt";
	}
	else if(pin==6715){
	infile.open("Himanshu.txt");
	filename="Himanshu.txt";
	}
	else if(pin==8735){
	infile.open("Sharad.txt");	
	filename="Sharad.txt";
	}
	else if(pin==1004){
	infile.open("Yash.txt");
	filename="Yash.txt";
	}
	else{
		cout<<"No Account exist for the entered PIN";
		exit(0);
	}
}

void balance_inquiry(int pin){	
	account_trivial(pin);
	
	while (infile >> word){ 
		if(word.substr(0,7)=="Balance")
        cout<<endl<<word<<endl;
    }
    infile.close();
}

void withdrawal(int pin){
	int iris_pin, temp1, temp2;
	string flag;
	
	cout<<"Enter your IRIS PIN :-- ";
	cin>>iris_pin;
	
	string s=to_string(iris_pin);
	if(s.length()!=4){
		cout<<"wrong PIN entered";
		exit(0);
	}
	
	if(s.length()==4){
		goto s2;
	}
	
	s2:
	account_nontrivial(iris_pin);
	cout<<"Enter the amount to withdraw :-- ";
	cin>>temp1;
	
	while (iofile >> word){ 
		if(word.substr(0,7)=="Balance"){
    	flag= word.substr(8);    
		}
	}
	temp2=stoi(flag)-temp1;
	
	iofile.close();
	account_nontrivial(iris_pin);
	
	ofstream out("temp.txt", ios::out);
	while (iofile >> word){ 	
		if(word.substr(0,7)!="Balance"){
        	out<<word<<endl;
		}
	}
	out<<"Balance="<<temp2;
	
	out.close();
	iofile.close();
	
	char oldname[25];
	strcpy(oldname, filename.c_str());
	remove(oldname);
    rename("temp.txt", oldname);
	cout<<endl<<"Please collect your money and card";
}

void money_depoist(int pin){
	int iris_pin, temp1, temp2;
	string flag;
	
	cout<<"Enter your IRIS PIN :-- ";
	cin>>iris_pin;
	
	string s=to_string(iris_pin);
	if(s.length()!=4){
		cout<<"wrong PIN entered";
		exit(0);
	}
	
	if(s.length()==4){
		goto s2;
	}
	
	s2:
	account_nontrivial(iris_pin);
	
	cout<<"Enter the amount to deposit :-- ";
	cin>>temp1;
	
	while (iofile >> word){ 
		if(word.substr(0,7)=="Balance"){
    	flag= word.substr(8);    
		}
	}
	temp2=stoi(flag)+temp1;
	iofile.close();
	account_nontrivial(iris_pin);
	
	ofstream out("temp.txt", ios::out);
	while (iofile >> word){ 	
		if(word.substr(0,7)!="Balance"){
        	out<<word<<endl;
		}
	}
	out<<"Balance="<<temp2;
	
	out.close();
	iofile.close();
	
	char oldname[25];
	strcpy(oldname, filename.c_str());
	remove(oldname);
    rename("temp.txt", oldname);
    cout<<"Amount deposited successfully";
}

void change_pin(int pin){
	int iris_pin, temp1;
	string flag, s;
	
	cout<<"Enter your IRIS PIN :-- ";
	cin>>iris_pin;
	
	s=to_string(iris_pin);
	if(s.length()!=4){
		cout<<"wrong PIN entered";
		exit(0);
	}
	
	if(s.length()==4){
		goto s2;
	}
	
	s2:
	account_nontrivial(iris_pin);
	cout<<"Enter Your New Pin :-- ";
	cin>>temp1;
	s=to_string(temp1);
	if(s.length()!=4){
		cout<<endl<<"wrong PIN entered";
		exit(0);
	}
	
	ofstream out("temp.txt", ios::out);
	while (iofile >> word){ 	
		if(word.substr(0,3)!="Pin"){
        	out<<word<<endl;
		}
	}
	out<<"Pin="<<temp1;
	
	out.close();
	iofile.close();
	
	char oldname[25];
	strcpy(oldname, filename.c_str());
	remove(oldname);
    rename("temp.txt", oldname);
    cout<<endl<<"PIN changed successfully";
}

void add_aadhar_card(int pin){
	int iris_pin;
	long long int temp1;
	string flag, s;
	
	cout<<"Enter your IRIS PIN :-- ";
	cin>>iris_pin;
	
	s=to_string(iris_pin);
	if(s.length()!=4){
		cout<<"wrong PIN entered";
		exit(0);
	}
	
	if(s.length()==4){
		goto s2;
	}
	
	s2:
	account_nontrivial(iris_pin);
	while (iofile >> word){ 	
		if(word.substr(0,6)=="Aadhar"){
        	flag= word.substr(7);  
		}
	}
	if(flag.length()==12){
		cout<<endl<<"Aadhar already exist, Please visit your branch to update your aadhar";
		exit(0);
	}
	
	cout<<"Enter Your Aadhar Number :-- ";
	cin>>temp1;
	s=to_string(temp1);
	if(s.length()!=12){
		cout<<endl<<"wrong Aadhar number entered";
		exit(0);
	}
	iofile.close();
	account_nontrivial(iris_pin);
	
	ofstream out("temp.txt", ios::out);
	while (iofile >> word){ 	
		if(word.substr(0,6)!="Aadhar"){
        	out<<word<<endl;
		}
	}
	out<<"Aadhar="<<temp1;
	
	out.close();
	iofile.close();
	
	char oldname[25];
	strcpy(oldname, filename.c_str());
	remove(oldname);
    rename("temp.txt", oldname);
    cout<<endl<<"Aadhar added successfully";
}

void transfer_money_to_other_account(int pin){	
	int iris_pin, amount, temp;
	string s, acc, ifsc, flag;
	
	cout<<"Enter your IRIS PIN :-- ";
	cin>>iris_pin;
	
	s=to_string(iris_pin);
	if(s.length()!=4){
		cout<<"wrong PIN entered";
		exit(0);
	}
	
	if(s.length()==4){
		goto s2;
	}
	
	s2:
	account_nontrivial(iris_pin);
	while (iofile >> word){ 	
		if(word.substr(0,7)=="Balance"){
        	flag= word.substr(8);  
		}
	}
	iofile.close();
	account_nontrivial(iris_pin);
	
	cout<<"Enter the Account number to whom you want to tranfer money :-- ";
	cin>>acc;
	cout<<"Enter the IFSC code :-- ";
	cin>>ifsc;
	cout<<"Enter the amount to tranfer :-- ";
	cin>>amount;
	
	temp=stoi(flag);
	if(amount>temp){
		cout<<"\nYou do not have sufficient balance in your account";
		exit(0);
	}
	
	ofstream out("temp.txt", ios::out);
	while (iofile >> word){ 	
		if(word.substr(0,7)!="Balance"){
        	out<<word<<endl;
		}
	}
	out<<"Balance="<<(temp-amount);
	
	out.close();
	iofile.close();
	
	char oldname[25];
	strcpy(oldname, filename.c_str());
	remove(oldname);
    rename("temp.txt", oldname);
    cout<<"\nAmount tranfered successfully";
}

void mini_statement(int pin){	
	queue<int> q;
	
}

void add_PAN(int pin){
	int iris_pin;
	string flag, s, temp;
	
	cout<<"Enter your IRIS PIN :-- ";
	cin>>iris_pin;
	
	s=to_string(iris_pin);
	if(s.length()!=4){
		cout<<"wrong PIN entered";
		exit(0);
	}
	
	if(s.length()==4){
		goto s2;
	}
	
	s2:
	account_nontrivial(iris_pin);
	while (iofile >> word){ 	
		if(word.substr(0,3)=="Pan"){
        	flag= word.substr(4);  
		}
	}
	if(flag.length()==10){
		cout<<endl<<"Pan already exist, Please visit your branch to update your Pan";
		exit(0);
	}
	
	cout<<"Enter Your Pan Number :-- ";
	cin>>temp;
	if(temp.length()!=10){
		cout<<endl<<"wrong Pan number entered";
		exit(0);
	}
	iofile.close();
	account_nontrivial(iris_pin);
	
	ofstream out("temp.txt", ios::out);
	while (iofile >> word){ 	
		if(word.substr(0,3)!="Pan"){
        	out<<word<<endl;
		}
	}
	out<<"Pan="<<temp;
	
	out.close();
	iofile.close();
	
	char oldname[25];
	strcpy(oldname, filename.c_str());
	remove(oldname);
    rename("temp.txt", oldname);
    cout<<endl<<"Pan added successfully";
}

void fordelay(int j)
{   int i, k=0;
    for(i=0; i<j; i++)
         k++;
}

int main(){
	int choice, fingerprint_pin;
	
	s1:
	cout<<"Enter your FINGERPRINT PIN :-- ";
	cin>>fingerprint_pin;
	
	string s=to_string(fingerprint_pin);
	if(s.length()!=4){
		cout<<"wrong PIN entered";
		fordelay(1000000000);
		exit(0);
	}
	
	if(s.length()==4){
		system("cls");
		goto s2;
	}
	
	system("cls");
	goto s1;
	
	s2:
	cout<<" 1. Balance inquary\n";
	cout<<" 2. Withdrawal\n";
	cout<<" 3. Money depoist\n";
	cout<<" 4. Change pin\n";
	cout<<" 5. Mini statement\n";
	cout<<" 6. Add aadhar card\n";
	cout<<" 7. Add PAN\n";
	cout<<" 8. Transfer money to other account";
	
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	
	
	
	switch(choice){
		case 1: 
			balance_inquiry(fingerprint_pin);
			break;
			
		case 2:
			withdrawal(fingerprint_pin);
			break;
			
		case 3:
			money_depoist(fingerprint_pin);
			break;
			
		case 4:
			change_pin(fingerprint_pin);
			break;
			
		case 5:
			mini_statement(fingerprint_pin);
			break;
			
		case 6:
			add_aadhar_card(fingerprint_pin);
			break;
			
		case 7:
			add_PAN(fingerprint_pin);
			break;
			
		case 8:
			transfer_money_to_other_account(fingerprint_pin);
			break;
			
		default:
			cout<<endl<<"wrong choice entered, Please try again";
			
	}
	
	return 0;
	getch();
}
