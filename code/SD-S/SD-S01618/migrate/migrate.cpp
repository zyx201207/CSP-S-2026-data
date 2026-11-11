#include<bits/stdc++.h>
using namespace std;
long long ans[2000005];
int n,m,cnt;
int q,D,c,a[2000005];
bool vis[2000005];
long long d[2000005];
int l[50000005];
struct dian
{
	long long dis,id;
};
struct edge
{
	long long nxt,to,v;
}e[50000005];
bool operator<(dian a,dian b)
{
	return a.dis>b.dis;
}
void add(int u,int v,int w)
{
	e[++cnt].nxt=l[u];
	l[u]=cnt;
	e[cnt].to=v;
	e[cnt].v=w;
}
long long dijkstra(int s,int t)
{
	memset(d,0x3f,sizeof(d));
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	priority_queue<dian> q;
	q.push((dian){0,s});
	d[s]=0;
	ans[s]=1;
	while(!q.empty())
	{
		dian tq=q.top();
		q.pop();
		if(vis[tq.id]) continue;
		vis[tq.id]=1;
		for(int i=l[tq.id];i;i=e[i].nxt)
		{
			int now=e[i].to;
			if(vis[now]) continue;
			if(d[now]==d[tq.id]+e[i].v)
			{
				ans[now]+=ans[tq.id];
				continue;
			}
			if(d[now]>d[tq.id]+e[i].v);
			{
				if(d[now]<d[tq.id]+e[i].v) continue;
				d[now]=d[tq.id]+e[i].v;
				ans[now]=ans[tq.id];
				q.push((dian){d[now],now});
			}
		}
	}
	return ans[t];
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		memset(l,0,sizeof(l));
		cnt=0;
		cin>>n>>D;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(abs(a[j]-a[i])<=D)
				{
					add(i,j,1);
					add(j,i,1);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dijkstra(i,j)==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
