#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll a[N],dp[N];
ll n,m;

int check(int x){
	ll cnt = 0;
	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		if(x >= a[i] && ans <= m - (a[i] - x)){
			ans += a[i] - x;
			cnt++;
		}
	}
	return cnt;
}

ll low(ll l,ll r){
	ll ans = 0;
	ll mid = (l+r)/2;
	while(l <= r){
		mid = (l+r)/2;
		if(check(mid) >= ans){
			ans = check(mid);
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	return ans;
}
bool cmp(ll a,ll b){
	return a > b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	ll minn = 1e18,maxx = 0;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
		minn = min(minn,a[i]);
		maxx = max(maxx,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	ll ans = low(minn,maxx);
	cout << ans;
	return 0;
}
