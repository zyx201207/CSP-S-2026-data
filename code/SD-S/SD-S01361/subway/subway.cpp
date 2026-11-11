#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define N 500010
using namespace std;
ll n,m,q,k,u,v,ans,w[N],d[510][510];
vector<pair<ll,ll>>vc[N];
int main(){
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k;
		for(ll j=1;j<=n;j++)d[i][j]=i^j?1e18:0;
		for(ll j=1;j<=k;j++)cin>>u>>v,vc[u].emplace_back(i,v);
	}
	for(ll i=1;i<=m;i++)for(auto j:vc[i])for(auto k:vc[i])d[j.fi][k.fi]=d[k.fi][j.fi]=min(d[j.fi][k.fi],j.se+k.se);
	for(ll k=1;k<=n;k++)for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	for(;q--;){
		cin>>u>>v,ans=1e18;
		for(auto i:vc[u])for(auto j:vc[v])ans=min(ans,d[i.fi][j.fi]+i.se+j.se+w[u]+w[v]);
		cout<<ans<<"\n";
	}
	return 0;
}
