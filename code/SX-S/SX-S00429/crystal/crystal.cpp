#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500500];
ll n, m, sum = 0, bs = 0, t = 0;

int main() {

	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll d = a[2] - a[1];
	bool flag = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] + d != a[i + 1])
			flag = 0;
	}
	if (flag) {
		sum = 1;
		for (int i = 2; i <= n; ++i) {
			bs += d * (i - 1);
			if (bs <= m)
				sum++;
			else
				break;
		}
		cout << sum << endl;
		return 0;
	}
	ll ans = n;
	for (int i = n - 1; i >= 1; i--) {	//反跑，找到最大极限
		bs += a[n] - a[i];
		if (bs <= m)
			ans--;
		else
			break;
	}
	for (int i = 1; i <= ans; ++i) {		//正跑
		sum = 1;
		bs = 0;
		for (int j = i; j <= n; ++j) {
			bs += (a[j + 1] - a[j]) * (j - i + 1);
			if (bs <= m)
				sum++;
			else
				break;
		}
		t = max(t, sum);
	}
	cout << t << endl;
	return 0;
}