#include<bits/stdc++.h>
using namespace std;
int w[500005],k[500005],a[500005][2],t[500005][2];//                        fuck
int main()
{
	int c,n,m,d,q,s=0,x,y,o,p;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=i;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		s+=w[x]+w[y];
		for(int j=1;j<=n;j++)
		{
			for(int h=0;h<=1;h++)
			{
				if(a[i][h]==x)
				{
					o=i;
					p=h;
				}
			}
		}
		while(a[o][p]!=y)
		{
			if(p==0) p=1;
			else p=0;
			for(int j=1;j<=n;j++)
		    {
			    for(int h=0;h<=1;h++)
			    {
				    if(a[i][h]==a[o][p]&&o!=i&&p!=h)
				    {
					    o=i;
					    p=h;
				    }
			    }
		    }
		    s+=t[o][p];
		}
	}
	cout<<s;
	return 0;
}
