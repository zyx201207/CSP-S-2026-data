#include<bits/stdc++.h>
#define eb emplace_back
//#define cerr int
#define pc __builtin_popcount
using namespace std;

const int N=3e2+10, INF=1e9;
vector<int> g[N];
int fa[N], d[N];
int ID, t;
int n, k, ans;

void fastio(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int x, int y){
	int fx=find(x), fy=find(y);
	if(fx!=fy) fa[fx]=fy;
}
void dfs(int u, int fa){
	for(int v:g[u]){
		if(v==fa) continue;
		d[v]=d[u]+1;
		dfs(v, u);
	}
}
void solve(){
	cin>>n>>k;
	for(int i=0; i<=n; i++) g[i].clear();
	for(int i=1; i<n; i++){
		int u, v; cin>>u>>v;
		g[u].eb(v); g[v].eb(u);
	}
	ans=INF;
	for(int s=0; s<(1<<n); s++){
//		s=9;
		if(pc(s)!=k) continue;
		for(int i=0; i<=n; i++) fa[i]=i;
		for(int u=1; u<=n; u++){
			if(!(s>>(u-1)&1)) continue;
			for(int v:g[u]){
				if(!(s>>(v-1)&1)) continue;
				merge(u, v);
			}
		}
		int cnt=0;
		for(int i=1; i<=n; i++){
			if((s>>(i-1)&1) && fa[i]==i) cnt++;
		}
//		if(s==9) cerr<<cnt<<"\n";
//		if(s==9){
//			ans=ans;
//		}
		if(cnt>2) continue;
		int res=0;
		for(int i=1; i<=n; i++){
			for(int j=0; j<=n; j++) d[j]=0;
			dfs(i, 0);
			int now=INF;
			for(int j=1; j<=n; j++){
				if((s>>(j-1)&1))
					now=min(now, d[j]);
			}
			if(now!=INF) res=max(res, now);
		}
		ans=min(ans, res);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	fastio();
	cin>>ID>>t;
	while(t--) solve();
	return 0;
}
/*
0 1
5 2
1 2
2 3
3 4
4 5
*/
