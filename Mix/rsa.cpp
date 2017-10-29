#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int h)
{
    int temp;
    while(1)
    {
        temp = a%h;
        if(temp==0)
        return h;
        a = h;
        h = temp;
    }
}
int main()
{
	double p,q;
	cout<<"\n Enter two prime no";
	cin>>p>>q;
	double n=p*q;
	double count=0;
	double totient=(p-1)*(q-1);
	double e=2;
 
    
    while(e<totient){
    count = gcd(e,totient);
    if(count==1)
        break;
    else
        e++;
    }
    double d,k=2;
    d = (1 + (k*totient))/e;
    double msg;
    cout<<"\n enter the msg";
    cin>>msg;
    double c = pow(msg,e);
    double m = pow(c,d);
    c=fmod(c,n);
    m=fmod(m,n);
    cout<<"\n"<<"n = pq = "<<n;
    cout<<"\n"<<"totient = "<<totient;
    cout<<"\n"<<"e = "<<e;
    cout<<"\n"<<"d = "<<d;
    cout<<"\n"<<"Encrypted data = "<<c;
    cout<<"\n"<<"Original Message sent = "<<m;
	return 0;
}
