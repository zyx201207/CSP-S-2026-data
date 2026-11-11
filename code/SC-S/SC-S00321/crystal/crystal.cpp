#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll n , m , ans = 0;
ll ch(ll x) {
	ll cnt = 0;
	for(int i = 1 ; i < x ; i++) {
		cnt += a[x] - a[i];
	}
	if(cnt > m) {
		return -1;
	} else {
		return 1;
	}
}
int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	ll l = 1 , r = n , mid = (l + r) / 2;
	while(l <= r) {
		mid = (l + r) / 2;
		if(ch(mid) == 1) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
} 