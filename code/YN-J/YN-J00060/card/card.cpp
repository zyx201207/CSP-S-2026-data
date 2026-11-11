#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500005];
long long t[300005];
bool vis[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (long long i = 1; i <= n; i++) {

		stack<long long>q;

		for (long long j = i; j <= n; j++) {

			if (!vis[a[j]]) {
				q.push(a[j]);
				vis[a[j]] = true;
			} else {
				while (!q.empty()) {
					if (q.top() == a[j]) {
						break;
					}

					vis[q.top()] = false;
					q.pop();

				}
			}
		}

		while (!q.empty()) {
			t[q.top()]++;
			vis[q.top()] = false;
			q.pop();
		}
	}

	for (long long i = 1; i <= m; i++) {

		cout << t[i] << " ";
	}

	return 0;
}