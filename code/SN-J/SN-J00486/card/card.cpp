#include <bits/stdc++.h>
using namespace std;
int main
{
	freopen("card","in");
	int m,n,k,a[1005];
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=n;i++) 
	{
		if(a[i]=k)
		{
		a[i]-a[i-1];
		}
	}
	for(int i=0;i<=m;i++)
	{
	
	cout<<a[i];
	}
	
	
}
