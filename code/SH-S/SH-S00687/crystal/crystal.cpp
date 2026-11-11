#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
typedef long long ll;
ll a[N],cf[N];
bool cmp(ll x, ll y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for (ll i = 1; i <= n; i++)
	cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for (ll i = 2; i <= n; i++){
		cf[i]=cf[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	ll l=1,r=2;
	ll ans = 0;
	while(l<=n&&r<=n){
		ll x = cf[r]-cf[l-1];
		if (x<=m){
			ans=max(ans,r-l+1);
			r++;
		} else {
			l++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
