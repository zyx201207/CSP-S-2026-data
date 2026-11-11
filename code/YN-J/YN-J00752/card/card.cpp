#include <bits/stdc++.h>
using namespace std;
#define IOS std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], ans[M];

int findd(int x, int s[], int tot) {
	for (int i = 1; i <= tot ; i++) {
		if (s[i] == x)
			return i;
	}
	return -1;
}

signed main() {
	IOS
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int j = 1; j <= n; j++) {
		int s[M], tot = 0;
		for (int i = j; i <= n; i++) {
			int k = findd(a[i], s, tot);
			if (k == -1)
				s[++tot] = a[i];
			else {
				int flg = 0, tott = tot;
				for (int l = 1; l <= tott; l++) {
					if (flg == 1)
						tot--;
					if (s[l] == a[i])
						flg = 1;
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			ans[i] += (findd(i, s, tot) == -1) ? 0 : 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}

