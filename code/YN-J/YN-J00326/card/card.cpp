#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], lst[M], b[M];
bool vis[M];
bool fA = 0;
int cnt[M];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i + 1])
			fA = 1;
	}
	if (!fA) {
		for (int i = 1; i <= n; i++) {
			cnt[a[i]] = max(cnt[a[i]], i);
		}
		int sum = 0;
		for (int i = 1; i <= m; i++) {
			cout << cnt[i] << " ";
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int tot = 0;
		for (int j = 1; j <= m; j++)
			lst[j] = 0;
		for (int j = i; j <= n; j++) {
			if (!lst[a[j]]) {
				lst[a[j]] = ++tot;
			} else {
				for (int k = j - 1; k >= lst[a[j]] + 1; k--) {
					if (lst[a[k]] >= lst[a[j]] + 1)
						lst[a[k]] = 0;
					//	lst[a[k]] = 0;
				}
				tot = lst[a[j]] + 1;
			}
		}
		for (int j = 1; j <= m; j++) {
			if (lst[j])
				b[j]++;
			//	cout << lst[j] << " ";
		}
		//	cout << "\n";
	}
	for (int i = 1; i <= m; i++)
		cout << b[i] << " ";
	return 0;
}