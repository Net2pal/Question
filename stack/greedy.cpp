#include<iostream>
#include<stack>
using namespace std;
int getvalue(char a)
{
	switch(a)
	{
		case 'A':return 0;
		break;
		case 'B':return 1;
		break;
		case 'C':return 2;
		break;
		case 'D':return 3;
		break;
		case 'E':return 4;
		break;
		case 'F':return 5;
		break;
		case 'G':return 6;
		break;
		case 'H':return 7;
		break;
		case 'I':return 8;
		break;
		case 'J':return 9;
	}
}
int check(char a,char b)
{
	if(a=='A' && b=='J')
	return 0;
	else if(a=='B' && b=='I')
	return 1;
	else if(a=='c' && b=='H')
	return 2;
	else if (a=='D' && b=='G')
	return 3;
	else if(a=='E' && b=='F')
	return 4;
	else
	return -1;
}
int main()
{
	int a;
	cin>>a;
	int value=0;
	stack<char> ch;
	int max;
	
	int base=1;
		for(int i=0;i<a;i++)
		{
		base =1;
			char c;
			string::iterator it;
			
			string wordString;
			cin>>wordString;

			for (it= wordString.begin(); it != wordString.end(); it++)
			{	
				ch.push(*it);
  
			}
			while(!ch.empty())
			{
			
		 		c=ch.top();
				ch.pop();
				value+=getvalue(c)*base;
				base*=10;
			//	cout<<value<<" "<<c<<endl;
				if(ch.size()!=0)
				{
			
						char ab=ch.top();
					
					int abc=check(c,ab);
					if(abc!=-1)
					{
						value+=abc*base;
						ch.pop();
						base*=10;
			
					}
			}
		//	cout<<"nkn"<<endl;
			
		}
	
		}
		cin>>max;
		if(value<max)
		{
			std::cout<<"INNOCENT";
		}
		else
		{
			std::cout<<"GREEDY";
		}
		return 0;
}
