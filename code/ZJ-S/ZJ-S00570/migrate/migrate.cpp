#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e3+10;
ll n,d;
ll a[N];
pair<ll,ll> f[N];
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)f[j]={0,0};
		f[i]={0,1};
		for(ll j=i+1;j<=n;j++){
			ll mn=INT_MAX;
			for(ll k=j-1;k>=i;k--){
				if(a[j]-a[k]<=d){
					mn=min(mn,f[k].first);
				}
				else break;
			}
			for(ll k=j-1;k>=i;k--){
				if(a[j]-a[k]<=d&&f[k].first==mn){
					f[j].second+=f[k].second;
				}
			}
			f[j].first=mn+1;
			if(f[j].second==2)ans++;
		}
	}
//	for(ll i=1;i<=n;i++){
//		cout<<f[i].first<<" ";
//	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
