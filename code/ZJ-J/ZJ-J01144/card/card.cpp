#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], cnt[N];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool f = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < a[i - 1]) f = 0;
	}
	if (m <= 2) {
		if (m == 1) {
			cout << n;
			return 0;
		}
		cnt[a[n]] = n;
		for (int i = 1; i <= n; ++i) {
			if (a[i] == a[n]) continue;
			cnt[a[i]]++;
		}
		cout << cnt[1] << ' ' << cnt[2];
		return 0;
	}
	if (f) {
		for (int i = 1; i <= n; ++i) {
			cnt[a[i]] = max(cnt[a[i]], n - i + 1);
		}
		for (int i = 1; i <= m; ++i) {
			cout << cnt[i] << ' ';
		}
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		vector<int> v;
		for (int j = i; j <= n; ++j) {
			v.push_back(a[j]);
		}
		vector<int> v1;
		for (int j = 0; j < v.size(); ++j) {
			if (v1.empty()) {
				v1.push_back(v[j]);
			}
			else {
				int id = -1;
				for (int k = 0; k < v1.size(); ++k) {
					if (v1[k] == v[j]) {
						id = k; break;
					}
				}
				if (id != -1) {
					for (int k = 1; k <= v1.size() - id + 1; ++k) {
						v1.pop_back();
					}
				}
				v1.push_back(v[j]);
			}
		}
		set<int> t;
		for (int j = 0; j < v1.size(); ++j) {
			t.insert(v1[j]);
		}
		for (int i : t) {
			cnt[i]++;
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << cnt[i] << ' ';
	}
	return 0;
}