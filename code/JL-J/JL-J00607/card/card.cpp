#include<bits/stdc++.h>
using namespace std;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
long long n,m;
int a[10001],b[10001]={ };
cin>>n>>m;
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
int x1=0,x2=0;
bool first=0;
for(int i=0;i<n;i++)
{
	x1=0;x2=0;
	for(int j=i;j<n;j++)
	{
	if(a[i]==i&&first)
	{
		x1=i;
		x2=i;
	}
	if(a[i]==i&&!first)
	{
		x2=i;
	}
	}
	for(int j=i;j<n;j++)
	{
		if(j<x1&&j>=x2)
		{
			b[a[j]]++;
		
		}
	}
}
for(int i=0;i<m;i++)
{
	cout<<b[i];
}
return 0;
}
