#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int pos[N];
int ans[N], col[N];
int n, m;
int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;

	int flag = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i - 1] > a[i]) {
			flag = 0;
		}
	}
	if (flag) {
		for (int i = 1; i <= m; i++) {
			cout << i << ' ';
		}
		return 0;
	}

	for (int i = n; i >= 1; i--) {
		pos[i] = col[a[i]];
		col[a[i]] = i;
	}
//	for (int i = 1; i <= n; i++) {
//		cout << pos[i] << ' ';
//	}
	for (int i = 1; i <= n; i++) {
		int k = i;
		while (k <= n) {
			for (int j = k; j <= n; j++) {
				if (pos[j] > j) {
					k = j;
					break;
				}
				ans[a[j]]++;
				//cout << 1;
			}
			if (pos[k] == 0) {
				break;
			}
			k = pos[k];
		}

	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}


	return 0;
}