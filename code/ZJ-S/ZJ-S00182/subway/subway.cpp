#include<bits/stdc++.h>
using namespace std;
const int M=5e5+7;
long long reach[M];
int c,d;
int m,n,q,w[M];//n线路数 m站点数 w进出口time
bool vis[M];
struct wzy
{
	int u,v,t;
	bool operator<(const wzy k) const{
		return t>k.t;
	}
};
vector<pair<int,int>> e[501],r[M];
priority_queue<int> que;
long long dij(int from,int final)
{
	long long ans=0;
	ans+=w[from]+w[final];
	priority_queue<wzy> que;
	vis[from]=true;
	for(int i=0;i<r[from].size();i++)
	{
		wzy gf;
		gf.u=from,gf.v=r[from][i].first,gf.t=r[from][i].second;
		que.push(gf);
	}
	for(int op=1;op<=m&&!que.empty();op++)
	{
		wzy to=que.top();
		que.pop();
		if(vis[to.v]) continue;
		reach[to.v]=reach[to.u]+to.t;
		if(to.v==final) return reach[to.v]+ans;
		vis[reach[to.v]]=true;
		for(int i=0;i<r[to.v].size();i++)
		{
			wzy gf;
			gf.u=to.v,gf.v=r[to.v][i].first,gf.t=r[to.v][i].second;
			if(!vis[gf.v]) que.push(gf);
		}
	}
}
int main()
{
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
 	cin.tie();
 	cin>>c>>n>>m>>d>>q;
 	for(int i=1;i<=m;i++) cin>>w[i];
 	for(int i=1;i<=n;i++)
 	{
 		int cc;
 		cin>>cc;
 		for(int j=1;j<=cc;j++)
 		{
 			int y,t;
 			cin>>y>>t;
 			for(int z=0;z<e[y].size();z++)
 			{
 				int u=e[y][z].first;
 				r[u].push_back({y,e[y][z].second+t});
 				r[y].push_back({u,e[y][z].second+t});
			}
 			e[y].push_back({i,t});
		}
	}
	while(q--)
	{
		memset(vis,0,sizeof(vis));
		int from,final;
		cin>>from>>final;
		cout<<dij(from,final)<<"\n";
	}
 	return 0;
}
