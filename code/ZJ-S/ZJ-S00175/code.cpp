#include<bits/stdc++.h>
// #include<cassert>
// #define int long long
#define maxn 1050050
#define fi first
#define se second
using namespace std;
const int inf=(int)1e18+7;

int n,k,d,rt,cnt,nd[maxn],l[maxn],gl[maxn],lson[maxn],clson[maxn],fa[20][maxn],dep[maxn],ed[maxn];
int F[maxn],G[maxn];
pair<int,int>f[maxn];
tuple<int,int,int>g[maxn];
vector<int>e[maxn];
void dfs(int x,int lst){
	dep[x]=dep[lst]+1;
	fa[0][x]=lst;
	if(dep[x]>dep[rt]) rt=x;
	for(auto i:e[x]) if(i!=lst){
		dfs(i,x);
	}
}
void dfs1(int x,int lst){
	fa[0][x]=lst;
	dep[x]=dep[lst]+1;
	l[x]=lson[x]=clson[x]=0;
	for(int i:e[x]) if(i!=lst){
		dfs1(i,x);
		if(l[i]>=l[lson[x]]) clson[x]=lson[x],lson[x]=i;
		else if(l[i]>=l[clson[x]]) clson[x]=i;
	}
	if(lson[x]) l[x]=l[lson[x]]+1,ed[x]=ed[lson[x]];
	else ed[x]=x;
}
void dfs2(int x,int lst){
	nd[++cnt]=x;
	for(int i:e[x]) if(i!=lst){
		int oth=l[x]+1;
		if(x==lson[x]){
			if(clson[x]) oth=l[clson[x]]+2;
			else oth=1;
		}
		gl[i]=max(oth,gl[x]+1);
		dfs2(i,x);
	}
}
inline int getfa(int x,int k){
	while(k) x=fa[__builtin_ctz(k)][x],k&=k-1;
	return x;
}
int check(int _d){
	d=_d;
	for(int it=n;it>=1;it--){
		int x=nd[it];
		F[x]=l[x]>=d;
		for(int i:e[x]) if(i!=fa[0][x]) F[x]+=F[i];
	}
	for(int it=n;it>=1;it--){
		int x=nd[it];
		if(l[x]<d){
			f[x]=make_pair(1,x);
			continue;
		}
		int maxx=0;
		for(int i:e[x]) if(i!=fa[0][x]&&i!=lson[x]){
			maxx=max(maxx,l[i]+1);
		}
		if(maxx>=d){
			f[x]=make_pair(max(1,F[x]),x);
			continue;
		}
		int u=f[lson[x]].se;
		if(dep[u]-dep[x]>d-maxx) u=getfa(u,dep[u]-dep[x]-(d-maxx));
		f[x]=make_pair(max(1,F[u]),u);
	}
	// for(int i=1;i<=n;i++) cerr<<F[i]<<' ';cerr<<'\n';
	if(f[rt].fi<=k) return 1;
	// for(int i=1;i<=n;i++) cerr<<f[i].fi<<' ';cerr<<'\n';
	G[rt]=0;
	for(int it=1;it<=n;it++){
		int x=nd[it],cur=G[x]+F[x];
		cur-=l[x]>=d;
		for(int i:e[x]) if(i!=fa[0][x]){
			G[i]=cur-F[i]+(gl[i]-1>=d);
		}
	}
	for(int i=1;i<=n;i++) G[i]=max(G[i],1);
	G[rt]=0;
	// for(int i=1;i<=n;i++) cerr<<G[i]<<' ';cerr<<'\n';
	for(int it=0;it<e[rt].size();it++){
		int id=e[rt].size()-1;
		while(id>=0&&id==it) id--;
		int u=ed[e[rt][id]];
		id--;
		while(id>=0&&id==it) id--;
		int oth=0;
		if(id>=0) oth=l[e[rt][id]]+1;
		if(oth>=d){
			g[e[rt][it]]=make_tuple(G[e[rt][it]],rt,rt);
			continue;
		}
		if(dep[u]-dep[rt]>d-oth) u=getfa(u,dep[u]-dep[rt]-(d-oth));
		assert(u!=rt);
		assert(u);
		// cerr<<e[rt][it]<<' '<<u<<'\n';
		g[e[rt][it]]=make_tuple(F[u],u,rt);
	}
	for(int it=2;it<=n;it++){
		int x=nd[it];
		// if(f[x].fi+get<0>(g[x])<=k){
		// 	cerr<<x<<' '<<f[x].fi<<' '<<get<0>(g[x])<<'\n';
		// }
		if(f[x].fi+get<0>(g[x])<=k) return 1;
		if(l[x]==0) continue;
		{
			int u=get<1>(g[x]),lca=get<2>(g[x]);
			if(l[x]<=d){
				if(dep[u]-dep[lca]+dep[x]-dep[lca]>d-l[x]){
					if(dep[x]-dep[lca]>d-l[x]) u=lca=getfa(x,d-l[x]);
					else u=getfa(u,dep[u]-dep[lca]+dep[x]-dep[lca]-(d-l[x]));
				}
			}
			else u=lca=x;
			for(auto i:e[x]) if(i!=fa[0][x]&&i!=lson[x]){
				get<1>(g[i])=u,get<2>(g[i])=lca;
				if(u==lca) get<0>(g[i])=G[getfa(i,dep[i]-dep[u]-1)];
				else get<0>(g[i])=F[u];
			}
		}
		{
			int u=get<1>(g[x]),lca=get<2>(g[x]),oth=0;
			if(clson[x]) oth=l[clson[x]]+1;
			if(oth<=d){
				if(dep[u]-dep[lca]+dep[x]-dep[lca]>d-oth){
					if(dep[x]-dep[lca]>d-oth) u=lca=getfa(x,d-oth);
					else u=getfa(u,dep[u]-dep[lca]+dep[x]-dep[lca]-(d-oth));
				}
			}
			else u=lca=x;
			get<1>(g[lson[x]])=u,get<2>(g[lson[x]])=lca;
			if(u==lca) get<0>(g[lson[x]])=G[getfa(lson[x],dep[lson[x]]-dep[u]-1)];
			else get<0>(g[lson[x]])=F[u];
		}
	}
	// for(int i=1;i<=n;i++) cerr<<get<0>(g[i])<<' ';cerr<<'\n';
	return 0;
}
inline void solve(){
	for(int i=1;i<=n;i++) e[i].clear();
	cnt=0;
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++) cin>>u>>v,e[u].emplace_back(v),e[v].emplace_back(u);
	rt=0,dfs(1,0);
	int r=rt;
	dfs(rt,0);
	int R,len=dep[rt]-1>>1;
	R=len-1;
	while(len--) rt=fa[0][rt];
	// #ifdef LOCAL
	// rt=3;
	// #endif
	dfs1(rt,0);
	sort(e[rt].begin(),e[rt].end(),[&](int x,int y){
		return l[x]<l[y];
	});
	gl[rt]=0;
	dfs2(rt,0);
	// for(int i=1;i<=n;i++) cerr<<gl[i]<<' ';cerr<<'\n';
	for(int i=1;i<20;i++) for(int j=1;j<=n;j++) fa[i][j]=fa[i-1][fa[i-1][j]];
	int L=0,ans=R+1;
	// cout<<rt<<' '<<ans<<' '<<check(1)<<'\n';
	while(L<=R){
		int mid=L+R>>1;
		if(check(mid)) ans=mid,R=mid-1;
		else L=mid+1;
	}
	cout<<ans<<'\n';
}
signed main(){
	#define FILE "test"
	#ifdef LOCAL
	assert(freopen("test.in","r",stdin));
	assert(freopen("test.out","w",stdout));
	#else
	// assert(freopen(FILE".in","r",stdin));
	// assert(freopen(FILE".out","w",stdout));
	#endif
	int T=1,Cid;
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>Cid>>T;
	while(T--) solve();
	cerr<<"Time: "<<clock()*1000/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}