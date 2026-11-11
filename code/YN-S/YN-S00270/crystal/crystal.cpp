#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N = 5e5 + 50;

ll a[N], sum, mid, mi = INT_MAX, idx, ans;
bool flag = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != i)
			flag = 0;
		sum += a[i];
	}
	if (flag) {
		for (int i = n; i >= 1; i--) {
			ll d = a[n] - a[i];
			if (m >= d) {
				m -= d;
				a[i] += d;
				ans++;
			}
		}
		cout << ans;
		return 0;
	}
	mid = sum / n;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		ll d = abs(a[i] - mid);
		if (d < mi) {
			mi = d;
			idx = i;
		}
	}
	mid = a[idx];
	for (int i = 1; i <= n; i++) {
		ll d = abs(mid - a[i]);
		if (m >= d) {
			m -= d;
			a[i] = mid;
			ans++;
		}
	}
	cout << ans;
//	cout << ' ' << idx << ' ' << mid << ' ' << mi;

	return 0;
}
