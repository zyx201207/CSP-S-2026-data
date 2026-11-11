#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,ll> 
using namespace std;
const ll N=6e5+10;
ll c,t,n,d,x[N],cnt[N],dis[N],ans;
bool vis[N];
vector<ll>e[N];
void Dij(ll s){
	for(ll i=1;i<=n;i++)vis[i]=cnt[i]=0,dis[i]=1e18;
	multiset<PII>q;
	dis[s]=0;
	q.insert({0ll,s});
	while(q.size()){
		ll u=(q.begin())->second;
		q.erase(q.begin());
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:e[u]){
			if(vis[v])continue;
			if(dis[u]+1==dis[v]){
				//cout<<u<<"  "<<v<<"\n";
				cnt[v]++;
			}
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.insert({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(ll i=1;i<=n;i++)cin>>x[i];
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==j||abs(x[i]-x[j])>d)continue;
				e[i].push_back(j);
			}
		}
		for(ll i=1;i<=n;i++){
			Dij(i);
			for(ll j=i+1;j<=n;j++){
				//cout<<i<<' '<<j<<' '<<cnt[j]<<"\n";
				ans+=(bool)(cnt[j]==1&&dis[j]!=1);
			}
			e[i].clear();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
