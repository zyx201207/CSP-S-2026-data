#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, m, arr[100005], maxf = 1, maxn, brr[100005];
bool b;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	ll tmp = arr[2] - arr[1], ans = 3;
	brr[2] = 1, brr[3] = 3;
	for (int i = 4; i <= n; i++) {
		if (arr[i] - arr[i - 1] != tmp) {
			b = 1;
			break;
		}
		ans += i - 1, brr[i] = ans;
	}
	if (b == 0) {
		ll tot = 0;
		for (int i = 1; i <= n; i++)
			if (tmp * brr[i] <= m)
				tot++;
		cout << tot;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (n - i + 1 <= maxf)
			break;
		maxn = 1;
		ll x = m, y = arr[i], z = 1;
		for (int j = i + 1; j <= n; j++) {
			ll p = arr[j] * z - y;
			if (p <= x)
				maxn++, z++, y = arr[j] * z, x -= p;
			else
				break;
		}
		maxf = max(maxf, maxn);
	}
	cout << maxf;
	return 0;
}
