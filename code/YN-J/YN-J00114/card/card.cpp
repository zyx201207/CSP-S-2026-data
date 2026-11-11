#include <bits/stdc++.h>
using namespace std;
int n, m, c[10000], a[10000], ans[10000];
stack<int>t;

void era() {
	while (!t.empty()) {
		t.pop();
	}
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> c[i];
	}

	for (int i = 1; i <= n; i++) {

		for (int j = i; j <= n; j++) {

			if (a[c[j]] == 0) {
				t.push(c[j]);
				a[c[j]] = 1;
			} else {
				while (t.top() != c[j]) {
					a[t.top()] = 0;
					t.pop();
				}

				t.pop();
				t.push(c[j]);
				a[c[j]] = 1;
			}
		}

		for (int j = 1; j <= m; j++) {

			ans[i] += a[i];
		}

		era();
		memset(a, 0, sizeof(a));

	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}

