#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 5;
int n, m, a[N]; bool vis[N];

int main()
{
	freopen("and.in", "r", stdin), freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) cin >> a[i];
	
	int ans = 0;
	for (int k = 29; 0 <= k; -- k)
	{
		int cnt = 0;
		for (int i = 1; i <= n; ++ i)
			if (!vis[i] && ((a[i] >> k) & 1) == 1) ++ cnt;
		
		if (m <= cnt)
		{
			ans += (1 << k);
			for (int i = 1; i <= n; ++ i)
				if (((a[i] >> k) & 1) == 0) vis[i] = true;
		}
	}
	cout << ans << '\n';
	return 0;
}
