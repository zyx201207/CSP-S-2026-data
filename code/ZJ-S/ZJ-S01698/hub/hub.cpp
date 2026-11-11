#include<bits/stdc++.h>
using namespace std;

namespace wsrCSPS {
	const int N=1e6+9;
	int n,k,fa[N],dep[N],son[N],top[N],siz[N];
	bool vis[N];
	vector<int>G[N];
	
	void dfs1(int u,int f) {
		dep[u] = dep[f]+1;
		fa[u] = f;
		siz[u] = 1;
		for(auto &v:G[u]) if(v!=f) {
			dfs1(v,u);
			siz[u] += siz[v];
			if(siz[v]>siz[son[u]]) son[u] = v;
		}
	} 
	
	void dfs2(int u,int tp) {
		top[u] = tp;
		if(son[u]) dfs2(son[u],tp);
		for(auto &v:G[u]) if(v!=fa[u]&&v!=son[u])
			dfs2(v,v);
	}
	
	int lca(int u,int v) {
		while(top[u]!=top[v]) {
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u = fa[top[u]];
		}
		return dep[u]<dep[v] ? u : v;		
	}
	
	int dist(int u,int v) {
		int l=lca(u,v);
		return dep[u]-dep[l]+dep[v]-dep[l];
	}
	
	void dfs(int u,int mask) {
		vis[u] = 1;
		for(auto &v:G[u]) if(((mask>>(v-1))&1)&&vis[v]==0)
			dfs(v,mask);
	}
	
	int main() {
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int c,T;cin>>c>>T;
		while(T--) {
			cin>>n>>k;
			memset(son,0,sizeof(son));
			for(int i=1;i<=n;i++) G[i].clear();
			for(int i=1;i<n;i++) {
				int u,v;cin>>u>>v;
				G[u].push_back(v);
				G[v].push_back(u);
			}	
			dfs1(1,0);
			dfs2(1,1);
			int ans=INT_MAX;
			// O(C(n,k))
			for(int mask=0;mask<(1<<n);mask++) {
				memset(vis,0,sizeof(vis));
				if(__builtin_popcount(mask)!=k) continue;
				// O(n)
				int cnt=0;
				for(int i=1;i<=n;i++)
					if((mask>>(i-1))&1) if(!vis[i]) {
						cnt++;
						dfs(i,mask);
					}
				if(cnt>2) continue;
				vector<int>v;
				for(int i=1;i<=n;i++)
					if((mask>>(i-1))&1)
						v.push_back(i);
				// O(n*k*logn)
				int R=0;
				for(int i=1;i<=n;i++) {
					int d=INT_MAX;
					for(auto &j:v)
						d = min(d,dist(i,j));
					R = max(R,d);
				}	
				ans = min(ans,R);
			}
			cout<<ans<<"\n";
		} 
		return 0;
	}
}

int main() { return wsrCSPS::main(); }
/*
O(C(n,k)*n*k*logn)
预计得分： 15 pts
CSP-S 2026 估分：100pts+68pts+24pts+15pts=207pts 
Trick||Treat!
Oct31==Dec25?
*/
