//Ñîð©Ñ­ SN-S00488 
#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace sol {
	struct Edge {
		int v,nxt;
	} e[105];

	int head[105],idx = 0;

	void add(int u,int v) {
		e[++idx] = {v,head[u]};
		head[u] = idx;
	}

	int a[105],ina[105];
	int n,k;
	
	int vis[105],dis[105];
	
	void dfs2(int u,int dep,int fa){
		vis[u] = 1;
		dis[u] = min(dis[u],dep);
		for(int i = head[u];i;i = e[i].nxt){
			int v = e[i].v;
			if(v == fa){
				continue;
			}
			if(ina[v] && dep == 0){
				dfs2(v,0,u);
			}
			if(!ina[v]){
				dfs2(v,dep+1,u);
			}
		}
	}
	
	int aans = 0x3f3f3f3f3f3f3f3f;
	
	void check(){
		int num = 0;
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= k;++i){
			if(!vis[a[i]]){
				++num;
				if(num > 2){
					return;
				}
				dfs2(a[i],0,-1);
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;++i){
			ans = max(dis[i],ans);
		}
		
		aans = min(aans,ans);
	}

	void dfs1(int dep,int lst) {
		if(dep == k+1) {
			check();
			return;
		}
		for(int i = lst+1; i<=n; ++i) {
			a[dep] = i;
			ina[i] = 1;
			dfs1(dep+1,i);
			ina[i] = 0;
		}
	}

	void main() {
		idx = 0;
		aans = 0x3f3f3f3f3f3f3f3f;
		memset(head,0,sizeof(head));
		cin >> n >> k;

		for(int i = 1; i <= n-1; ++i) {
			int u,v;
			cin >> u >> v;
			add(u,v);
			add(v,u);
		}
		
		dfs1(1,0);
		
		cout << aans << endl;
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--) {
		sol::main();
	}
}
/*
17:24 feat: initial commit
17:38 feat: bf





*/
