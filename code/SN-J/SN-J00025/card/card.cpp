#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long  n,m;
	cin>>n>>m;
	long long c[n],a[n],b[n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	b[i]=0;
}
	for(int i=0;i<n;i++)
	{
		for(int y=1;y<n;y++) 
		c[y]=a[y];
	for(int g=i;g<n;g++)
	{
		for(int e=g-1;e>i;e--)
		{
			if(a[e]==a[g]&&c[e]!=0)
			{
				cout<<e<<g;
				for(int r=e;r<g;r++)
				c[r]=0;
			}
		}
	}
	for(int t=0;t<n;t++)
		{
			if(c[i]!=0)
			{
			b[c[i]]++;
		}
		}
	}
for(int i=0;i<m;i++)
	cout<<b[i]<<" ";
	return 0;
}
