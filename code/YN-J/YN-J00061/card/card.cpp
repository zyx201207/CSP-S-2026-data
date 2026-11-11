#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N = 5 * 1e5 + 10;
int n, m, a[N];
queue<int> q, p;
set<int> c;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		q.push(a[i]);
		c.insert(q.front());
	}
	while (!q.empty()) {
		int b = q.front();
		if (c.find(b) != c.end()) {
			p.push(b);
		} else {
			while (!p.empty() && p.front() != b) {
				p.pop();
			}
			c.clear();
		}
		q.pop();
	}
	return 0;
}