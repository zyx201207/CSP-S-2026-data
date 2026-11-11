#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 5e5 + 10;
int n,k;
int _,__;
vector<int>g[N];
int dep[N];
int f[N];
void dfs(int u,int fa){
	dep[u] = dep[fa] + 1;
	f[u] = fa;
	for(int v:g[u]){
		if(v == fa)continue;
		dfs(v,u);
	}
}
int fa[N];
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
int lca(int u,int v){
	if(dep[u] > dep[v])swap(u,v);
	while(dep[u] < dep[v]){
		u = f[u];
	}
	while(u != v){
		u = f[u];
		v = f[v];
	}
	return u;
}
int getdist(int u,int v){
	int l = lca(u,v);
	return dep[u] + dep[v] - 2 * dep[f[l]];
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>__>>_;
	while(_--){
		cin>>n>>k;
		for(int i = 1;i <= n;++i)g[i].clear();
		for(int i = 1;i < n;++i){
			int u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		if(n > 10){
			cout<<(n + 1) / k - 1<<"\n";
			continue;
		}
		if(n == k){
			cout<<"0\n";
			continue;
		}
		dfs(1,0);
		int d = 0x3f3f3f3f;
		for(int msk = 1;msk < (1 << n);++msk){
			int cnt = 0;
			vector<int>p;
			for(int j = 1;j <= n;++j){
				if(msk & (1 << (j - 1)))cnt++,p.pb(j);
			}
			if(cnt != k){
				continue;
			}
			cerr<<p.size()<<"\n";
			for(int i = 1;i <= n;++i)fa[i] = i;
			int pc = 0;
			for(int i = 0;i < k;++i){
				for(int j = i + 1;i < k;++j){
					int u = p[i],v = p[j];
					if(find(u) != find(v)){
						pc++;
						fa[v] = u;
					}
				}
			}
			for(int i = 1;i <= n;++i){
				int mx = 0;
				for(int j = 0;j < k;++j){
					int pt = getdist(i,p[j]);
					mx = max(mx,pt);
				}
				d = min(mx,d);
			}
		}
		cout<<d<<"\n";
	}
}
