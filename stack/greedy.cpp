/* You know that summers are at peak this year and every day is hot and due to this everyone is using coolers and ACs and a lot of electricity is consumed by the people. You are living in a hostel and your hostel owner decided to charge extra for electricity consumption. To achieve this he put one separate electricity meter for every room and connected all those meters to central meter.But the hostel owner is a bit greedy and wants to manipulate the meters to show a reading that is more than the actual consumption of electricity. He also encrypted all the meters with alphabets. The technique he used for encrypting is as follows:Every meter has 6 Alphabets i.e. 6 digits.Every alphabet is in upper case.Allowed alphabets are A, B, C, D, E, F, G, H, I, J.
A corresponds to 0, B = 1 and similarly C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9
The interpretation rules change as follows:
If the alphabet next to J is A, then J represents 0. Similarly, if the alphabet after I is B, then I counts as 1 (and not 8), the alphabet after H is C, then H represents 2. The same is true if D follows G and if E follows F. Note that A, B, C, D and E will always retain their respective values. When J is not followed by A, J will represent 9 and similar rules for I, H, G and F
You are given central meter reading and encrypted readings of all the meters in the hostel. Your task is to find out whether the owner is Greedy or Innocent. If he is greedy then print the unit difference otherwise print innocent.
Owner is greedy if and only if 
(units of all meters in the hostel except central meter < central meter units)
Input Format:
First line contains an integer N, giving the number of rooms in the hostel. 
The next line contains N strings each of length 6 characters giving the readings of the meters in the rooms
The next line contains an integer that gives the reading in the central meter
Output Format:
First line containing either GREEDY or INNOCENT
If the first line is GREEDY, the next line should contain the difference (as a decimal number) between the central meter reading and the consumption shown in the rooms.
 Constraints:
Number of rooms <= 100 
Example 1
Input 
3 
JAABHF JAACJA JAACDA 
500

Output 
GREEDY 
105

Explanation 
In the reading JAABHF, J represents 0 since it is followed by A, and hence the reading is 000175. Similarly, the other readings are 000200 and 000230. The total of the readings in the rooms is 605 and the central meter reading is 500. Thus the owner is GREEDY and he stole 605-500 = 105 units.

Example 2

Input 
8 
JAACJA JAABCH JAABHD JAACAF JAJAJJ JAABEJ JAACJJ JAACDI 
1500

Output 
INNOCENT

Explanation 
The readings are, 

000200, 000127, 000173, 000205, 0000099, 000149, 000299, 000238

The sum of these readings is 1490 < 1500, the central meter reading. Hence the owner is INNOCENT.
 */
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