#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+15;
const int inf=2e18;
int c,T;
int n,d;
int a[N];
struct edge{
	int to,next,val;
}e[2*N];
int head[N];
int tot;
int dis[N];
int f[N];
bool vis[N];
int ans;
void add(int u,int v,int val)
{
	tot++;
	e[tot].to=v;
	e[tot].next=head[u];
	e[tot].val=val;
	head[u]=tot;
}
struct pq{
	int id,x;
	bool operator<(const pq A)const{
		return A.x<x;
	}
};
void di(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=inf;
		vis[i]=0;
		f[i]=0;
	}
	priority_queue<pq> q;
	q.push({s,0});
	dis[s]=0;
	f[s]=1;
	while(!q.empty())
	{
		int u=q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v]>dis[u]+e[i].val)
			{
				dis[v]=dis[u]+e[i].val;
				f[v]=f[u];
				if(!vis[v])
				{
					q.push({v,dis[v]});
				}
			}
			else if(dis[v]==dis[u]+e[i].val)
			{
				f[v]+=f[u];
				if(!vis[v])
				{
					q.push({v,dis[v]});
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==s) continue;
		else if(f[i]==2) ans++;
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//16:29 24pts solution 
	//zhe ti da suan bu guan le
	//T2 gan jue you dian si lu 
	//xian ba bao li fen da le 
	cin>>c>>T;
	while(T--)
	{
		ans=0,tot=0;
		cin>>n>>d;
		if(n<=300)
		{
			for(int i=1;i<=n;i++) cin>>a[i],f[i]=0,dis[i]=inf,vis[i]=0,head[i]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=d)
					{
						add(i,j,1);
					}
					else break;
				}
			}
			for(int i=1;i<=n;i++) di(i);
			cout<<ans<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}
}
