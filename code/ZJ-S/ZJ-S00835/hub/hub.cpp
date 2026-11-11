#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
const int N=1e6+10,M=5e2+10,MOD=1e9+7;
const ll inf=1e18;
ll c,n,k,pre[N][30],dep[N];
vector<ll> G[N];
vector<pa> edge;
void dfs(ll x,ll fa=0){
	pre[x][0]=fa;
	for(int i=1;i<=20;i++) pre[x][i]=pre[pre[x][i-1]][i-1];
	dep[x]=dep[fa]+1;
	for(auto v:G[x]){
		if(v==fa) continue;
		dfs(v,x);
	}
}
ll lca(ll u,ll v){
	if(dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;i<=20;i++){
		if(d&(1<<i)) u=pre[u][i];
	}
	if(u==v) return u;
	for(int i=20;i>=0;i--){
		if(pre[u][i]!=pre[v][i]){
			u=pre[u][i];
			v=pre[v][i];
		}
	}
	return pre[u][0];
}
ll fa[N];
ll find(ll x){
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(ll x,ll y,ll &sum){
	ll fx=find(x),fy=find(y);
	if(fx!=fy) fa[fy]=fx,sum--;
}
void main1(){
	for(int i=0;i<(1<<n);i++){
		ll t=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1) t++;
		}
		if(t!=k) continue;
		for(int j=1;j<=n;j++) fa[j]=j;
		ll sum=k;
		for(int j=0;j<n-1;j++){
			ll u=edge[j].first,v=edge[j].second;
			if(((i>>(u-1))&1)&&((i>>(v-1))&1)) merge(u,v,sum);
		}
		if(sum>2) continue;
		ll sum=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1) continue;
			for(int l=1;l<=n;l++){
				if((i>>(j-1))&1){
					
				}
			}
		}
	}
}
//7,11,12
int dep2[N];
void dfs(int x,int fa=0){
	dep2[x]=dep2[fa]+1;
	for(auto v:G[x]){
		if(v==fa) continue;
		dfs(v,x);
	}
}
void main2(){
	
}
//13,14
void main3(){
	if(n==k) cout<<"0\n";
	else if(k>(n/2)) cout<<"1\n";
	else{
		ll t=n/4+1;
		cout<<max(2ll,t-k+1)<<"\n";
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	edge.clear();
	for(int i=1;i<n;i++){
		ll u,v; cin>>u>>v;
		edge.push_back({u,v});
		G[u].push_back(v);
		G[v].push_back(u);
	}
	main1();
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IOS;
	int _=1;
	cin>>c>>_;
	while(_--) solve();
	return 0;
}
/*

*/
