#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[56000],g=0,h=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(h<g)
		{
			h=g;
			g=0;
		}
		for(int y=1;y<=m;y++)
		{
			for(int r=i+1;r<=n;r++)
			{
				if(a[i]+y==a[r])
				{
					g++;
				}
			}
		}
	}
	cout<<h<<endl;
	return 0;
}
