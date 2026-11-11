#include <bits/stdc++.h>
using namespace std;
long long a[500001]; 
long long f[500001];
long long g[500001];
int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i];
	for (int i = 1; i <= n; i++) g[i] = i * a[i] - f[i];
	long long ans = upper_bound(g + 1, g + n + 1, m) - g;
	cout << ans - 1;
	return 0;
}
