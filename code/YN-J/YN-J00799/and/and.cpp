#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
vector<int>v;

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		maxx = max(maxx, x);
	}
	if (m == 1) {
		cout << maxx;
		return 0;
	}
	if (m == 2) {
		int sc = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sc = max(sc, v[i] & v[j]);
			}
		}
		cout << sc;
		return 0;
	}
	int sc = 0;
	do {
		int now = v[0];
		for (int i = 1; i < m; i++)
			now &= v[i];
		sc = max(sc, now);
	} while (next_permutation(v.begin(), v.end()));
	cout << sc;
	return 0;
}