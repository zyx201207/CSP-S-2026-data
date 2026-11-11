#include <bits/stdc++.h>

using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
int a[N], cnt[M], st[M];

void solve(int num) {
	memset(st, 0, sizeof st);
	vector<int> b;
	int id = 1e9;
	for (int k = num; k <= n; ++k) {
		if (b.size() == 0) {
			b.push_back(a[k]);
			continue;
		}
		for (int i = 0; i < b.size(); ++i) {
			if (b[i] == a[k]) {
				id = i;
				break;
			}
		}
		for (int i = id; i < b.size(); ++i) {
			b.pop_back();
		}
		b.push_back(a[k]);
	}
	for (auto i : b) {
		if (st[i]) {
			continue;
		} else {
			st[i] = 1;
			cnt[i]++;
		}
	}
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		solve(i);
	}
	for (int i = 1; i <= m; ++i) {
		cout << cnt[i] << " ";
	}
	return 0;
}

