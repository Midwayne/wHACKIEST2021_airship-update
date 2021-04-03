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
    int positive;

    public:
    	
    	void input();
        
    	
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
            
            cout<<"\nThe time when entering : "<<entry_hour<<":"<<entry_min<<":"<<entry_sec;
            cout<<"\nThe time when exiting : "<<exit_hour<<":"<<exit_min<<":"<<exit_sec<<"\n";
            
            
        }
        
        long getphone()
        {
            return phone;
        }
        
        int get_entry_hour()
        {
        	return entry_hour;
		}
        
        int get_entry_min()
        {
        	return entry_min;
		}
		
		 int get_exit_hour()
        {
        	return exit_hour;
		}
        
        int get_exit_min()
        {
        	return exit_min;
		}
		
		int get_exit_sec()
		{
			return exit_sec;
		}
		
		int get_entry_sec()
		{
			return entry_sec;
		}
		
		int get_positive()
		{
			return positive;
		}
		

};

		void customer_entry::input()
		{			
					
					system("CLS");
		            cout<<"\n Enter your name: ";
		            cin>>name;
		
		            if(strcmpi(name,"amongus")==0) //easter egg pls give marks
		            {
		            	cout<<"you are very sus hehehehehehehehehehehehe"<<"\n";
		            	system("pause");
		            	exit(0);
					}
		
		            cout<<"\n Enter your phone number: ";
		            cin>>phone;
		            
		            entry_time();
		 }

void intro()
{
	cout<<setw(328)<<"Contact Tracing Software";	
	cout<<setw(214)<<"by Aryan, Kushal and Shivam\n\n";
}


void infected_record(long infected_number)
{	
	
	system("CLS");
	cout<<"The details of the people who were in contact: "<<"\n";
	int flag = 0;
	int inf_entry_hour;
	int inf_entry_min;
	int inf_exit_sec;
	int inf_entry_sec;
	int inf_exit_hour;
	int inf_exit_min;
	customer_entry d;
	fstream file;
	file.open("customer_data.dat",ios::in|ios::app|ios::binary);
	file.seekg(ios::beg);
	
	
	while(file.read((char*)&d,sizeof(d)))
		{
			 
			 if(infected_number == d.getphone())
			 {
			 	flag=1;
				inf_entry_min = d.get_entry_min();
				inf_entry_hour = d.get_entry_hour();
				inf_exit_sec = d.get_exit_sec();
				inf_entry_sec = d.get_entry_sec();
				inf_exit_hour = d.get_exit_hour();
				inf_exit_min = d.get_exit_min();
		
	   		 }
		}
		if(flag==0)
		{
			cout<<"\n The number was not found."<<"\n";
			system("pause");
			return;
		}
	
	file.close();
	
	
	file.open("customer_data.dat",ios::in|ios::app|ios::binary);
	file.seekp(0, ios::beg);
	while(file.read((char*)&d,sizeof(d)))
	{
		
if(d.getphone()!=infected_number){

	if(d.get_exit_hour() >= inf_entry_hour && d.get_exit_hour() <= inf_exit_hour && d.get_exit_min() >= inf_entry_min && d.get_exit_min() <= inf_exit_min && d.get_exit_sec() >= inf_entry_sec && d.get_exit_sec() <= inf_exit_sec) 

	
		{
		
			d.output();
			
		}
		 	
	else if(d.get_entry_hour() <= inf_exit_hour && d.get_entry_hour() >= inf_entry_hour && d.get_entry_min() <= inf_exit_min && d.get_entry_min() >= inf_exit_min && d.get_entry_sec() <= inf_exit_sec && d.get_entry_sec() >= inf_entry_sec)		 	
		 {
		 	
		 	d.output();
		 
		 	
		}
			
		 
	else if(d.get_entry_hour() <= inf_entry_hour && d.get_exit_hour() >= inf_exit_hour && d.get_entry_min() <= inf_entry_min && d.get_exit_min() >= inf_exit_min && d.get_entry_sec() <= inf_entry_sec && d.get_exit_sec() >= inf_exit_sec)
		  {
		  	
		 	d.output();
		
				
			
		 }
	else if(d.get_entry_hour() >= inf_entry_hour && d.get_exit_hour() <= inf_exit_hour && d.get_entry_min() >= inf_entry_min && d.get_exit_min() <= inf_exit_min && d.get_entry_sec() >= inf_entry_sec && d.get_exit_sec() <= inf_exit_sec)
		 	{
		 	d.output();
		
		 	}
	}
	}
	cout<<"\n";
	system("pause");
	
	file.close();
}



int main()
{	
	int choice;
	long phone_search;
	fstream file; 
	customer_entry s;
	
	do{
		

		
		system("CLS");
		intro();
		
		
		
		cout<<"Menu\n1:Customer Entry\n2:Customer Exit\n3:Report Case\n4:Show all customer details\n5:Exit\n";
		cout<<"\n\nEnter your choice: ";
		cin>>choice;
	
	
		if(choice < 6)
			{
			
				switch(choice)
				{
					case 1: {
								
								s.input();
								file.open("customer_data.dat",ios::in|ios::app|ios::binary);
							    file.write((char*)&s,sizeof(s));
							    file.close();
								break;
							}
							
							
					case 2:{
							system("CLS");
							cout<<"Enter your phone number: ";
								   cin>>phone_search;
								   file.open("customer_data.dat",ios::in|ios::out|ios::binary);
								   file.seekg(ios::beg);
								    while(file.read((char*)&s,sizeof(s)))
								    {
								    	if(phone_search==s.getphone())
								    	{			
								    	s.exit_time();
								    	file.seekg(file.tellg()-sizeof(s), ios::beg); 
								    	file.write((char*)&s,sizeof(s));
										}	
									}
									file.close();
								break;
							}
							
							
					case 3:{
								system("CLS");
								cout<<"Enter the phone number of the infected: ";
								cin>>phone_search;
								infected_record(phone_search);
								break;
						   }
						   
					case 4:{	
								system("CLS");
								fstream file;
								file.open("customer_data.dat",ios::in|ios::app|ios::binary);
								file.seekg(ios::beg);
							    while(file.read((char*)&s,sizeof(s)))
							    {
							    	s.output();
								}
								cout<<"\n";
								system("pause");
								file.close();
								break;
					}
						   
					case 5:{
						exit(0);
						
					}
				}
			
		   }
		else
		{
			cout<<"Enter a valid input >:("<<"\n";
			system("pause");
			system("CLS");
		}
				
	   }while(choice != 5);
	
	
	return 0;
}
