#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500005;
ll n, m;
ll a[MAXN];
ll ans = 0;
bool check (ll mid) {
	ll cnt = 0;
	for (int i = 1; i <= mid; i++) {
		cnt += a[mid] - a[i];
	}
	if (cnt <= m) {
		return true;
	}
	else {
		return false;
	}
}
void solve () {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			flag = true;
			break;
		}
	}
	
	if (!flag) {
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			a[i]--;
		}
		for (int i = 1; i <= n; i++) {
			if (ans + a[i] <= m) {
				ans += a[i];
				cnt++;
			}
			else {
				break;
			}
		}
		cout << cnt << "\n";
		return;
	}
	ll l = 1;
	ll r = n;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check (mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve ();
	return 0;
}
 
