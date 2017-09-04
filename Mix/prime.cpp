#include<iostream>
#include<cmath>
int check(int low,int high )
{int k=0,count=0,flag;

	while (low < high)
    {
        flag = 0;

        for(int i = 2; i <= low/2; ++i)
        {
            if(low % i == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            k++;

        ++low;
    }
    return k;
}
int main()
{
	int tc;
	std::cin>>tc;
	while(tc--)
	{
		int a,b;
		std::cin>>a>>b;
		//int c=a/log(a-1);
		int c=(a/log (a))*(1 + 0.992/log (a));
		std::cout<<c<<" ";
		int d=b/log(b-1);
		std::cout<<d<<" ";
		std::cout<<d-c;
	

	}
	return 0;
}

