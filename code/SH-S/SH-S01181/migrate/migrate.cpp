#include<bits/stdc++.h>
using namespace std;
#define int long long
#define foR(i,a,b,c) for(int i=a;i<=b;i+=c)
#define For(i,a,b,c) for(int i=a;i>=b;i-=c)
#define il inline
il void file(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
const int maxn=5e5+5;
int n,m,a[maxn],diff[maxn],pre[maxn];
int dfn[maxn],htop[maxn],sz[maxn],f[maxn];
il void dfs1(int u,int f){
	dep[u]=dep[f]+1,sz[u]+=sz[v];
	
}
il void dfs2(int u,int tp){
	for(int i=head[u];~i;i=e[i].nxt){
		int v=e[i].to,w=e[i].w;
	}
	if(!hson[u]){
		dfs2(v,v);
	}
}
signed main(){
	file();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	foR(i,1,n,1){
		cin>>a[i];
	}
	return 0;
}


