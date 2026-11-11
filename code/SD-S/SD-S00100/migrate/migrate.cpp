#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005],cnt;
vector<pair<ll,ll> > dp;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","r",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	dp.push_back(make_pair(1ll,0ll));
	while(t--){
		cin>>n>>d;
		for(ll i=1; i<=d; ++i) cin>>x[i];
		ll p=(*max_element(x+1,x+n+1))-(*min_element(x+1,x+n+1));
		dp.resize(p);
		for(ll i=cnt+1; i<=p; ++i){
			for(ll j=max(1ll,p-d); j<=p-1; ++j){
				dp[i].first+=dp[j].first;
				dp[i].second=dp[j].second+1;
			}
		}
		ll ans=0;
		for(ll i=1; i<=n; ++i){
			for(ll j=i+1; j<=n; ++j){
				ll dist=j-i,mdist=(((j-i)%d==0) ? ((j-i)%d) : ((j-i)%d+1)),cnt=0;
				for(ll k=max(1ll,dist-d); k<=dist-1; ++k) if(dp[k].second==mdist-1) cnt+=dp[k].first;
				if(cnt==2) ++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
