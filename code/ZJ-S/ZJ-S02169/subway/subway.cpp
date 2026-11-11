#include<bits/stdc++.h>
#define int long long
#define bocchi ios::sync_with_stdio(0);
#define rock cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
const int N=505;
const int K=5e4+15;
const int M=1e6+15;
const int inf=1e18;
struct node{
	int id,line,t;
};
int c,n,m,d,q;
int w[M];
vector<node> be[M];//ji lu mei ge dian fen bie shu yu de xian lu
struct edge{
	int to,next,val;
}e[M];
struct pq{
	int id,x;
	bool operator<(const pq A)const{
		return A.x<x;
	}
};
int dis[N][K];
bool vis[N][K];
int head[M],tot;
void add(int u,int v,int val)
{
	tot++;
	e[tot].to=v;
	e[tot].next=head[u];
	e[tot].val=val;
	head[u]=tot;
}
void di(int s)
{
	priority_queue<pq> q;
	dis[s][s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		int u=q.top().id;
		q.pop();
		if(vis[s][u]) continue;
		vis[s][u]=1;
		for(int i=head[u];i;i=e[i].next)
		{
			int v=e[i].to;
			if(dis[s][v]>dis[s][u]+e[i].val)
			{
				dis[s][v]=dis[s][u]+e[i].val;
				if(!vis[s][v])
				{
					q.push({v,dis[s][v]});
				}
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	// wo yao gen T2 bao le!!!
	// now 17:00
	bocchi rock
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<K;j++)
		{
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	int cnt=n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			add(++cnt,i,0);
			add(i,cnt,0);
			be[x].push_back({cnt,i,y});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<be[i].size();j++)
		{
			for(int k=j+1;k<be[i].size();k++)
			{
				int d1=be[i][j].id;
				int d2=be[i][k].id;
				add(d1,d2,be[i][j].t+be[i][k].t);
				add(d2,d1,be[i][j].t+be[i][k].t);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		di(i);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(int i=0;i<be[x].size();i++)
		{
			for(int j=0;j<be[y].size();j++)
			{
				int linex=be[x][i].line;
				int liney=be[y][j].line;
				int idx=be[x][i].id;
				int idy=be[y][j].id;
				int needx=be[x][i].t;
				int needy=be[y][j].t;
				ans=min(ans,w[x]+needx+dis[linex][idx]+dis[liney][linex]+dis[liney][idy]+w[y]+needy);
			}
		}
		cout<<ans<<endl;
	}
	//wo bu xiang jiu ci fang qi
	//17:59 [44,60] pts
	//now 100+[44,60]+24+0=[168,184]pts.
}
