#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
ll m;
ll a[500005];

ll d[500005];
ll need[500005];

//改良特殊性质AB
int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	int t = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		d[t] = a[i] - a[i - 1];
		t++;
	}
	t--;

//	for (int i = 1; i <= t; i++) {
//		cout << d[i] << " ";
//	}
//	cout << endl;

	ll cnt = 0;
	ll k = 1;
	for (int i = 1; i <= t; i++) {
		cnt += d[i] * k;
		k++;
		need[i] = cnt;
	}

//	for (int i = 1; i <= t; i++) {
//		cout << need[i] << " ";
//	}
//	cout << endl;

	ll ans = 0;
	for (int i = 1; i <= t; i++) {
		if (m >= need[i] && (m < need[i + 1] || i == t)) {
			ans = i + 1;
		}
	}

	//特殊性质AB
//	ll d = a[2] - a[1];
//	ll pos = m / d;
//
//	ll t = 0;
//	ll step = 1;
//	ll ans = 0;
//	while (t <= pos) {
//		t += step;
//		step++;
//		ans++;
//	}
//	ans--;

	cout << ans << "\n";

	return 0;
}

//4 21
//1 4 7 10