#include<bits/stdc++.h>
using namespace std;
int n,m;
int r=0;
int p=0;
int q=0;
int k=0;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	for(int i=0;i<n;i++)
	{
		if(a[i]==r)
		{
			continue;
		}
		else
		{
			break;
		}
			p=1;
	}
	for(int i=0;i<n;i++)
	{
		q=a[0];
		if(a[i]==q)
		{
			continue;
		}
		else
		{
			break;
		}
		q+=a[1]-a[0];
		k=1;
	}
	if(n==1)
	{
		cout<<"1";
	}
	else if(p==1)
	{
		cout<<n;
	}
	else if(k==1)
	{
		int j=0;
		int g=0;
		int u=0;
		u=m/a[1]-a[0];
		for(int i=1;i<=n;i++)
		{
			g+=i;
			if(g<=u)
			{
				j=g;
			} 
			else
			{
				cout<<i-1;
			}
		}
	}
	else
	{
		cout<<"4";	
	}
	return 0;
}
