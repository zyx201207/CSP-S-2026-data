#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 200005;
const int INF = 0x3f3f3f3f;
int n, k;
vector<int> G[N];
int fa[N], top[N], son[N], dep[N], sz[N];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	sz[u]=1;
	for(auto v:G[u]){
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int h){
	top[u]=h;
	if(son[u]) dfs2(son[u], h);
	for(auto v:G[u]){
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]) x=fa[top[x]];
		else y=fa[top[y]];
	}
	return dep[x]<dep[y]?x:y;
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
int p[N];
int find(int x){
	if(x==p[x]) return x;
	return p[x] = find(p[x]);
}
void merge(int x,int y){
	int px=find(x), py=find(y);
	if(px==py) return;
	p[px]=py;
}
int d[1005][1005];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		map<pair<int,int>,bool> mp;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			mp[{u,v}]=mp[{v,u}]=1;
		}
		for(int i=1;i<=n;i++) fa[i]=sz[i]=dep[i]=top[i]=son[i]=0;
		dfs1(1), dfs2(1,1);
		if(n<=10){
			int ans = n;
			for(int i=1;i<1<<n;i++){
				vector<int> vc;
				for(int j=0;j<n;j++){
					if(i>>j&1) vc.push_back(j+1);
				}
				if((int)vc.size()>k) continue;
				for(int i=1;i<=n;i++) p[i]=i;
				for(auto x:vc){
					for(auto y:vc){
						if(mp[{x,y}]) merge(x,y);
					}
				}
				int cnt = 0;
				for(int i=1;i<(int)vc.size();i++){
					if(find(vc[i])!=find(vc[0])) cnt++;
				}
				if(cnt>1) continue;
				int mx = 0;
				for(int j=1;j<=n;j++){
					int mn = n;
					for(auto x:vc) mn=min(mn, dis(j,x));
					mx=max(mx,mn);
				}
				ans=min(ans, mx);
			}
			cout<<ans<<"\n";
		}else if(k==2){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) d[i][j] = dis(i, j);
			}
			int ans = n;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int mx=0;
					for(int k=1;k<=n;k++) mx=max(mx,min(d[i][k],d[j][k]));
					ans=min(ans,mx);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}