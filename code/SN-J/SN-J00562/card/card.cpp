#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n, m, i, last, a[N], cnt[N];
signed main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= n; j++) {
		if (last >= a[j]) {
			cout << cnt[i] << ' ';
			i++;
		} else {
			last = a[j];
			if (last == i) cnt[i]++;
		}
	}
	return 0;
}
