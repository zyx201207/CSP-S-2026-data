#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, m, a[N], ans = 0;
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a+1, a+1+n);
	for (int i = 1; i <= n; i++) {
		long long cnt = 1, cur = m;
		for (int j = i-1; j >= 1; j--) {
			if (cur < a[i]-a[j]) break;
			else {
				cnt ++;
				cur -= a[i]-a[j];
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
