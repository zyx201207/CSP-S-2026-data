#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
const ll inf = 1e18;
inline ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x*f;
}
int n;
ll a[N], b[N], m;
ll sum[N];
bool check(int x) {
	for (int i = 1; i <= n; i++) {
		ll tmp = 0;
		if (i + x - 1 > n)break;
		tmp = 1LL * x*a[i + x - 1];
		tmp -= (sum[i + x - 1] - sum[i - 1]);
//		for (int j = i + x - 1; j >= i; j--)
//			tmp += (a[i + x - 1] - a[j]);
		if (tmp <= m)return 1;
	}
	return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n;
	m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int l = 1, r = n, ans = 0;
	while (l <= r) {
//		cout << l << " " << r << endl;
		int mid = l + r >> 1;
		if (check(mid))ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}