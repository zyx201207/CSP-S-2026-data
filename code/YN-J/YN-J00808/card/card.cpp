#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], c[500005];
queue<int> q;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			q.push(a[i]);
			c[i] = 1;
		} else {
			q.pop();
			c[i] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << '1';
	}
	return 0;
}