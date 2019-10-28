#include<bits/stdc++.h>
using namespace std;


string word, filename;
ifstream infile;
fstream iofile;

void account_nontrivial(int pin){
	if(pin==5432){
	iofile.open("Amardeep.txt");
	filename="Amardeep.txt";
	}
	if(pin==4321){
	iofile.open("Dimple.txt");
	filename="Dimple.txt";
	}
	if(pin==5176){
	iofile.open("Himanshu.txt");
	filename="Himanshu.txt";
	}
	if(pin==5378){
	iofile.open("Sharad.txt");	
	filename="Sharad.txt";
	}
	if(pin==4001){
	iofile.open("Yash.txt");
	filename="Yash.txt";
	}
}

void account_trivial(int pin){
	if(pin==2345){
	iofile.open("Amardeep.txt");
	filename="Amardeep.txt";
	}
	if(pin==1234){
	iofile.open("Dimple.txt");
	filename="Dimple.txt";
	}
	if(pin==6715){
	iofile.open("Himanshu.txt");
	filename="Himanshu.txt";
	}
	if(pin==8735){
	iofile.open("Sharad.txt");	
	filename="Sharad.txt";
	}
	if(pin==1004){
	iofile.open("Yash.txt");
	filename="Yash.txt";
	}
}

void balance_inquary(int pin){	
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
	int temp1, temp2;
	string flag;
	account_trivial(pin);
	
	cout<<"Enter the amount to deposit :-- ";
	cin>>temp1;
	
	while (iofile >> word){ 
		if(word.substr(0,7)=="Balance"){
    	flag= word.substr(8);    
		}
	}
	temp2=stoi(flag)+temp1;
	iofile.close();
	account_trivial(pin);
	
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
	cout<<"Enter Your New Fingerprint_PIN :-- ";
	cin>>temp1;
	
	ofstream out("temp.txt", ios::out);
	while (iofile >> word){ 	
		if(word.substr(0,15)!="Fingerprint_PIN"){
        	out<<word<<endl;
		}
	}
	out<<"Fingerprint_PIN="<<temp1;
	
	out.close();
	iofile.close();
	
	char oldname[25];
	strcpy(oldname, filename.c_str());
	remove(oldname);
    rename("temp.txt", oldname);
    cout<<endl<<"Fingerprint PIN changed successfully";
}

void mini_statement(int pin){
}

void add_aadhar_card(int pin){
}

void add_PAN(int pin){
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
	cout<<" 4. Change fingerprint pin\n";
	cout<<" 5. Mini statement\n";
	cout<<" 6. Add aadhar card\n";
	cout<<" 7. Add PAN\n";
	
	cout<<"\nEnter your choice: ";
	cin>>choice;
	
	
	
	switch(choice){
		case 1: 
			balance_inquary(fingerprint_pin);
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
			
	}
	
	return 0;
}
