#include<bits/stdc++.h>
using namespace std;
int c[300000+5];
void aaa(int a[],int j,int n,int d[])
{
	bool bb=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==j)
		{
			bb=!bb;
		}
		
		if(bb=1)
		{
			d[i]=1;
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[500000+5];
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=m;i++)
	{
		int s=0;
		int d[500000+5]={};
		int a[300000+5]={};
		for(int j=i;j<=n;j++)
		{
			a[b[j]]++;
		}
		for(int j=i;j<=m;j++)
		{
			if(a[j]>=2)
			{
				aaa(b,j,n,d);
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(a[b[i]]%2==1&&!d[b[i]])
			{
				c[b[i]]++;
				d[b[i]]=1;
			}
			else if(a[b[i]]%2==0&&d[b[i]])
			{
				c[b[i]]++;
				d[b[i]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
