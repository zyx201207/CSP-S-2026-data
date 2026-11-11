#include <bits/stdc++.h>
using namespace std;
int a[500005], c[500005];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		vector <int> s, x;
		for (int j = i; j <= n; j++) {
			for (auto to : s) {
				if (to != a[j])
					x.push_back(to);
				else break;
			}
			s.clear();
			
			x.push_back(a[j]);
			for (auto to : x)
				s.push_back(to);
			x.clear();
		}
		for (auto to : s)
			c[to]++;
	}
	for (int i = 1; i <= m; i++)
		cout << c[i] << ' ';
	return 0;
}