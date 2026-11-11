#include <bits/stdc++.h>
#define ll long long
#define rep(i, j, k) for(int i=j;i<=k;i++)
#define Suika 0
using namespace std;
const int N = 5e5 + 10;
int n;
ll m, a[N], pre[N];
int ans;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(Suika);
	cin.tie(Suika);cout.tie(Suika);
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
	rep(i, 1, n) {
		int l = 1, r = i, k = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (1ll * (i - mid) * a[i] - (pre[i - 1] - pre[mid - 1]) <= m) r = mid - 1, k = mid;
			else l = mid + 1;
		}
		if (k > 0) ans = max(ans, i - k + 1);
	}
	cout << ans;
	return Suika;
}
/*
5 8
-3 -1 2 2 7
5 5
2 1 2 4 8 9
*/