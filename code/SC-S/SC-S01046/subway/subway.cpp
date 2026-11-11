#include<bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define dep(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
template<typename T> void read(T&x){x=0;T f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();x*=f;}
template<typename T1,typename ...T2> void read(T1&x,T2&... y){read(x),read(y...);}
const int N=5e5+15,M=500+15,inf=1e15;

int n,m,d,q;
int w[N],mp[M][M];
vector<pii> g[N];

void solve(){
	read(n,m,d,q);
	rep(i,1,m) read(w[i]);
	rep(i,1,n) rep(j,1,n) mp[i][j]=inf;
	rep(i,1,n) mp[i][i]=0;
	rep(i,1,n){
		int k;read(k);
		while(k--){
			int x,t;read(x,t);
			g[x].push_back({i,t});
		}
	}
	rep(i,1,m) for(auto [u,w1]:g[i]) for(auto[v,w2]:g[i]) mp[u][v]=mp[v][u]=min(w1+w2,mp[u][v]);
	rep(k,1,n) rep(i,1,n) rep(j,1,n) mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		int res=inf;
		for(auto [u,w1]:g[x]) for(auto[v,w2]:g[y]) res=min(res,w1+w2+mp[u][v]);
		cout<<res+w[x]+w[y]<<'\n';
	}
}

#define NAME "subway"

signed main(){
#ifdef NAME
	freopen(NAME".in","r",stdin);
	freopen(NAME".out","w",stdout);
#endif
	int c;read(c);
	solve();
	return 0;
}
/*
好像会了
因为你一个点最多 20 个
那么暴力更连边是 400m
跑最短路 n^3
查询 400q
过了吧
*/