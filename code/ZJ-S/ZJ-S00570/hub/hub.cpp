#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=10+10;
ll n,k;
vector<ll>g[N];
ll dep[N],f[N][20];
ll vis[N];
ll mark[N];
void dfs(ll x,ll fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(ll i=1;i<=19;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(auto to:g[x]){
		if(to==fa)continue;
		dfs(to,x);
	} 
}
ll lca(ll x,ll y){
	if(dep[x]<dep[y])swap(x,y);
	ll h=dep[x]-dep[y];
	for(ll i=0;i<=19;i++){
		if(h&(1<<i))x=f[x][i];
	}
	if(x==y)return x;
	for(ll i=19;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
void bfs(ll x){
	mark[x]=1;
	for(auto to:g[x]){
		if(vis[to]&&!mark[to]){
			bfs(to);
		}
	}
}
ll dis(ll x,ll y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
} 
void solve(){
	cin>>n>>k;
	for(ll i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
//	cout<<"!!"<<lca(1,2);
	ll ans=INT_MAX;
	for(ll i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)==k){
			memset(vis,0,sizeof vis);
			memset(mark,0,sizeof mark);
			for(ll j=0;j<n;j++){
				if(i&(1<<j))vis[j+1]=1;
			}
//			cout<<"??";
//			for(ll j=1;j<=n;j++){
//				cout<<vis[j]<<" ";
//			}
			ll cnt=0;
			for(ll j=1;j<=n;j++){
				if(vis[j]&&!mark[j]){
					bfs(j);
					cnt++;
				}
			}
			if(cnt>2)continue;
			ll mx=0;
			for(ll j=1;j<=n;j++){
				ll mn=INT_MAX;
				for(ll k=1;k<=n;k++){
					if(vis[k]){
//						cout<<k<<" ";
						mn=min(mn,dis(j,k));
					}
				}
//				cout<<"??"<<j<<":"<<mn<<endl;
				mx=max(mx,mn);
			}
//			cout<<"??"<<mx;
			ans=min(ans,mx);
		}
	}
	cout<<ans<<"\n";
	for(ll i=1;i<=n;i++)g[i].clear();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}
//0 2
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10
