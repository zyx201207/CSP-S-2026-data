// 管晨清 陕西省西安爱知中学 SN-S00356 
#include<bits/stdc++.h>
#define ll int
#define endl '\n'
#define pr pair<ll,ll>
#define fr first 
#define sec second 
using namespace std;
const ll N=5e5+10;
ll dis[N];
ll c,n,m,d,q,k;
ll w[N];
ll a[N],x[N],y[N];
map<ll,ll>t[600],id[600];
struct node{
	ll to,tp;
};
vector<node>G[N];
void Dijkstra(ll s){
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[s]=0;
	priority_queue<pr,vector<pr>,greater<pr> >Q;
	Q.push({s,0});
	while(!Q.empty()){
		pr u=Q.top();
		Q.pop();
		if(dis[u.fr]!=u.sec) continue;
		for(auto i:G[u.fr]){
			if(u.sec+t[i.tp][id[i.tp][u.fr]]+t[i.tp][id[i.tp][i.to]]<dis[i.to]) {
				dis[i.to]=u.sec+t[i.tp][id[i.tp][u.fr]]+t[i.tp][id[i.tp][i.to]];
				Q.push({i.to,dis[i.to]});
			}
		}
	}
}
bool vis[N];
ll Dij(ll s,ll y){
	queue<pr>Q;
	Q.push({s,0});
	vis[s]=true;
	while(!Q.empty()){
		pr u=Q.front();
		Q.pop();
		if(u.fr==y) return u.sec;
		//if(dis[u.fr]!=u.sec) continue;
		for(auto i:G[u.fr]){
			if(!vis[i.to]) {
				//dis[i.to]=u.sec+2;
				Q.push({i.to,u.sec+2});
				vis[i.to]=true;
			}
		}
	}
}
void solve(){
	for(ll i=1;i<=m;++i) cin>>w[i];
	for(ll i=1;i<=n;++i){
		cin>>k;
		for(ll j=1;j<=k;++j){
			ll x;
			cin>>a[j]>>x;
			//id[i][a[j]]=j;
			//v.push_back({a[j],i});
		}
		for(ll j=1;j<=k;++j){
			for(ll l=1;l<=k;++l)G[a[j]].push_back({a[l],i});
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		memset(vis,0,sizeof vis);
		cout<<Dij(x,y)+w[x]+w[y]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c>=12&&c<=15){
		solve();
		return 0;
	}
	for(ll i=1;i<=m;++i) cin>>w[i];
	for(ll i=1;i<=n;++i){
		cin>>k;
		for(ll j=1;j<=k;++j){
			cin>>a[j]>>t[i][j];
			id[i][a[j]]=j;
			//v.push_back({a[j],i});
		}
		for(ll j=1;j<=k;++j){
			for(ll l=1;l<=k;++l)G[a[j]].push_back({a[l],i});
		}
	}
//	for(ll i=1;i<=n;++i){
//		for(auto j:G[i]) cout<<i<<' '<<j.to<<' '<<j.tp<<endl;
//	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		Dijkstra(x);
		cout<<dis[y]+w[x]+w[y]<<endl;
		//cout<<dis[y]<<' '<<w[x]<<' '<<w[y]<<endl;
	}
} 
