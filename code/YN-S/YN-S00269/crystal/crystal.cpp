#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
ll n, m, ans, a[N], d;

int main() {
	freopen("crysal.in", "r", stdin);
	freopen("crysal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	d = a[2] - a[1];
	ans += min(n - 1, m / d);
	cout << ans + 1;
	return 0;
}
//30pts