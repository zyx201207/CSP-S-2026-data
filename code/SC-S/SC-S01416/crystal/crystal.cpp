#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, maxx = 0;
ll m, a[500005];
ll sum[500005];
ll mp[10005];
int main() {
//	freopen("C:\\Users\\user\\Downloads\\csps\\down\\crystal\\crystal4.in", "r", stdin);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	bool b1 = true;
	ll maxxx = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] >= -100) mp[a[i] + 100]++;
		maxxx = max(maxxx, abs(a[i]));
	}
	sort (a + 1, a + n + 1);
	ll d = a[2] - a[1];
	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			if (a[i] != a[i - 1] + d) b1 = false;
		}
		sum[i] = sum[i - 1] + a[i];
	}
	if (maxxx <= 100) {
		vector<int> b(a + 1, a + n + 1);

		b.erase (unique(b.begin(), b.end()), b.end()); 
		for (ll val : b) {
			int i = lower_bound (a + 1, a + n + 1, val) - a;
			for (int l = 1; l <= i; l++) {
				if ((i - l) * a[i] - (sum[i - 1] - sum[l - 1]) <= m) {
					maxx = max(maxx, i - l + 1 + mp[val + 100] - 1);
				}
			}
		}
		cout << maxx;
		return 0;
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			for (int l = 1; l <= i; l++) {
				if ((i - l) * a[i] - (sum[i - 1] - sum[l - 1]) <= m) {
					maxx = max(maxx, i - l + 1ll);
				}
			}
		}
		cout << maxx;
		return 0;
	}
	if (b1) {
		for (int i = 1; i <= n; i++) {
			if ((d + (i - 1) * d) * (i - 1) / 2 <= m) {
				maxx = max(maxx, i * 1ll);
			}
		}
		cout << maxx << '\n';
		return 0;
	}
	return 0;
} 