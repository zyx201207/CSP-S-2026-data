#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N], sum[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	string s, s1, s2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int xb = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = a[i - 1] + sum[i - 1];
	}
	int maxx = LLONG_MIN;
	int l = 1;
	for (int r = 1; r <= n; r++) {
		int qjh = sum[r + 1] - sum[l];
		int cd = r - l + 1;
		int xy = a[r] * cd - qjh;
		if (xy > m) {
			cd--;
			maxx = max(maxx, cd);
			while (xy >= m && cd > 0) {
				l++;
				cd--;
				qjh = sum[r + 1] - sum[l];
				xy = a[r] * cd - qjh;
			}
		}
	}
	if (maxx == LLONG_MIN) {
		cout << n;
		return 0;
	}
	cout << maxx;
	return 0;
}