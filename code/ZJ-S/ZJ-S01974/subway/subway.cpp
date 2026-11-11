#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int C,n,m,D,Q,ww[500005],up[500505][20],fa[500505],dep[500505],tot;
ll dis[500505];
struct nn{
	int u,v,w;
};
vector<nn> q;
struct dd{
	int v,w;
};
vector<dd> tr[500505];
inline bool cmp(const nn &x,const nn &y){
	return x.w<y.w;
}
inline find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}
void init(const int &u,const int &fa,const int &w){
	dep[u]=dep[fa]+1;
	dis[u]=dis[fa]+w;
	up[u][0]=fa;
	for(int i=1;i<20;++i){
		up[u][i]=up[up[u][i-1]][i-1];
	}
	for(const auto &v:tr[u]){
		if(v.v!=fa){
			init(v.v,u,v.w);
		}
	}
}
inline int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	const int diff=dep[u]-dep[v];
	for(int i=0;i<20;++i){
		if((diff>>i)&1) u=up[u][i];
	}
	if(u==v) return u;
	for(int i=19;i>=0;--i){
		if(up[u][i]!=up[v][i]){
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>m>>n>>D>>Q;
	for(int i=1;i<=n+m;++i){
		fa[i]=i;
	}
	for(int i=1;i<=n;++i){
		cin>>ww[i];
	}
	for(int i=1;i<=m;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int v,w;
			cin>>v>>w;
			q.push_back({n+i,v,w});
		}
	}
	sort(q.begin(),q.end(),cmp);
	for(const auto &e:q){
		int uu=find(e.u),vv=find(e.v);
		if(uu!=vv){
			fa[vv]=uu;
			++tot;
			tr[e.u].push_back({e.v,e.w});
			tr[e.v].push_back({e.u,e.w});
		}
		if(tot==n+m-1) break;
	}
	init(1,0,0);
	for(int i=1;i<=Q;++i){
		int u,v;
		cin>>u>>v;
		cout<<ww[u]+ww[v]+dis[u]+dis[v]-2*dis[lca(u,v)]<<"\n";
	}
	//cerr<<sizeof(tr)+sizeof(q)+sizeof(dep)+sizeof(dis)+sizeof(fa)+sizeof(ww)+sizeof(up);
	return 0;
}