#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
const ll inf = 1e11;

ll a[N];
ll n, m;

bool check(int x){
	int cnt = 0;
	for (int i = 0; i < x; ++i){
		cnt += a[x - 1] - a[i];
	}
	return cnt <= m;
}

int main(){
	freopen("crystal.in","r",stdin);
	cin >> n >> m;
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll l = 1, r = n;
	ll ans = 1;
	while (l < r) {
		ll mid = l + r >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	cout << ans << "\n";
	freopen("crystal.out","w",stdout);
	return 0;
} 