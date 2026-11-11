#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll> 
using namespace std;
const ll N=6e5+10;
ll c,n,m,d,q,x,y,ans,w[N],k[555],dis[N],diss[555][555];
bool vis[N];
vector<PII>e[N];
void Dij(ll s){
	for(ll i=1;i<=n+m+10;i++)vis[i]=0,dis[i]=1e18;
	multiset<PII>q;
	dis[s]=0;
	q.insert({0ll,s});
	while(q.size()){
		ll u=(q.begin())->second;
		q.erase(q.begin());
		if(vis[u])continue;
		vis[u]=1;
		for(auto ret:e[u]){
			ll v=ret.first,w=ret.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.insert({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1,a,t;j<=k[i];j++){
			cin>>a>>t;
			e[m+i].push_back({a,t});
			e[a].push_back({m+i,t});
		}
	}
	for(ll i=1;i<=n;i++){
		Dij(m+i);
		for(ll j=1;j<=n;j++)diss[i][j]=dis[m+j];
	}
	while(q--){
		cin>>x>>y;ans=1e18;
		for(auto retx:e[x]){
			for(auto rety:e[y]){
				ll rx=retx.first,ry=rety.first;
				ans=min(ans,diss[rx-m][ry-m]+retx.second+rety.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
