#include <bits/stdc++.h>
#define N 500001
using namespace std;
int n, m, a[N], ans[N], b[N], top, v[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		memset(v, 0, sizeof(v));
		memset(b, 0, sizeof(b));
		top = 0;

		for (int j = i; j <= n; j++) {

			if (v[a[j]] == 1) {
				while (b[top] != a[j]) {
					v[b[top]] = 0;
					top--;
				}

				top--;
			}

			b[++top] = a[j];
			v[a[j]] = 1;
		}

		for (int i = 1; i <= m; i++) {

			if (v[i] == 1) {
				ans[i]++;
			}
		}

	}

	for (int i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}