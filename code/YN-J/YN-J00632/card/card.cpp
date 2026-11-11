#include <bits/stdc++.h>
using namespace std;

int n, m, a[500050], ans[300050], sc[300050];
stack<int>q;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (ans[a[j]] == 0) {
				q.push(a[j]);
				ans[a[j]]++;
			} else {
				while (q.top() != a[j]) {
					ans[q.top()]--;
					q.pop();
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			sc[i] += ans[i];
			ans[i] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << sc[i] << " ";
	}
	return 0;
}