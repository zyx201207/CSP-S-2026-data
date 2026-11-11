#include<bits/stdc++.h>
using namespace std;
#define ll  long long
const ll nn=5e5+5;
ll c,n,m,d,q,a[nn],dis[2*nn],vis[2*nn],deep[2*nn],f[2*nn][25];
struct node{
	ll v,w;
};
vector<node> g[2*nn];
void dfs(ll x,ll d){
	vis[x]=1;deep[x]=d;
	for(ll i=1;(1<<i)<=d;i++)f[x][i]=f[f[x][i-1]][i-1];//1~19 19~1
	for(node i:g[x]){
		ll v=i.v,w=i.w;
		if(vis[v])continue;
		f[v][0]=x;
		dis[v]=min(dis[x]+w,dis[v]);
		dfs(v,d+1);
	}
}
ll lca(ll a,ll b){
	if(deep[a]<deep[b]) swap(a,b);
	ll k=deep[a]-deep[b];
	for(ll i=19;i>=0;i--){
		if(k&(1<<i)) a=f[a][i];
	}
	if(a==b) return a;
	for(ll i=19;i>=0;i--){
		if(f[a][i]!=f[b][i]){
			a=f[a][i];b=f[b][i];
		}
	}
	return f[a][0];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>a[i];dis[i]=dis[i+m]=INT_MAX;
	}
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		for(ll j=1;j<=k;j++){
			ll x,y;cin>>x>>y;
			g[m+i].push_back(node{x,y});
			g[x].push_back(node{m+i,y});
		}
	}dis[1]=0;
	dfs(1,0);
	for(ll i=1;i<=q;i++){
		ll x,y;cin>>x>>y;
		ll z=lca(x,y);
		cout<<dis[x]-dis[z]+dis[y]-dis[z]+a[x]+a[y]<<"\n";
	}
	return 0;
}