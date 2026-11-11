#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxm=5e3+7;
ll c,n,m,d,q,w[maxm],t[maxm][maxm],st,ed,ans;
int vis[maxm];
struct node{
	ll u,v;
}g[maxm];
void dfs(int x,ll dis){
	if(x==ed){
		ans=min(ans,dis);
		return;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(g[i].u==x&&!vis[g[i].v]){
			dfs(g[i].v,dis+t[i][x]+t[i][g[i].v]);
		}
		if(g[i].v==x&&!vis[g[i].u]){
			dfs(g[i].u,dis+t[i][x]+t[i][g[i].u]);
		}
	}
}
void solve(){
	memset(vis,0,sizeof(vis));
	dfs(st,0);
	cout<<ans+w[st]+w[ed]<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,a1,a2,a3,a4;
		cin>>k>>a1>>a2>>a3>>a4;
		g[i]={a1,a3};
		t[a1][i]=t[i][a1]=a2;
		t[a3][i]=t[i][a3]=a4;
	}
	while(q--){
		ans=LLONG_MAX;
		cin>>st>>ed;
		solve();
	}
	return 0;
}