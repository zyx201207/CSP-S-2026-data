#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[21000], cnt[21000];
stack<int> q;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		int p[21000] = {0};

		for (int j = i; j <= n; j++) {

			if (p[a[j]]) {
				while (q.top() != a[j]) {
					q.pop();
				}

			} else {
				q.push(a[j]);
				p[a[j]] = 1;
			}
		}

		while (!q.empty()) {
			cnt[q.top()]++;
			q.pop();
		}
	}

	for (int i = 1; i <= m; i++) {

		cout << cnt[i] << ' ';
	}

	return 0;
}