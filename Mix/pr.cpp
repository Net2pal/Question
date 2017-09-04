#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a=5/log(5);
	int b=30/log(30);
	int c=(b-a)/log(a);
	std::cout<<a<<b;
	std::cout<<c;
	return 0;
}
