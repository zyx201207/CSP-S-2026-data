#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n, m, a[N], c[N], sum[N];

//ll s1[N], s2[N], ans = 0
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; i++)
		c[i] = a[i + 1] - a[i];
	sum[0] = 0ll;
//	s1[0] = 0ll, s2[0] = 0ll;
//	for (int i = 1; i < n; i++)
//		s1[i] = s1[i - 1] + c[i];
//	for (int i = 1; i < n; i++)
//		s2[i] = s2[i - 1] + s1[i];
	for (int i = 1; i < n; i++)
		sum[i] = sum[i - 1] + c[i] * i;
//	ll l = 1, r;
	for (int i = 1; i < n; i++)
		if (sum[i] > m) {
			while (c[i] == 0 && i < n)
				i++;
			cout << i;
			return 0;
		}
//		if (sum[i] <= m) {
//			while (c[i] == 0 && i < n)
//				i++;
//			r = i;
//		} else {
//			while (c[i] == 0 && i < n)
//				i++;
//			ans = i;
//			cout << i;
//			break;
//			return 0;
//		}
//	while (l < r && r < n) {
//		l++;
//		while (sum[r] - l * s1[l] + s2[l - 1] <= m)
//			r++;
//		ll k = r;
//		while (c[k] == 0 && k < n)
//			k++;
//		ans = max(ans, k);
//	}
//	cout << ans;
	cout << n;
	return 0;
}