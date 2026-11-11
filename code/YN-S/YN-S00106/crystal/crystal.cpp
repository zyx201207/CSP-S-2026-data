#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e5 + 5;
ll n, m;
ll a[N];
ll sum[N];
ll ans1 = 0, ans2 = 0;

/*
true_ans = 315275
my_ans = 313324
m=19768503
*/

inline ll calc(int l, int r) {
	return 1ll * (r - l) * a[r] - sum[r - 1] + sum[l - 1];
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	ll l = 1;
	ll t;
	for (ll r = n; r >= 1; r--) {
		l = 1;
		t = calc(l, r);
		while (t > m) {
			l++;
			t = calc(l, r);
		}
//		cout << l << " " << r << " " << x << " l r y\n";
		ans1 = max(r - l + 1, ans1);
	}
	cout << ans1;
	return 0;
}
