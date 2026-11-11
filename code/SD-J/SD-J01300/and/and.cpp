#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll ans=0;
ll a[200010];
inline bool check(ll x){
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		if((a[i]&x)==x) cnt++;
	}
	return cnt>=m;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=30;i>=0;i--){
		if(check(ans|(1<<i))) ans|=(1<<i);
	}
	cout<<ans;
	return 0;
}
