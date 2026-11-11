#include<bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
using namespace std;
int n, ans;
long long a[500010], sum[500010], m;
bool possible(int l, int r) {
	if ((a[r] * (long long)(r - l + 1) - (sum[r] - sum[l - 1])) <= m) return true;
	return false;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	rep (i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	rep (i, 1, n) {
		sum[i] = sum[i - 1] + a[i];
	}
	int l = 1, r = 1;
	while (r <= n) {
		while (!possible(l, r)) l++;
		ans = max(ans, r - l + 1);
		r++;
	}
	cout << ans << "\n";
}