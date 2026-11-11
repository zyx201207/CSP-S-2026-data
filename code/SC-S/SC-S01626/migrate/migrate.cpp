#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
ll c,t,n,d,a[N],Min;
map<ll,ll>mp;
bool check(ll l,ll r){
	for(ll i=l;i<r;i++){
		if(a[i+1]-a[i]>d)return false;
	}
	return true;
}
void dfs(ll u,ll v,ll cnt){
	if(u==v){
		Min=min(cnt,Min);
		mp[cnt]++;
		return;
	}
	ll dd=u+1;
	while(a[dd]-a[u]<=d&&dd<=v){
		dfs(dd,v,cnt+1);
		dd++;
	}
	return;
}
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		ll ans=0;
		for(int i=1;i<=n-3;i++){
			for(ll j=i+3;j<=n;j++){
				if(check(i,j)){
					Min=1e18;
					mp.clear();
					dfs(i,j,0);
					if(mp[Min]==2)ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}