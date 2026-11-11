#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
const int INT_INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;


ll n,m;
ll a[500005];

bool check(ll len) {
	ll temp_m;
	
	for (ll i = 0;i < n;i++) {
		temp_m = m;
		if (i + len > n - 1) continue;
		for (ll j = i;j <= i + len;j++) {
			temp_m -= a[i + len] - a[j];
		}
		
		if (temp_m >= 0) {
			return true;
		}
	}
	return false;
}

int main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	bool is_sorted = true;
	for (ll i = 0;i < n;i++) {
		cin >> a[i];
		if (i != 0 && a[i] < a[i - 1]) is_sorted = false;
	}
	
	if (!is_sorted) sort(a,a + n);
	ll l = 1,r = n,mid;
	ll ans = 0;
	
	while (l <= r) {
		mid = (l + r) >> 1;
		
		if (check(mid - 1)) {
			l  = mid + 1;
			ans = max(ans,mid);
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	
	return 0;
}
