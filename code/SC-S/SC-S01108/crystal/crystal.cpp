#include<bits/stdc++.h>
#define ll long long
#define ls(i) i<<1
#define rs(i) i<<1|1

using namespace std;
const int N = 5e5+5;

ll n, m;
ll a[N], pre[N], dp[N], diff[N];
ll ans, minn = 1e18, minw;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		a[i] -= a[1];
	}
	a[1] = 0;
	a[0] = -1e12;
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
		diff[i] = a[i] - a[i - 1];
		if (diff[i] < minn && i > 1) {
			minn = diff[i];
			minw = i - 1;
		}
	}
	if (m < minn) {
		cout << 1;
	} else {
		if (n <= 5000 ) {
			ans = 2;
			for (int i = 1; i < n; i++) {
				ll nail = i, head = i + 1;
				ll sum = diff[i + 1], len = 2;
				while (head <= n && nail > 0 && sum <= m) {
					ll c1 = len * diff[head + 1];
					ll c2 = a[head] - a[nail - 1];
					if (c1 < c2) {
						head++;
						sum += c1;
						len++;
					} else {
						sum += c2;
						nail--;
						len++;
					}
				}
				if (sum > m) len--;
				ans = max(ans, len);
			}
			cout << ans;
		} else {
			ll nail = minw, head = minw + 1;
			ll sum = minn, len = 2;
			while (head <= n && nail > 0 && sum < m) {
				ll c1 = len * diff[head + 1];
				ll c2 = a[head] - a[nail - 1];
				if (c1 < c2) {
					head++;
					sum += c1;
					len++;
				} else {
					sum += c2;
					nail--;
					len++;
				}
				if (sum > m) len--;
			}
			cout << len;
		}
	}
	return 0;
}