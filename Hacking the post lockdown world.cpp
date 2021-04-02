#include<bits/stdc++.h>

using namespace std;

class customer_entry
{
    char name[50];
    long phone;
    
    int entry_hour;
    int entry_min; 
    int entry_sec;
    int exit_hour;
    int exit_min; 
    int exit_sec;

    public:
    	
    	void input()
        {
            cout<<"\nEnter your name: ";
            cin>>name;

            cout<<"\nEnter your phone number: ";
            cin>>phone;
            
            entry_time();
        }
    	
    	void exit_time()
    	{
    		time_t now = time(0);
        	tm *ltm = localtime(&now);
            exit_hour = ltm->tm_hour;
            exit_min = ltm->tm_min;
            exit_sec = ltm->tm_sec;
		}
    	
    	void entry_time()
        {
        	time_t now2 = time(0);
        	tm *ltma = localtime(&now2);
            entry_hour = ltma->tm_hour;
            entry_min = ltma->tm_min;
            entry_sec = ltma->tm_sec;

        }
        
        
        void output()
        {
            cout<<"\nName: ";
            cout<<name;

            cout<<"\nPhone number: ";
            cout<<phone;
            
            cout<<"\nThe time when entering: "<<entry_hour<<":"<<entry_min<<":"<<entry_sec;
            cout<<"\nThe time when exiting: "<<exit_hour<<":"<<exit_min<<":"<<exit_sec;
            
            
        }

        long getphone()
        {
            return phone;
        }

};

void intro()
{
	cout<<setw(328)<<"Contact Tracing Software";	
	cout<<setw(214)<<"by Aryan, Kushal and Shivam\n\n";
}

void sus();
{
	int abc=0;
	long phno_infected;
	cout<<"Enter phone number: ";
	cin>>phno_infected;
	
	while(s[abc].phone!=phno_infected)
	{
		++abc;
	}
	
	if(s[abc].phone==phno_infected)
	{
		cout<<"Details of the infected person/n";
		s[abc].output;
	}
	
	else()
	{
		cout<<"Record not found/n";
		break;
	}
	
}

int main()
{	
	long phone_search;
	fstream file; 
	customer_entry s[100];
	int i=0;
	int choice;
	
	loop: 
	intro();
	cout<<"Menu\n1:Customer Entry\n2:Customer Exit\n3: Show All Customers\n4:Report Case\n5:Exit\n";
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	

	switch(choice)
	{
		case 1: {
				
				s[i].input();
				file.open("customer_data.dat",ios::in|ios::app|ios::binary);
			    file.write((char*)&s[i],sizeof(s[i]));
			    file.close();
			    ++i;
				break;
				}
				
				
		case 2:{
			
		cout<<"Enter your phone number: ";
			   cin>>phone_search;
			   file.open("customer_data.dat",ios::in|ios::out|ios::binary);
			   file.seekg(ios::beg);
			    while(file.read((char*)&s[i],sizeof(s[i])))
			    {
			    	if(phone_search==s[i].getphone())
			    	{			
			    	s[i].exit_time();
			    	file.seekg(file.tellg()-sizeof(s[i]), ios::beg); 
			    	file.write((char*)&s[i],sizeof(s[i]));
					}	
				}
				++i;
			break;
				}
				
				
		case 3:{
			
			break;
			   }
		
		case 4:{
			sus();
			break;
		}
		case 5:{
			
			exit(0);
		}
				
	}
	
	system("CLS");
	goto loop;
	return 0;
}
