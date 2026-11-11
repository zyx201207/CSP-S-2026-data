#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> subway[501];
ll w[500010],k[501],t[501][250001];
ll vis[500001];
vector<ll> zhan[500001];
ll n,m,c,d,q;
ll sx,sy;
ll ans=LLONG_MAX;
bool flag=true;
struct st{
	ll u,v;
};
vector<st> e[500001];
set<ll> s;
void dfs(ll xi,ll x,ll tim){
	if(x==sy){
		ans=min(ans,tim+w[sy]);
		return;
	}
	for(auto xian:zhan[x]){
		if(xian==xi) continue;
		for(auto it:subway[xian]){
			if(it==x) continue;
			if((zhan[it].size()>1||it==sy)&&vis[it]==0){
				vis[it]=1;
				dfs(xian,it,tim+t[xian][x]+t[xian][it]);
				vis[it]=0;
			}
		}
	}
}
void dfs2(ll x,ll tim){
	if(x==sy){
		ans=min(ans,tim+w[sy]);
		return;
	}
	for(auto it:e[x]){
		if(vis[it.u]==0){
			vis[it.u]=1;
			dfs2(it.u,tim+it.v);
			vis[it.u]=0;
		}
	}
}
void solve(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]<=1) continue;
		ll x,y,z,j;
		cin>>x>>y>>z>>j;
		e[x].push_back({z,y+j});
		e[z].push_back({x,y+j});
	}
	while(q--){
		ans=LLONG_MAX;
		memset(vis,0,sizeof(vis));
		cin>>sx>>sy;
		dfs2(sx,w[sx]);
		cout<<ans<<"\n";
	}
}
void solve2(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	ll aaa=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll x;
			cin>>x;
			cin>>t[i][x];
			if(i==1) s.insert(x);
			if(i==2){
				if(s.count(x)>0){
					aaa=max(aaa,t[1][x]+t[2][x]);
				}
			}
		}
	}
	while(q--){
		cin>>sx>>sy;
		if(n==1) cout<<w[sx]+w[sy]<<"\n";
		else cout<<w[sx]+w[sy]+aaa<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	if(q>2000&&n<=2&&d>2){
		if(n>2){
			solve();
		}else{
			solve2();
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			ll x;
			cin>>x;
			cin>>t[i][x];
			subway[i].push_back(x);
			zhan[x].push_back(i);
		}
	}
	while(q--){
		ans=LLONG_MAX;
		memset(vis,0,sizeof(vis));
		cin>>sx>>sy;
		dfs(0,sx,w[sx]);
		cout<<ans<<"\n";
	}
	return 0;
}
