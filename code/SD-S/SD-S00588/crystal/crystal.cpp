#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using db = double;

const int MAXN = 5e5 + 5;

ll a[MAXN];
ll sum[MAXN];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];	
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = i;
		while (l < r) {
			int mid = (l + r) / 2;
			if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans << '\n';
}
