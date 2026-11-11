#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=1000600,INF=LLONG_MAX;
struct bian{
	int x,w,y;
};
int c,n,m,d,q;
vector<bian> e;
vector<pii> e2[N];
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int f[N][22],dt[N][22],dep[N];
void dfs(int u,int ff,int w){
	dep[u]=dep[ff]+1;
	f[u][0]=ff;
	dt[u][0]=w;
	for(int i=1;i<22;i++){
		f[u][i]=f[f[u][i-1]][i-1];
		dt[u][i]=dt[u][i-1]+dt[f[u][i-1]][i-1];
	}
	for(pii to:e2[u]) if(to.se!=ff){
		int v=to.se,nw=to.fi;
		dfs(v,u,nw);
	}
}
int dis(int x,int y){
	int rt=0;
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=21;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]){
			rt+=dt[x][i];
			x=f[x][i];
		}
	}
	if(x==y) return rt;
	for(int i=21;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			rt+=dt[x][i]+dt[y][i];
			x=f[x][i];
			y=f[y][i];
		}
	}
	rt+=dt[x][0]+dt[y][0];
	return rt;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w; cin>>w;
		e.pb({i,w,m+i});
	}
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		for(int j=1;j<=k;j++){
			int a,t; cin>>a>>t;
			e.pb({2*m+i,t,a+m});
		}
	}
	sort(e.begin(),e.end(),[](const bian &a,const bian &b){
		return a.w<b.w;
	});
	for(int i=1;i<=m*2+n;i++) fa[i]=i;
	for(bian nw:e){
		int x=nw.x,y=nw.y,w=nw.w;
		int fx=find(x),fy=find(y);
		if(fx==fy) continue;
		fa[fx]=fy;
		e2[x].pb({w,y});
		e2[y].pb({w,x});
	}
//	for(int i=1;i<=n;i++){
//		cout<<i<<".e2:";
//		for(pii to:e2[i]) cout<<to.se<<' ';
//		cout<<endl;
//	}
	dfs(1,0,0);
	while(q--){
		int x,y; cin>>x>>y;
		cout<<dis(x,y)<<endl;
	} 
	return 0;
}/*
Oct31==Dec25?

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/

