#include<bits/stdc++.h>
using namespace std;
long long a[300005],n,m,a1[300005],c[300005];
bool f(int x)
{
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(a[mid]<x) l=mid+1;
		if(a[mid]>=x) r=mid;
	}
	return true;
}
void f1(int x)
{
	for(int i=x;i<=n;i++)
	{
		a[i]=0;
	}
	return ;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(f(a[j]))
			{
				f(j);
			}
			else
			{
				continue;
			}
		}
		for(int k=1;k<=n;k++)
		{
			a1[i]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==j)
			{
				c[j]+=1;
			}
		}
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
