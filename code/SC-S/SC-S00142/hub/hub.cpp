#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
#define ppcnt(x) __builtin_popcount(x)
#define endl '\n'
using namespace std;
const int N=1e6+10;
		
int n,m,a[N];
int fa[N],Fa[N],dep[N];
pii E[N];
vector<int> e[N];
int cnt=0;
inline int find(int u) {return (fa[u]==u)?(u):(fa[u]=find(fa[u]));}
void dfs(int u,int fa) {
	Fa[u]=fa,dep[u]=dep[fa]+1;
	for (auto v : e[u]) {
		if (v==fa) continue;
		dfs(v,u);
	}
	return ;
}
int LCA(int u,int v) {
	if (dep[u]<dep[v]) swap(u,v);
	while (dep[u]!=dep[v]) u=Fa[u];
	while (u!=v) u=Fa[u],v=Fa[v];
	return u;
}
void Clear() {
	rep(i,1,n) {
		e[i].clear();
		fa[i]=Fa[i]=dep[i]=a[i]=0;
	}
	return ;
}
int dis[N],rt=0,res=0;
void df5(int u,int fa) {
	if (dis[u]>dis[rt]) rt=u;
	for (auto v : e[u]) {
		if (v==fa) continue;
		dis[v]=dis[u]+1;
		df5(v,u);
	}
	return ;
}
void dfz(int u,int fa) {
	if (dis[u]>res) res=dis[u];
	for (auto v : e[u]) {
		if (v==fa) continue;
		dis[v]=dis[u]+1;
		dfz(v,u);
	}
	return ;
} 
void solve() {
	cin>>n>>m;
	rep(i,1,n-1) {
		int u,v;cin>>u>>v;
		E[i]={u,v};
		e[u].eb(v),e[v].eb(u);
	}
	if (n<=10) {
		dfs(1,0);
		int res=n;
		rep(S,0,(1<<n)-1) if (ppcnt(S)==m) {
			rep(i,1,n) a[i]=((S>>(i-1))&1);
			iota(fa+1,fa+n+1,1);
			rep(i,1,n-1) {
				int u=E[i].first,v=E[i].second;
				if (a[u] and a[v]) {
					u=find(u),v=find(v);
					fa[u]=v;
				}
			} 
			int cnt=0;
			rep(i,1,n) if (find(i)==i and a[i]) cnt++;
			if (cnt>2) continue;
			dfs(1,0);
			int val=0;
			rep(i,1,n) if (!a[i]) {
				int now=n;
				rep(j,1,n) if (a[j]) now=min(now,dep[i]+dep[j]-2*dep[LCA(i,j)]);
				val=max(val,now);
			}
			res=min(res,val);
		}
		cout<<res<<endl;
		return Clear();
	}
	dis[1]=dis[rt=0]=0;
	df5(1,0);
	dis[rt]=res=0;
	dfz(rt,0);
	cout<<(res/2)<<endl;
	return Clear();
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,_;cin>>c>>_;
	while (_--) solve();
	return 0;
}
/*
简化题意：
给你一棵树，让你选 k 个点，至多两个连通块
val = max(dis(S,i))
求 min (val)
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
*/