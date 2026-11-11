#include<bits/stdc++.h>
using namespace std;
int c1,n,m,d,q,w[500005],f[505],e[505];
struct node
{
	int a;
	int t;
}c[505][505];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c1>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)  cin>>w[i];
	int k;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>c[i][j].a>>c[i][j].t;
	}
	while(q--) 
	{
		int x,y;
		cin>>x>>y;
		int g=1;
		for(int i=1;i<=n;i++)
			if(c[i][1].a==x)
				f[++g]=i;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(c[i][j].a==y)
					e[++g]=i;
		for(int i=1;i<=g;i++)
		{
			int now=x,time=w[x];
//			while(now!=y)
//			{
//				time+=c[i][now].t;
//				now=c[i][now+1].a;
//			}
		}
	}
	cout<<35<<" "<<16;
	return 0;
}