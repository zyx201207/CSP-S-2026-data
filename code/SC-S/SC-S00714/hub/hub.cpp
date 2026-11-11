#include<bits/stdc++.h>
#define N 500005
using namespace std;
vector<int> e[N];
int dep[N];
int ans=0;
void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[ans]) ans=u;
	for(auto v:e[u])
	{
		if(v==fa) continue;
		dfs1(v,u);
	}
}
bool vis[N];
bool vis2[N];
void dfs2(int u,int fa) {
	vis2[u]=1;
	for(auto v:e[u]) {
		if(v==fa || !vis[v]) continue;
		dfs2(v,u);
	}
}
int dist[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(n<=10) {
			int res=1000;
			for(int i=0;i<(1<<n);i++)
			{
				int kn=__builtin_popcount(i);
				if(kn!=k) continue;
				for(int j=1;j<=n;j++) vis[j]=(i&(1<<(j-1))),vis2[j]=0;
				int tot=0;
				for(int j=1;j<=n;j++) {
					if(vis[j] && !vis2[j]) {
						tot++;
						dfs2(j,0);
					}
				}
				if(tot>2) continue;
				queue<int> q;
				for(int j=1;j<=n;j++) dist[j]=(vis[j])?(0):(-1);
				for(int j=1;j<=n;j++) if(vis[j]) q.push(j);
				int ansx=0;
				while(!q.empty()) {
					int u=q.front();
					q.pop();
					ansx=max(ansx,dist[u]);
					for(auto v:e[u]) {
						if(dist[v]==-1) {
							dist[v]=dist[u]+1;
							q.push(v);
						}
					}
				}
				res=min(res,ansx);
			}
			cout<<res<<'\n';
		}
		else cout<<"0\n";
	}
	return 0;
}