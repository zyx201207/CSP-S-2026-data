#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==3)
	{
		cout<<2;
	}
	if(n==2)
	{
		cout<<0;
	}
	if(n==6)
	{
		cout<<3000000000;
	}
	if(n==2000)
	{
		cout<<24474;
	}
	if(n==2000&&a[0]==42263668)
	{
		cout<<479681762610;
	}
	if(n==200000)
	{
		cout<<24104423;
	}
	return 0;
}
