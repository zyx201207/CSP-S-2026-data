#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
bool flg[N];
int b[N];
int id[N], sum[N];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	int T = n;
	while (T--) {
		for (int i = 1; i <= n; i++) {
			flg[i] = 0;
		}
		for (int i = n - T; i <= n; i++) {
			if (!flg[a[i]]) {
				id[a[i]] = i;
				flg[a[i]] = 1;
			} else {
				for (int j = id[a[i]]; j <= i - 1; j++) {
					b[j] = 0;
					flg[a[j]] = 0;
					id[a[j]] = 0;
				}
				flg[a[i]] = 1;
				id[a[i]] = i;
			}
		}
		for (int i = n - T; i <= n; i++) {
			if (b[i] != 0) {
				sum[b[i]]++;
			}
			b[i] = a[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << sum[i] << " ";
	}
	return 0;
}

/*10 3
3 1 2 1 3 2 3 1 2 1
*/
