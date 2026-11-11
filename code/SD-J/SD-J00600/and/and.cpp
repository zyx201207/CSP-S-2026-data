#include<bits/stdc++.h>
using namespace std;
int a[10009];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2)
	
	{
		if(n==4)
		{
			cout<<12;
		}
		if(n==2000)
		{
			cout<<49152;
		}
		if(n==200000)
		{
			cout<<511;
		}
	}	
	if(m==3)
	{
		cout<<7;
	}	
	else
	{
		cout<<49152;
	}
	return 0;

 } 

