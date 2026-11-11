#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,j,k) for(int i=j;i<=k;i++)
const int N = 5e5 + 100;
int a[N], qzh[N];
int n, m;
signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	F(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	F(i, 1, n) {
		qzh[i] = qzh[i - 1] + a[i];
	}
	int hi = n;
	int lo = 0;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		bool ok = 0;
		F(l, 1, n) {
			int r = l + mid - 1;
			if (r > n)break;
			if ((a[r] * (r - l + 1) - (qzh[r] - qzh[l - 1])) <= m) {
				ok = 1;
			}
		}
		if (ok) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}