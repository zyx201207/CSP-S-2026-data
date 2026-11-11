#include <bits/stdc++.h>
using namespace std;

int n, m;
struct bin {
	int t[64], cnt = 0;
	bool ch = 1;
	void change(int a) {
		int x = a;
		while (x > 0) {
			cnt++;
			t[cnt] = x % 2;
			x /= 2;
		}
	}
} k[200010];
bool ans[64], l[200010];



int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		k[i].change(p);
	}
	for (int i = 32; i >= 1; i--) {
		memset(l, 0, sizeof(l));
		int cnt1 = 0;
		for (int j = 1; j <= n; j++) {
			if (k[j].t[i] == 1 && k[j].ch == 1) {
				cnt1++;
				l[j] = 1;
			}
		}
		if (cnt1 > m) {
			for (int j = 1; j <= n; j++) {
				if (l[j] == 0)
					k[j].ch = 0;
			}
			ans[i] = 1;
		} else if (cnt1 == m) {
			for (int j = 1; j <= n; j++) {
				if (l[j] == 0)
					k[j].ch = 0;
			}
			ans[i] = 1;
		} else if (cnt1 < m) {
			ans[i] = 0;
		}
	}
	long long ans2 = 0, mul = 1;
	for (int i = 1; i <= 32; i++) {
		ans2 += ans[i] * mul;
		mul *= 2;
	}
	cout << ans2;
	return 0;
}