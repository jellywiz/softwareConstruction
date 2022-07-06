#include<iostream>
#include<cstring>
#include <queue>
#include<fstream>
#include <windows.h>
using namespace std;

class staff
{
	private:
		string name;
		string password;
	public:
		void setname(string n)
		{
			name = n;			
		}	
		string getname()
		{
			return name;
		}
		void setpassword(string p)
		{
			password = p;
		}
		string getpassword()
		{
			return password;
		}	
};

class Bank
{	

	public :
	string email;
	 string pass;
		string adress;
		  double account; //add money
			
			
			double getaccount()
			{
            	return account;
			}
			
			
	
			
};

/*#########################################################################################*/



 class costumer 
 {
 	private :
 		string name;
 		string adress;
 		string phone;
 		string comment;
 	
 		Bank *bank;//aggregation
 		

 		
 		public:
 			//just for print
			void getinput()
			{
			
				
		    	}
 			
 				//monitors
 		void setname(string n)
			 {
				 
 				name=n;
 			}
 			
 			
 			void setage(string a)
 			{
			 
 				adress=a;
 				
			}
			
			void setphone(string p)
			{
			phone=p;
			 }
			 
			 
 	
 };
class medicine
{
	protected:
	 double price[10];
	 string p[10];
	 int n;
	 int sales[10];
	 costumer cos;
	 queue<int> myQ;
	 
	 
	 
	public:
	medicine();
	
	
	
	
};

medicine::medicine()
{
	ifstream file;
	file.open("medicine.txt");
	n=0;
	for(int i=0;i<10;i++)
	sales[i]=0;
	while(!file.eof())
	{
	file>>p[n];
	file>>price[n];
	n++;
	}
	n--;
}


class  user : public medicine
{
	public:
		void customer();
		void staff();
	
};

void user ::customer()
{
	cout<<"\nLogged in as customer\n";
	int ch;
	while(ch!=4)
	{
		
		cout<<"\n\nMENU";
		cout<<"\n1.View"
		<<"\n2.Search"
		<<"\n3.Buy"
		<<"\n4.Exit"
		<<"\nEnter choice-> ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				cout<<"\nThose are the type of medicine we have :)\n";
				for(int i=0;i<n;i++)
				{
				
					cout<<"\n"<<i+1<<". "<<p[i]<<"\t"<<price[i]<<"$"<< endl;;
				
				}
	
				
			
			
				
				break;
			}
			case 2:
			{
				string s;
				cout<<"Enter the medicine Name: ";
				cin>>s;
				for(int i=0;i<n;i++)
				{
					if(p[i]==s)
					{
					
						cout<<"\n"<<p[i]<<"\t"<<price[i]<<"$";
					}
				}
				break;
			}
			case 3:
			{
				int item,no;
				double cost=0;
				char c;
				cout<<"\nThose are the type of medicine we have :)\n";
				for(int i=0;i<n;i++)
				{
					cout<<"\n"<<i+1<<". "<<p[i]<<"\t"<<price[i]<<"$";
				}
				while(c!='n')
				{
					cout<<"\nSelect the medicine Number ?? -> ";
					cin>>item;
					item--;
					cout<<"\nQuantity: ";
					cin>>no;
					sales[item]=no;
					cost=cost+price[item]*no;
					cout<<"\n Do you want to buy more medicine  (y/n): ";
					cin>>c;
				}
				cout<<"\nTotal cost: "<<cost<<"$";
				cos.getinput();
				break;
			}
		}
		
		
	}
	cout<<"\nExiting as Customer\n";
	system("pause");

}


void user::staff()
{
	cout<<"\nLogged in as Staff\n";
	int ch;
	string name;
	int password;
	cout<<"Please enter you name: "<< endl;
	cin>> name;
	cout<<"Welcome "<< name<< endl;
	cout<<"Please enter you password: "<< endl;
	cin>> password;
	if (password == 123)
	{
		while(ch!=3)
	{
		
		cout<<"\n1.Change price"
		<<"\n2.Delete medicine"
		<<"\n3.Add medicine"
		<<"\n4..Generate report"
		<<"\n5..Exit"
		<<"\nEnter choice-> ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
			{
				double no;
				int item;
				cout<<"\nType of medicine:\n";
				for(int i=0;i<n;i++)
				{
					
					cout<<"\n"<<i+1<<". "<<p[i]<<"\t"<<price[i]<<"$";
					
				}
				cout<<"\n\nSelect the medicine no: ";
				cin>>item;
				item--;
				cout<<"\nNew price: ";
				cin>>no;
				price[item]=no;
				break;
			}
			
			case 2:
				{
					double no;
				int item;
				string nwma;
				cout<<"\nType of medicine:\n";
				for(int i=0;i<n;i++)
				{
					
					cout<<"\n"<<i+1<<". "<<p[i]<<"\t"<<price[i]<<"$";
					
				}
				cout<<"\n\nSelect the medicine no to delete: ";
				cin>>item;
				item--;
				no=0;
				nwma=="null";
				price[item]=no;
				p[item]="null";
				break;	
				}
			
			case 3:
				{
						double priced;
						int item;
				string nwma;
				ofstream MyFile("medicine.txt", std::ios_base::app);
						cout<<"\nType of medicine:\n";
			for(int i=0;i<n;i++)
				{
					
					cout<<"\n"<<i+1<<". "<<p[i]<<"\t"<<price[i]<<"$";
					
				}
				item++;
					cout<<"\n\add the medicine name: ";
				cin>>nwma;
				
					cout<<"\n\add the medicine price: ";
				cin>>priced;
				
				p[item]=nwma;
				price[item]=priced;
				MyFile << nwma <<" "<< priced <<"\n";
				MyFile.close();
				
					for(int i=0;i<n;i++)
				{
					
					cout<<"\n"<<i+1<<". "<<p[i]<<"\t"<<price[i]<<"$";
					
				}
				cout<<"\n"<<9<<". "<<p[item]<<"\t"<<price[item]<<"$";
				
					break;
					
				}
			case 4:
			{
				double cost,tcost=0;
				
				cout<<"\n Item\t Quantity\t Price";
				for(int i=0;i<n;i++)
				{
				
					cost=sales[i]*price[i];
					tcost+=cost;
					cout<<"\n"<<i+1<<". "<<p[i]<<"\t"<<sales[i]<<"\t"<<cost<<"$\n";
				
				}
				cout<<"\nTotal earnings: "<<tcost<<"$\n";
		
				
			
				break;
			}
			
			
		}
	}
	}
	
	
	cout<<"\nExiting as Staff\n";
	system("pause");
} 

int main()
{
	int ch;
	medicine p;
	user u;
	system("Color 7C");
	cout<<"Welcome to our pharmacy mangment system"<<endl;
	
	while(ch!=3)
	{
		Beep(523,500);
		cout<<"\nLogin as:\n";
		cout<<"\n1.Customer"
		<<"\n2.Staff"
		<<"\n3.Exit"
		<<"\nEnter choice-> ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				u.customer(); 
				break;
			}
			case 2:
			{
				u.staff();
				break;
			}
			
			
		}
		
		
	}
	
	cout<<"\nExiting...\n";
	Beep(784,500);
	system("pause");
	
	return 0;
}
