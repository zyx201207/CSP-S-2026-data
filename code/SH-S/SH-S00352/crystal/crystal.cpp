#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[500100];
ll h[500100];

bool check(ll mid){
	ll minn = LONG_LONG_MAX;
	for (ll i = mid; i <= n; i++){
		minn = min(minn, mid * a[i] - (h[i] - h[i - mid]));
	}
	if (minn <= m) return 1;
	else return 0;
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++){
		h[i] = h[i - 1] + a[i];
	}
	
	ll l = 1, r = n;
	ll ans;
	while (l <= r){
		ll mid = l + (r - l) / 2;
		if (check(mid)){
			ans = mid;
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	
	return 0;
} 
