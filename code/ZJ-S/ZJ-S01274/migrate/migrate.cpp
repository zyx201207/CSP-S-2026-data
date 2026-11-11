#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2000010;
ll c,t;
void dfs(ll x,ll y,vector<ll> v[],ll cnt);
void solve(){
	ll n,d;cin>>n>>d;
	ll a[N];
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	vector<ll>v[N];
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(j-i>d)break;
			v[i].push_back(j);
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<n;j++){
			ll cnt=0;
			dfs(i,j,v,cnt);
			if(cnt==2)ans++;
		}
	}
	cout<<ans<<endl;
}
void dfs(ll x,ll y,vector<ll> v[],ll cnt){
	for(ll i=x;i<=y;i++){
		for(ll j:v[i]){
			if(j==y){
				cnt++;
				return;
			}
			dfs(j,y,v,cnt);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}