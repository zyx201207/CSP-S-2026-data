#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 214514;
ll n, m, ans;
ll a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (m == 1)
		ans = a[n];
	else if (m == 2)
		ans = (a[n] & a[n - 1]);
	cout << ans;
	return 0;
}