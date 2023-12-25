
#include "iostream.h"
#include "conio.h"
//--------data strcture---------------------------
class LIST
{
		//  data
		int A[100],n,size;
	public:
		// operations
		LIST(int);
		void ADD_FIRST(int);
		void ADD_LAST(int);
		void ADD_AT_POS(int,int);
		int DEL_FIRST();
		int DEL_LAST();
		int DEL_FRM_POS(int);
		void VIEW_LIST();
};
//------------operation def-----------------------
LIST::LIST(int par)
{
	size = par; // capacity of list
	n = 0; // current no of elements
}
//------------------------------------------------
void LIST::ADD_FIRST(int ele)
{
	if(n == size)
	{
		cout<<endl<<"LIST is full";
		return;
	}
	// shift elements to right
	for(int i=n;i>=1;i--)
		A[i+1]=A[i];
	A[1] = ele; // add at first
	n = n+1;
}
//------------------------------------------------
void LIST::ADD_LAST(int ele)
{
	if(n == size)
	{
		cout<<endl<<"LIST is full";
		return;
	}
	n = n+1;
	A[n] = ele; // add at last
}
//------------------------------------------------
void LIST::ADD_AT_POS(int ele,int pos)
{
	if(n == size)
	{
		cout<<endl<<"LIST is full";
		return;
	}
	// shift elements to right
	for(int i=n;i>=pos;i--)
		A[i+1]=A[i];
	A[pos] = ele; // add at first
	n = n+1;
}
//------------------------------------------------
int LIST::DEL_FIRST()
{
	if(n == 0)
	{
		cout<<endl<<"LIST is empty";
		return NULL;
	}
	int ele = A[1];
	// shift elements to left
	for(int i=1;i<=n-1;i++)
		A[i]=A[i+1];
	n = n-1;
	return ele;
}
//------------------------------------------------
int LIST::DEL_LAST()
{
	if(n == 0)
	{
		cout<<endl<<"LIST is empty";
		return NULL;
	}
	int ele = A[n];
	n = n-1;
	return ele;
}
//------------------------------------------------
int LIST::DEL_FRM_POS(int pos)
{
	if(n == 0)
	{
		cout<<endl<<"LIST is empty";
		return NULL;
	}
	int ele = A[pos];
	// shift elements to left
	for(int i=pos;i<=n-1;i++)
		A[i]=A[i+1];
	n = n-1;
	return ele;
}
//------------------------------------------------
void LIST::VIEW_LIST()
{
	// def of function
	if(n == 0)
	{
		cout<<endl<<"LIST is empty";
		return;
	}
	cout<<endl<<"LIST elemets are : ";
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" " ;
}
//------------------------------------------------
void MENU()
{
	int ele,n,opt,pos;
	cout<<endl<<"Enter the size of LIST : ";
	cin>>n;
	LIST obj(n);
	do
	{
		cout<<endl<<"1 Add @ First";
		cout<<endl<<"2 Add @ Last";
		cout<<endl<<"3 ADD @ Position";
		cout<<endl<<"4 Delete from First";
		cout<<endl<<"5 Delete from Last";
		cout<<endl<<"6 Delte from Position";
		cout<<endl<<"7 View List";
		cout<<endl<<"8 Exit Menu";
		cout<<endl<<"====================\n";
		cout<<endl<<"Enter your choice : ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<endl<<"Enter ele to Add First : ";
				cin>>ele;
				obj.ADD_FIRST(ele);
				obj.VIEW_LIST();
				break;
			case 2:
				cout<<endl<<"Enter ele to Add Last : ";
				cin>>ele;
				obj.ADD_LAST(ele);
				obj.VIEW_LIST();
				break;
			case 3:
				cout<<endl<<"Enter ele to Add at Position : ";
				cin>>ele;
				cout<<endl<<"Enter ele position : ";
				cin>>pos;
				obj.ADD_AT_POS(ele,pos);
				obj.VIEW_LIST();
				break;
			case 4:
				ele = obj.DEL_FIRST();
				if(ele)
				{
					cout<<endl<<"Deleted First ele = "<<ele;
					obj.VIEW_LIST();
				}
				break;
			case 5:
				ele = obj.DEL_LAST();
				if(ele)
				{
					cout<<endl<<"Deleted Last ele = "<<ele;
					obj.VIEW_LIST();
				}
				break;
			case 6:
				cout<<endl<<"Enter ele position to delete : ";
				cin>>pos;
				ele = obj.DEL_FRM_POS(pos);
				if(ele)
				{
					cout<<endl<<"Deleted Ele from position "<<pos<<" is "<<ele;
					obj.VIEW_LIST();
				}
				break;
			case 7:
				obj.VIEW_LIST();
				break;
			case 8:
				return;
			default:
				cout<<endl<<"invalid input";
		}
	}while(1);

}
//------------------------------------------------
void main()
{
	clrscr();
	MENU();
	getch();

}
//------------------------------------------------
