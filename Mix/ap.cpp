/* C++ program for efficient approach to find
largest number having digits in non-decreasing
order. */
#include<bits/stdc++.h>
using namespace std;

// Prints the largest number smaller than s and
// digits in non-decreasing order.
void nondecdigits(string s)
{
	long long m = s.size();

	/* array to store digits of number */
	long long a[m];

	/* conversion of characters of string int number */
	for (long long i=0; i<m; i++)
		a[i] = s[i] - '0';

	/* variable holds the value of index after which
	all digits are set 9 */
	long long level = m-1;
	for (long long i=m-1; i>0; i--)
	{
		/* Checking the condition if the digit is
		less than its left digit */
		if (a[i] < a[i-1])
		{
			a[i-1]--;
			level=i-1;
		}
	}

	/* If first digit is 0 no need to print it */
	if (a[0] != 0)
	{
		for (long long i=0; i<=level; i++)
			cout << a[i];
		for (long long i=level+1; i<m; i++)
			cout << "9";
	}
	else
	{
		for (long long i=1; i<level; i++)
			cout << a[i];
		for (long long i=level+1; i<m; i++)
			cout << "9";
	}
}

// Driver function
int main()
{
	string n ;
	getline(cin, n);
	nondecdigits(n);
	return 0;
}

