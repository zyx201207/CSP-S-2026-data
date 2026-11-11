#define ll long long

#include<bits/stdc++.h>
using namespace std;
const int mx = 5e5 + 10;
ll a[mx];
ll s[mx];
ll val(ll l,ll r){
	ll len = r - l;
	return len * a[r] - (s[r - 1] - s[l - 1]);
}
bool check(ll x,ll n,ll m){
	for(ll l = 1;l <= n - x + 1;l++){
		ll r = l + x - 1;
		if(val(l,r) <= m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++)scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++)s[i] = s[i - 1] + a[i];
	ll l = 1,r = n,mid;
	ll ans = 0;
	while(l <= r){
		mid = (l + r) / 2;
		if(check(mid,n,m)){
			l = mid + 1;
			ans = mid;
		}else{
			r = mid - 1;
		}
	}
	printf("%lld",ans);
	return 0;
}
