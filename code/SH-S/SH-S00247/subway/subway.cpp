#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll dp[505][505];//dp[i][j]:从线路i到线路j的最短路，累死floyd
ll w[500005];
ll k[505];
vector<pair<ll,ll> > v[500005];//v[i]:通过i的地铁编号与时间 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(dp,0x3f,sizeof dp);
	for(ll i=1;i<=500;i++) dp[i][i]=0;
	ll n,m;
	ll c,d,q;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll a,t;cin>>a>>t;
			v[a].push_back({i,t});
		} 
	}
	for(ll i=1;i<=m;i++){
		for(auto j:v[i]){
			for(auto j2:v[i]){
				dp[j.first][j2.first]=dp[j2.first][j.first]=min(dp[j.first][j2.first],j.second+j2.second);
			}
		}
	}
	for(ll kk=1;kk<=n;kk++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][kk]+dp[kk][j]);
			}
		}
	}
	while(q--){
		ll a,b;
		cin>>a>>b;
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto i:v[a]){
			for(auto j:v[b]){
				ans=min(ans,dp[i.first][j.first]+i.second+j.second);
			}
		}
		ans=ans+w[a]+w[b];
		cout<<ans<<"\n";
	} 
	return 0;
} 
//时间复杂度：O((m+q)*d^2+n^3) 
