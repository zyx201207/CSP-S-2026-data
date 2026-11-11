#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+5;
vector<int>vc[N];
int n,k;int dep[N],ans,vis[N];
pii edge[N],p,mx;
void dfs1(int u,int fa){
	mx=max(mx,make_pair(dep[u],u));
	for(int v:vc[u]){
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs1(v,u);
	}
}
pii dfs2(int u,int fa){
	pii ans={dep[u],0};
	for(int v:vc[u]){
		if(v==fa||make_pair(u,v)==p||make_pair(v,u)==p)continue;
		dep[v]=dep[u]+1;
		pii t=dfs2(v,u);
		ans=max(ans,t);
	}
	if(dep[u]==ans.fi/2)ans.se=u;
	return ans;
}
void dfs3(int u,int fa){
	dep[u]=0;
	for(int v:vc[u]){
		if(v==fa||make_pair(u,v)==p||make_pair(v,u)==p)continue;
		dfs3(v,u);dep[u]=max(dep[u],dep[v]+1);
	}
}
void sol(){
	cin>>n>>k;ans=2e9;
	for(int i=1;i<=n;i++)vc[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		vc[u].push_back(v);
		vc[v].push_back(u);
		edge[i]={u,v};
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n;j++)vis[j]=0;
		p=edge[i];mx={0,0};
		int u=p.fi,v=p.se;
		dep[u]=dep[v]=0;
		dfs1(u,v);dep[mx.se]=0;
		pii s=dfs2(mx.se,0);
		dfs3(s.se,0),mx={0,0};
		dfs1(v,u);dep[mx.se]=0;
		pii t=dfs2(mx.se,0);
		dfs3(t.se,0);
		priority_queue<pii >pq;
		while(pq.size())pq.pop();
		{
		pii u={dep[t.se],t.se};
			vis[u.se]=1;
			for(int v:vc[u.se]){
				if(vis[v]||make_pair(u.se,v)==p||make_pair(v,u.se)==p)continue;
				pq.push({dep[v],v});
			}
		u={dep[s.se],s.se};
			vis[u.se]=1;
			for(int v:vc[u.se]){
				if(vis[v]||make_pair(u.se,v)==p||make_pair(v,u.se)==p)continue;
				pq.push({dep[v],v});
			}
		}
		for(int j=3;j<=k;j++){
			pii u=pq.top();pq.pop();
			vis[u.se]=1;
			for(int v:vc[u.se]){
				if(vis[v]||make_pair(u.se,v)==p||make_pair(v,u.se)==p)continue;
				pq.push({dep[v],v});
			}
		}
		if(pq.size())ans=min(ans,pq.top().fi);
	}
	cout<<ans+1<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;cin>>c>>T;
	while(T--)sol();
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
