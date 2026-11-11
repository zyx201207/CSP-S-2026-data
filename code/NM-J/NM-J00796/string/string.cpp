#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long a;
	char x;
	char y;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		cin>>x;
		for(int j=0;j<a;j++)
		{
			y+=x;
		}
	}
	cout<<y;
	return 0;
}
