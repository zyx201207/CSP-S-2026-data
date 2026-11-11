#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[200005],maxx=-99;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	else if(m==2)
	{
		maxx=-99;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
	}
	else if(m==3)
	{
		maxx=-99;
		for(int b=1;b<=n;b++)
		{
			for(int c=b+1;c<=n;c++)
			{
				for(int d=c+1;d<=n;d++)
				{
					maxx=max(maxx,(a[b]&a[c])&a[d]);
				}
			}
		}
		cout<<maxx;
	}
	return 0;
}
