#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int c,t,n,k;
vector<vector<int>>e;
vector<int>h;
void dfs(int u,int fa){
	int mx=-1;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		mx=max(mx,h[v]);
	}
	h[u]=mx+1;
}
void solve(){
	cin >> n >> k;
	e.assign(n+1,vector<int>());
	rep(i,1,n){
		int u,v;cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int rt=1,mn=inf;
	rep(i,1,n){
		h.assign(n+1,0);
		dfs(i,0);
		if(h[i]<mn)
			mn=h[i],rt=i;
	}
	h.assign(n+1,0);
	dfs(rt,0);
	//[h,id]
	vector<bool>vis(n+1,0);
	priority_queue<pair<int,int>>q;
	vis[rt]=1;
	q.push({h[rt],rt});
	rep(k,2,n){
		auto i=q.top();
		int hi=i.first,u=i.second;
		q.pop();
		for(auto v:e[u]){
			if(vis[v])continue;
			q.push({h[v],v});
		}
	}
	int ans=0;
	if(!q.empty())
		ans=q.top().first;
	cout << ans << '\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> c >> t;
	while(t--)
		solve();
	
	return 0;
}