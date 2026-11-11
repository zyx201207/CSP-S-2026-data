#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], ans[N];
stack < int> t;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		t.push(a[i]);

		for (int j = i + 1; j <= n; j++) {

			if (a[j] == a[j - 1]) {
				t.pop();
			}

			t.push(a[j]);
		}

		while (!t.empty()) {
			ans[t.top()]++;
			t.pop();
		}

	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << ' ';
	}

	return 0;
}