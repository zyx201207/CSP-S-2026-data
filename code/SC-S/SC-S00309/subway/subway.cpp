#include<bits/stdc++.h>
using namespace std;
int tot,hh[400050],vis[400005],dis[400005];
int c,n,m,d,q,k1,x,y,w;
int a[100005],t[100005];
queue<int> s;
struct node
{
	int to,w,net;
}e[400005];
void add(int x,int y,int z)
{
	tot++;
	e[tot]={y,z,hh[x]};
	hh[x]=tot;
}
void spfa(int x)
{
	vis[x]=1;
	s.push(x);
	dis[x]=0;
	while(!s.empty())
	{
		int u=s.front();
		s.pop();
		vis[u]=0;
		for(int i=hh[u];i;i=e[i].net)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(!vis[v])
				{
					vis[v]=1;
					s.push(v);
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
    	cin>>w;
    	add(i,i+n,w);
    	add(i+n,i,w);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k1;
		for(int j=1;j<=k1;j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<k1;j++)
		{
			add(a[j],a[j+1],0);
			add(a[j-1],a[j],0);
			add(a[j],a[j]+n,t[j]);
			add(a[j]+n,a[j],t[j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		memset(dis,0x3f,sizeof dis);
		memset(vis,0,sizeof vis);
		cin>>x>>y;
		spfa(x);
		cout <<dis[y+n]<<'/n';
	}
	return 0;
}