#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;

int main() {
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	int n, m, a[N], sum[N];
	bool flag[M];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(flag, 0, sizeof flag);
		for (int j = i; j <= n; j++) {
			if (flag[a[j]] == false) {
				flag[a[j]] = true;
			} else {
				memset(flag, 0, sizeof flag);
				flag[a[j]] = true;
			}
		}
		for (int j = 1; j <= m; j++) {
			if (flag[j]) {
				sum[j]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << sum[i] << " ";
	}
	return 0;
}