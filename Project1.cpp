#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;

struct accountinfo{
	string firstname;
	string lastname;
	string email;
	string pass;
	char gender;
	int dateofbirth[3];
	long long int phone;
}reg;

void login();
void checking_input(string mail,string pass);
void forgotten_password();
bool checking_newemail(string newemail);
void registration();
void openingfile(string mail);
void creatingfile(accountinfo regg);
void viewinformation(string mail);
void writedata(string mail);
void deleteaccount(const string mail);

int main(){
        cout << "\t\t\tWELCOME TO SOCIAL MEDIA\n\t\t\tLOGIN PAGE\n\n";
        login();
        return 0;
}

void login(){
        string mail,pass;
        cout << "\n\t\t\t\tEmail:     ";
        cin >> mail;
        cout << "\t\t\t\tPassword:  ";
        cin >> pass;
        checking_input(mail,pass);
        return;
}

void checking_input(string mail,string pass){
	string emaily,passy;
	int count;
	bool option,option1;
	ifstream emails;
	emails.open("emails.txt");
        if (!emails.is_open()){
                cout << "\t\t\tError! Please Bring all files in same folder.";
                exit;
        }
	while(emails >> emaily >> passy){

                if (mail==emaily&&pass==passy){
                        cout << "\n\t\t\tSuccessfully logined !";
                        openingfile(mail);
                        option1=1;
                        break;
                }
                
		count++;
	}
        emails.close();
        if (!option1){
        	cout << "\n\t\t\tIncorrect Email or Password !\n";
        	cout << "\t\t\tDon't have an account? Press 1 for Registration and 0 for Forgotten Password ! : ";
        	cin >> option;
        	if (option==1){
        	        registration();
        	}
        	else{
                        forgotten_password();
        	}
        	        
	}
        return;
}

void forgotten_password(){
        string email,pass,forgetemail;
        bool choice;
        cout << "\n\t\t\tRecovering your Password.";
        cout << "\n\t\t\tYou have to write correct email.\n";
        cout << "\n\t\t\tEmail: ";
        cin >> forgetemail;
        ifstream emailrecover;
        emailrecover.open("emails.txt");
        if (!emailrecover.is_open()){
                cout << "\t\t\tError! Please Bring all files in same folder.";
                exit;
        }
        while(emailrecover >> email >> pass){
                if (email==forgetemail){
                        cout << "\t\t\tYour saved Password is: " << pass;
                        break;
                }
        }
        emailrecover.close();
        do{
                cin.clear();
                cin.ignore();
                cout << "\n\t\t\tDo you want to Login your account(Press 1) OR close the Program(Press 0):  ";
                cin >> choice;
        }while(!cin);
        if (choice==1)
                login();
        else 
                exit;
        return;
}

bool checking_newemail(string newemail){
        string newemaily;
	bool option;
	ifstream emails;
	emails.open("emails.txt");
        if (!emails.is_open()){
                cout << "\t\t\tError! Please Bring all files in same folder.";
                exit;
        }
	while(emails >> newemaily){

                if (newemail==newemaily){
                        cout << "\n\t\t\tThis email is already registered.";
                        cout << "\n\t\t\tPress 1 to Login or press 0 to retype email.";
                        cin >> option;
                        if (option==1){
                                login();
                                break;
                        }
                        else{
                                return 1;
                        }

                        break;
                }
                emails.close();
        }
        return 0;
}

void registration(){

	cout << "\n\t\t\tLets start Registration.\n";
        bool result;
	do{
                cin.clear();
                cin.ignore();
                cout << "\t\t\tFirst Name less than 15 characters : ";
                cin >> reg.firstname;
	}while(!cin ||reg.firstname.length()>=15);

	do{
                cin.clear();
                cin.ignore();
                cout << "\t\t\tLast Name less than 15 characters : ";
                cin >> reg.lastname;
	}while(!cin ||reg.lastname.length()>=15);

	do{
                cin.clear();
                cin.ignore();
                cout << "\t\t\tCreate an email : ";
                cin >> reg.email;
                result=checking_newemail(reg.email);
	}while(!cin || result);

	do{
                cin.clear();
                cin.ignore();
                cout << "\t\t\tSet a Password of 8 or more characters : ";
                cin >> reg.pass;
	}while(!cin ||reg.pass.length()<8);

	cout << "\t\t\tWhat is your gender:-\n\t\t\t Write\n\t\t\t M for Male\n\t\t\t F for Female\n\t\t\t O for Other\n\t\t\t P for Prefer not to say \n";
	char genderr[8]={'M','m','F','f','O','o','P','p'};
	bool abc;

	do{
                cin.clear();
                cin.ignore();
                cout << "\n\t\t\t Your choice :   ";
                cin >> reg.gender;

                for (int i=0;i<8;i++){
                        if (reg.gender==genderr[i]){
                                abc=0;
                                break;
                        }
                        else
                                abc=1;
                }
	}while(!cin ||abc==1);

	cout << "\t\t\tDate of Birth :- ";

	do{
                cin.clear();
                cin.ignore();
                cout << "\n\t\t\t Write Day from 1 to 31 : ";
                cin >> reg.dateofbirth[0];
	}while(!cin || reg.dateofbirth[0]>31 || reg.dateofbirth[0]<1);

	do{
                cin.clear();
                cin.ignore();
                cout << "\n\t\t\t Write Month from 1 to 12 : ";
                cin >> reg.dateofbirth[1];
	}while(!cin || reg.dateofbirth[1]>12 || reg.dateofbirth[1]<1);

	do{
                cin.clear();
                cin.ignore();
                cout << "\n\t\t\t Write Year from 1900 to 2023 : ";
                cin >> reg.dateofbirth[2];
	}while(!cin || reg.dateofbirth[2]>2023 || reg.dateofbirth[2]<1900);

	do{
                cin.clear();
                cin.ignore();
                cout << "\n\t\t\t Write Valid Phone Number 11 digits  : ";
                cin >> reg.phone;
	}while(!cin || reg.phone>99999999999 || reg.phone<999999999);
	creatingfile(reg);
	return;
}

void creatingfile(accountinfo regg){
        string filename=(".txt");
        ofstream emails;
        emails.open("emails.txt",ios::app);
        if (!emails.is_open()){
                cout << "\t\t\tError! Please Bring all files in same folder.";
                exit;
        }
        ofstream newuser(regg.email+filename);
        newuser << "Firstname:     " << regg.firstname << endl;
        newuser << "Lastname:      " << regg.lastname << endl;
        newuser << "Gender:        " << regg.gender << endl;
        newuser << "Date of Birth: " <<regg.dateofbirth[0]<< "/" <<regg.dateofbirth[1]<< "/"<< regg.dateofbirth[2]<< endl;
        newuser << "Phone:         " <<regg.phone << endl;
        newuser.close();
        cout << "\n\t\t\tSuccessfully Registered !\n" ;
        emails << endl << regg.email << " " << regg.pass;
        emails.close();
        cout << "\t\t\tNow Login your account.";
        login();
        return;
}

void openingfile(string mail){
        int choicee;
        cout << "\n\t\t\tWhat do you want to do?\n";
        cout << "\t\t\tPress 1 to view your information.";
        cout << "\n\t\t\tPress 2 to add any data to your account.";
        cout << "\n\t\t\tPress 3 to Permanently delete your account.";
        cout << "\n\t\t\tPress 0 to exit.";
        do{
                cin.clear();
                cin.ignore();
                cout << "\n\t\t\tChoose a number from 0-3: ";
                cin >> choicee;
        }while(!cin || choicee<0 || choicee>3);
        if (choicee==1)
                viewinformation(mail);
        else if (choicee==2)
                writedata(mail);
        else if (choicee==3){
                //mail=mail+".txt";
                deleteaccount(mail);
        }
        else if (choicee==0){
                exit;
        }
        return;
}

void viewinformation(string mail){
        string line,file={".txt"};
        cout << "\n\t\t\tYour Personal information is:- \n";
        ifstream viewdata;
        viewdata.open(mail+file);
        if (!viewdata.is_open()){
                cout << "\t\t\tError! Please Bring all files in same folder.";
                exit;
        }
        while(!viewdata.eof()){
                getline(viewdata,line);
                cout << "\t\t\t" << line << endl;
        }
        viewdata.close();
        openingfile(mail);
        return;
}

void writedata(string mail){
        string data,file={".txt"};
        ofstream writedata;
        writedata.open(mail+file,ios::app);
        if (!writedata.is_open()){
                cout << "\t\t\tError! Please Bring all files in same folder.";
                exit;
        }
        cout << "\n\t\t\tWrite down all the data here that you want to add in to your account.\n\t\t\t: ";
        cin >> data;
        writedata << data;
        writedata.close();
        openingfile(mail);
        return;
}

void deleteaccount(string mail){
        string yourmail=mail;
        mail=mail+".txt";
        const char* path=mail.c_str();
        bool choiceee;
        cout << "\n\t\t\tDo you really want to delete your account.\tIf YES Press \"1\" Otherwise Press \"0\" to go back. : ";
        cin >> choiceee;
        if (choiceee){
                if(remove(path)){
                        cout << "\t\t\tYour account successfully deleted.";
                }
                else{
                        cout << "\t\t\tError in deleting your account.";
                }
        }
        else{
                openingfile(yourmail);
        }

        return;
}
