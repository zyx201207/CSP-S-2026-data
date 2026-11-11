#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll a[N];
ll n,d;
ll cnt;
void dfs1(ll x,ll y,ll s){
	if (x>y) return ;
	if (s>=cnt) return ;
	if (x==y) cnt=min(cnt,s);
	for (ll q=y-x;q>=1;q--){
		if (a[x+q]-a[x]<=d) dfs1(x+q,y,s+1);
	}
	return ;
}
ll cntt=0;
void dfs2(ll x,ll y,ll s){
	if (x>y) return ;
	if (cntt>=3) return ;
	if (x==y && s==cnt) cntt++;
	if (s>cnt) return ;
	for (ll q=1;q<=y-x;q++){
		if (a[x+q]-a[x]<=d) dfs2(x+q,y,s+1);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while (t--){
		cin>>n>>d;
		for (ll i=1;i<=n;i++) cin>>a[i];
		ll ans=0;
		for (ll i=1;i<=n;i++){
			for (ll j=i+1;j<=n;j++){
				cnt=n-j;
				dfs1(i,j,0);
				cntt=0;
				dfs2(i,j,0);
				if (cntt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
