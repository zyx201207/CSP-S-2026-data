#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
int a[500005], cnt[500005], dp[500005];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
//	cout << n << " " << m;
	fr(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int mm = 0, ans = 1;
//	fr(i, 1, n) {
//		cout << a[i] << " ";
//	}
//
//	cout << "\n";
	fr(i, 2, n) {
		mm += (a[i] - a[i - 1]) * (i - 1);
//		cout << mm << " ";
		if (mm > m) {
			break;
		}
		ans++;
	}
	cout << ans;
	return 0;
}
