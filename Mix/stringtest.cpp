#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  int n;
  cin>>n;
  string acc[n];
  int i = 0;
for (string word; cin >> word; i++)
    acc[i] = word;
//  for(int i=0;i<n;i++)
//  {
//    std::getline (std::cin,acc[i]);
//  }
  for(int i=n/2;i<n;i++)
  {
  cout<<acc[i]<<endl;}
  for(int i=0;i<n/2;i++)
  {
    cout<<acc[i]<<endl;
  }
  return 0;
}

