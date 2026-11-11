#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m;
int a[1000000 + 1];
int cnt[1000000 + 1];
int ins[1000000 + 1];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int sum = n;
		for (int j = i; j <= n; j++) {
			bool flag = 0;
			for (int s = 1; s <= sum; s++) {
				ins[s] = a[s];
				if (a[s] == a[i]) {
					flag = 1;
					sum = s;
					break;
				}
				if (flag == 0) {
					sum++;
					ins[sum] = a[j];
				}
			}
			if (j == n) {
				for (int g = 1; g <= sum; g++) {
					cnt[ins[g]]++;
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	return 0;
}