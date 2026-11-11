#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll int a[N], m, n;

namespace subtask1 {
	void solve() {
		ll int sum = 0, cnt = 1;
		for (int i = 1; i <= n; i++) {
			sum += i;
			if (sum <= m) {
				cnt++;
			}
		}
		cout << cnt;
	}
}

namespace subtask2 {
	void solve() {
		ll int sum = 0, cnt = 1, x = a[2] - a[1];
		for (int i = 1; i <= n; i++) {
			sum += x * i;
			if (sum <= m) {
				cnt++;
			}
		}
		cout << cnt;
	}
}

namespace subtask3 {
	void solve() {
		ll int sum = 0, cnt = 1, maxx = 0;
		int l = 1, r = 1;
		while (r <= n) {
			cout << maxx << ' ' << cnt << " ";
			if (sum <= m) {
				maxx = max(cnt, maxx);
				r++;
				sum += (a[r] - a[r - 1]) * cnt;
				cnt++;
			} else {
				sum -= a[r - 1] - a[l];
				l++;
				cnt--;
			}
		}
		cout << maxx;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int f1 = 1, f2 = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			f1 = 0;
		}
		if (i > 1 && i < n) {
			if (a[i] - a[i - 1] != a[i + 1] - a[i]) {
				f2 = 0;
			}
		}
	}
	if (f1) {
		subtask1::solve();
	} else if (f2) {
		subtask2::solve();
	} else {
		subtask3::solve();
	}
	return 0;
}