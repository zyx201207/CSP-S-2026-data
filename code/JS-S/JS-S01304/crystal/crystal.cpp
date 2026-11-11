// so, AC?
// upd 13:42

// i no fen shu no gua fen!

#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long a[N], s[N], n, m;
bool check(int v)
{
	for (int i = v; i <= n; i++)
	{
		long long sum = s[i] - s[i - v];
		long long x = v * a[i];
		if (x - sum <= m) return true;
    }
    return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	int L = 1, R = n, ans = 1;
	while (L <= R)
	{
		int mid = (L + R) / 2;
		if (check(mid)) L = mid + 1, ans = mid;
		else R = mid - 1;
	}
	cout << ans << endl;
	return 0;
}
