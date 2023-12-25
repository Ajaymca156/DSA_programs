
#include "iostream.h"
#include "conio.h"
class STACK
{
		//  data
		int A[100],size, top;
	public:
		// operations
		STACK(int);
		void PUSH(int);
		int POP();
		int PEEP();
		void VIEW_STACK();
};
STACK::STACK(int par)
{
	// def of function
	size = par;
	top = 0;
}
void STACK::PUSH(int ele)
{
	// def of function
	if(top == size)
	{
		cout<<endl<<"Stack is full";
		return;
	}
	top = top+1;
	A[top] = ele;
}
int STACK::POP()
{
	// def of function
	if(top == 0)
	{
		cout<<endl<<"Stack is empty";
		return NULL;
	}
	int ele = A[top];
	top = top-1;
	return ele;
}
int STACK::PEEP()
{
	// def of function
	if(top == 0)
	{
		cout<<endl<<"Stack is empty";
		return NULL;
	}
	return A[top];
}
void STACK::VIEW_STACK()
{
	// def of function
	if(top == 0)
	{
		cout<<endl<<"Stack is empty";
		return;
	}
	cout<<endl<<"Stack elemets are : ";
	for(int i=1;i<=top;i++)
		cout<<A[i]<<" " ;
}

void MENU()
{
	int ele,n,opt;
	cout<<endl<<"Enter the size of stack : ";
	cin>>n;
	STACK obj(n);
	do
	{
		cout<<endl<<"1 PUSH";
		cout<<endl<<"2 POP";
		cout<<endl<<"3 PEEP";
		cout<<endl<<"4 VIEW_STACK";
		cout<<endl<<"5 EXIT MENU";
		cout<<endl<<"================\n";
		cout<<endl<<"Enter your choice : ";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<endl<<"Enter ele to push : ";
				cin>>ele;
				obj.PUSH(ele);
				break;
			case 2:
				ele = obj.POP();
				if(ele)
					cout<<endl<<"Poped ele = "<<ele;
				break;
			case 3:
				ele = obj.PEEP();
				if(ele)
					cout<<endl<<"The top element of stack is "<<ele;
				break;
			case 4:
				obj.VIEW_STACK();
				break;
			case 5:
				return;
			default:
				cout<<endl<<"invalid input";
		}
	}while(1);

}
void main()
{
	clrscr();
	MENU();
	getch();

}