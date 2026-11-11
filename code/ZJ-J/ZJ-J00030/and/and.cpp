#include<bits/stdc++.h>
using namespace std;
int a,b,c[200005][40]={},d[200005]={},e[40]={};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int h=1;h<=a;h++)
	{
		int u,v=0;
		cin>>u;
		while(u>0)
		{
			v++;
			c[h][v]=u%2;
			u/=2;
		}
	}
	for(int h=30;h>=1;h--)
	{
		int u=0;
		for(int i=1;i<=a;i++)
		    if(c[i][h]==1)
		       u++;
		if(u>=b)
		{
			for(int i=1;i<=a;i++)
			    if(c[i][h]==1)
				    d[i]=1;
				    
			e[h]=1;
			for(int i=h-1;i>=1;i--)
			{
				int v=0;
				for(int j=1;j<=a;j++)
				    if(d[j]==1)
				    {
				    	if(c[j][i]==1)v++;
				    	else d[j]=0;
					}
				if(v>=b)e[i]=1;
				else break;
			}
			int x=1,y=0;
			for(int i=1;i<=30;i++)
			{
				y+=e[i]*x;
				x*=2;
			}
			cout<<y;
			return 0;
		}
	}
	cout<<0;
	return 0;
}