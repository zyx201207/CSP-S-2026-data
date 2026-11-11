#include<bits/stdc++.h>
#define int long long
using namespace std;
string CSP="CSP RP++";

const int N=5e5+5;

int c,n,m,d,Q;
int dis[N],W[N],a[N];
bool vis[N];

struct edge{
	int v,w;
};

struct node{
	int u,d;
	bool operator < (const node& x)const
	{
		return d>x.d;
	}
};

vector<edge> e[N];

void dj(int s)
{
	for(int i=1;i<=n;i++) dis[i]=N;
	dis[s]=0;
	
	priority_queue<node> q;
	q.push({s,0});
	
	while(!q.empty())
	{
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i].v,w=e[u][i].w;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>W[i];
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		for(int j=1,v,w;j<=k;j++)
		{
			cin>>v>>w;
			e[i].push_back({v,w*2});
		}
	}
	
	while(Q--)
	{
		memset(dis,0,sizeof(dis));
		memset(vis,0,sizeof(vis));
		int x,y;
		cin>>x>>y;
		dj(x);
		cout<<dis[y]+W[x]+W[y]<<"\n";
	} 
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
