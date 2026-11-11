#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	long long f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=(k<<1)+(k<<3)+(c^48);
		c=getchar();
	}
	return f*k;
}
long long n,m,dis[505][505],w[500005],d,c,q,k[505],sum;
struct node
{
	long long v,w;
};
vector<node>e[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++) w[i]=rd();
	for(int i=1;i<=n;i++)
	{
		k[i]=rd();
		for(int j=1;j<=k[i];j++)
		{
			long long A=rd(),W=rd();
			e[A].push_back({i,W});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=1e15;
			if(i==j) dis[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto tp1:e[i])
		{
			for(auto tp2:e[i])
			{
				if(tp1.v!=tp2.v)
				{
					int v=tp1.v,u=tp2.v;
					dis[v][u]=min(dis[v][u],tp1.w+tp2.w);
					
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--)
	{
		sum=1e15;
		int x=rd(),y=rd();
		for(auto tp1:e[x])
		{
			for(auto tp2:e[y])
			{
				int v=tp1.v,u=tp2.v;
				sum=min(sum,dis[u][v]+tp1.w+tp2.w);
			}
		}
		cout<<sum+w[x]+w[y]<<"\n";
	}
}