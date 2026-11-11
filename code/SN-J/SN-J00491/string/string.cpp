#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 5;
int n, a[N]; char c[N];

int main()
{
	freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> a[i] >> c[i];
	
	long long ans = 0;
	for (int i = 1, j = n; i < j;)
	{
		int cnt = min(a[i], a[j]);
		if (c[i] != c[j]) ans += cnt;
		a[i] -= cnt, a[j] -= cnt;
		if (a[i] == 0) ++ i;
		if (a[j] == 0) -- j;
	}
	cout << ans << '\n';
	return 0;
}
