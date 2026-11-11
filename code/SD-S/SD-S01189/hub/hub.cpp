#include<bits/stdc++.h>
#define int long long
#define double long double
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int N=2e6+10;
int n,k;
pii e[N];
vector<int>g[N];
int sz[N],fa[N],hson[N];
int dep[N],top[N];
void dfs1(int u,int f){
	sz[u]=1;
	int mx=-1;
	fa[u]=f;
	for(int v:g[u])if(v!=f){
		dfs1(v,u);
		mx=max(mx,sz[v]);
		if(mx==sz[v]){
			hson[u]=v;
		}
		sz[u]+=sz[v];
	}
	return ;
}
void dfs2(int u,int tp){
	top[u]=tp;
	dep[u]=dep[fa[u]]+1;
	if(sz[u]==1)return ;
	dfs2(hson[u],tp);
	for(int v:g[u])if(v!=fa[u]&&v!=hson[u]){
		dfs2(v,v);
	}
	return ;
}
int lca(int u,int v){
//	cout<<u<<" "<<v<<" ";
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]){
			swap(u,v);
		}
		u=fa[top[u]];
	}
//	cout<<u<<" "<<v<<" "<<(dep[u]<dep[v]?u:v)<<endl;
	return (dep[u]<dep[v]?u:v);
}
int ff[N];
int find(int u){
	return (ff[u]==u?u:ff[u]=find(ff[u]));
}
bool iss[N];
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		g[i].clear();
		sz[i]=fa[i]=dep[i]=hson[i]=top[i]=0;
	}
	for(int i=1;i<n;i++){
		cin>>e[i].fi>>e[i].se;
		g[e[i].fi].push_back(e[i].se);
		g[e[i].se].push_back(e[i].fi);
	}
	dfs1(1,0);
	dfs2(1,1);
	int ans=LLONG_MAX;
	for(int msk=1;msk<=(1ll<<n)-1;msk++)if(__builtin_popcount(msk)==k){
		for(int j=1;j<=n;j++){
			if(msk&(1<<(j-1))){
				iss[j]=1;
				ff[j]=j;
			}else{
				iss[j]=0;
			}
		}
		for(int i=1;i<n;i++)if(iss[e[i].fi]&&iss[e[i].se]){
			ff[find(e[i].fi)]=find(e[i].se);
		}
		set<int>st;
		for(int i=1;i<=n;i++)if(iss[i]){
			st.insert(find(i));
		}
		if(st.size()>2)continue ;
		int mx=0;
		for(int i=1;i<=n;i++)if(!iss[i]){
			int mn=LONG_MAX;
			for(int j=1;j<=n;j++)if(iss[j]){
				if(dep[i]+dep[j]-2*dep[lca(i,j)]==0)cout<<"! "<<i<<" "<<j<<endl;
				mn=min(mn,dep[i]+dep[j]-2*dep[lca(i,j)]);
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
	}
	cout<<ans<<endl;
	return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c=0,T=0;
	cin>>c>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
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

0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
*/
