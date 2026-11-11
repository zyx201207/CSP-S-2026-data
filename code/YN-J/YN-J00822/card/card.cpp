#include <bits/stdc++.h>
using namespace std;
stack<long long> q;
long long cnt[300010];
long long a[500010], c[300010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int j = 1; j <= n; j++) {

		for (int i = j; i <= n; i++) {

			q.push(a[i]);
			c[a[i]]++;
			cnt[a[i]]++;

			if (c[a[i]] == 2) {
				q.pop();
				c[a[i]]--;
				cnt[a[i]]--;

				while (q.top() != a[i]) {
					c[q.top()]--;
					cnt[q.top()]--;
					q.pop();
				}
			}
		}

		memset(c, 0, sizeof(c));
	}

	for (int i = 1; i <= m; i++) {

		cout << cnt[i] << " ";
	}

	return 0;
}