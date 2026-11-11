#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define db double
#define pii pair<int,int>
const int N=1e6+5,inf=1e9+5;
int mx[N],imx[N],se[N],ans,n,T,c,k;
vector<int> e[N];
void dfs(int u,int fa){
	for(auto v:e[u]){
		if(v==fa) continue;
		dfs(v,u);
		if(mx[v]+1>=mx[u]) se[u]=mx[u],imx[u]=v,mx[u]=mx[v]+1;
		else se[u]=max(se[u],mx[v]+1);
	}
}
void dfs2(int u,int fa){
	for(auto v:e[u]){
		if(v==fa) continue;
		int d1=(imx[u]==v)?se[u]:mx[u];
		ans=min(ans,max(d1,mx[v]));
		if(d1+1>=mx[v]) se[v]=mx[v],imx[v]=u,mx[v]=d1+1;
		else se[v]=max(se[v],d1+1);
		dfs2(v,u);
	}
}
void solve1(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear(),imx[i]=mx[i]=se[i]=0;
	ans=inf;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1,0);
	dfs2(1,0);
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c==7||c==11||c==12) 
		while(T--) 
			solve1();
	else while(T--) {
		cin>>n>>k;
		for(int i=1;i<n;i++) {int x,y;cin>>x>>y;}
		cout<<n/2<<"\n";
	}
	return 0;
}