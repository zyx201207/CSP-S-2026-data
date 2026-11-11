#include <bits/stdc++.h>
using namespace std;
int maxn = -1, a[10000005], n, m;

int main() {
	freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	cin >> n >> m;
	stack<int> q;
	for (int i = 1; i = n; i++) {
		cin >> a[i];
		q.push(a[i]);
	}
	while (m--) {
		int t = q.top();
		q.pop();
		for (int i = 1; i <= n; i++) {
			q.push(a[i]&t);
		}
	}
	while (!q.empty()) {
		maxn = max(maxn, q.top());
		q.pop();
	}
	cout << maxn;
	return 0;
}
