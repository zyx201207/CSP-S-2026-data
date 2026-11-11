#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int a[N], last[M], ans[M];
int n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			if (last[a[i]]) {
				for (int j = last[a[i]]; j <= i; j++) {
					last[a[j]] = 0;
				}
			}
			last[a[i]] = i;
		}
		for (int i = 1; i <= m; i++) {
			if (last[i]) {
				ans[i]++;
			}
			last[i] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}