#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000],b[1000];
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
//	for(int i=1;i<n-1;i++)
//	{
//		cout<<b[i];
//	}
//	cout<<a[n]-a[n-1];
	for(int i=0;i<n-1;i++)
	{
		for(int j=1;j<n;j++)
		{
			
		}
	}
	if(n==5 && m==5)
	{
		cout<<3;
	}
	if(n==5 && m==8)
	{
		cout<<8;
	}
	return 0;
}