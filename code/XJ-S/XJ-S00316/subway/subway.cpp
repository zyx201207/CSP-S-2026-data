#include<bits/stdc++.h>
using namespace std;
const int N=1e7+12;
const int inf=INT_MAX;
long long to[N],net[N],ci[N],p,head[N];
long long c,n,m,d,r,w,x[N],y,e[N],k,z,dis[N],used[N];
struct node
{
	int v,d;
	bool operator <(const node&other)const
	{
		return d>other.d;
	}
};
priority_queue<node> q;
void addedge(int a,int b,int c)
{
	to[++p]=b;
	net[p]=head[a];
	head[a]=p;
	ci[p]=c;
}
void dij(int s)
{
	dis[s]=0;
	q.push((node){s,0});
	while(!q.empty())
	{
		node now=q.top();
		q.pop();
		if(used[now.v]==1)
		{
			continue;
		}
		used[now.v]=1;
		for(int i=head[now.v];i;i=net[i])
		{
			if(dis[to[i]]>dis[now.v]+ci[i])
			{	
				dis[to[i]]=dis[now.v]+ci[i];
				q.push((node){to[i],dis[to[i]]});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++)
	{
		cin>>w;
		addedge(i,i+m,w);
		addedge(i+m,i,w);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		memset(x,0,sizeof(x));
		memset(e,0,sizeof(e));
		for(int j=1;j<=k;j++)
		{
			cin>>x[j]>>e[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int h=j+1;h<=k;h++)
			{
				if(j==h)
				{
					continue;
				}
				addedge(x[j],x[h],e[j]+e[h]);
				addedge(x[h],x[j],e[j]+e[h]);
			}
		}	
	}
	while(r--)
	{
		memset(used,0,sizeof(used));
		for(int i=1;i<=n+2*m;i++)
		{
			dis[i]=inf;
		}
		cin>>y>>z;
		dij(y+m);
		cout<<dis[z+m]<<endl;
	}
	return 0;
}
