#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[500010];
int r[300010];
bool cnt[300010];
int b[500010];
int l;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i += 1) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i += 1) {
		memset(cnt, 0, sizeof(cnt));
		l = 0;
		for (int j = i; j <= n; j += 1) {
			if (cnt[a[j]] == 0) {
				cnt[a[j]] = 1;
				l += 1;
				b[l] = a[j];
			} else {
				while (b[l] != a[j]) {
					cnt[b[l]] = 0;
					b[l] = 0;
					l -= 1;
				}
			}
		}
		for (int j = 1; j <= l; j += 1) {
			r[b[j]] += 1;
		}
	}
	for (int i = 1; i <= m; i += 1) {
		cout << r[i];
		cout << " ";
	}
	return 0;
}