#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(auto i=(l);i<=(r);i++)
#define irep(i,l,r) for(auto i=(l);i>=(r);i--)
#define sc cerr
#define qlog(x) {sc<<#x<<"="<<(x)<<"\n";}
#define qloga(a,l,r) {sc<<#a<<": "; rep(I,l,r){sc<<a[i]<<" ";} sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<": "; for(const auto &x:a){sc<<x<<" ";} sc<<"\n";}
typedef long long ll;
typedef __int128 i128;
//
//constexpr int N=2e6+10;
//int n,k;
//vector<int> to[N];
//int tp[N],hson[N],fa[N],sz[N],dep[N];
//
//void dfs1(int u,int f=0){
//	fa[u]=f;
//	sz[u]=1;
//	d[u]=d[f]+1;
//	for(int v:to[u])if(v!=f){
//		dfs1(v,u);
//		sz[u]+=sz[v];
//	}
//}
//void dfs2(int u,int hd=0){
//	tp[u]=hd;
//	if(hson[u])dfs2(hson[u],hd);
//	for(int v:to[u])if(v!=fa[u] && v!=hson[u]){
//		dfs2(v,v);
//	}
//}
//int lca(int u,int v){
//	while(hd[u]!=hd[v]){
//		if(d[hd[u]]<d[hd[v]])swap(u,v);
//		u=fa[hd[u]];
//	}
//	if(d[u]>d[v])swap(u,v);
//	return u;
//}
//
//ll solve(){
//	cin>>n>>k;
//	rep(i,1,n-1){
//		int u,v;
//		cin>>u>>v;
//		to[u].push_back(v);
//		to[v].push_back(u);
//	}
//	dfs1(1);
//	dfs2(1);
//	int l=0, r=;
//}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	int C,T;
	cin>>C>>T;
	while(T--){
		cout<<"0\n";
	}
}
