#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<int> a(n);
	vector<int> t(m, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		vector<int> d(n - i);
		vector<int> s(m, 0);
		for (int j = i; j < n; j++) {
			d[j] = a[j];
			s[a[j]]++;
		}
		int r = 0;
		for (int j = 1; j <= m; j++) {
			if (s[j] >= 2) {
				for (int k = d.size() - 1; k >= 0; k--) {
					if (d[k] == j) {
						r = max(r, k);
						break;
					}
				}
			}
		}
		if (r != 0)
			r--;
		for (int j = 0; j < m; j++) {
			for (int k = r; k < d.size(); k++) {
				if (d[k] == j + 1 ) {
					t[j]++;
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
		cout << 1 << ' ';
	return 0;
}