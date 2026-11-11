#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[200001], ans;
void dfs(int u, int k, long long sum)
{
	if (u == n + 1 || k == m + 1)
	{
		if (k == m + 1)
			ans = max(ans, sum);
		return;
	}
	if (k == 1)
		sum = a[u];
	dfs(u + 1, k + 1, sum & a[u]);
	dfs(u + 1, k, sum);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf ("%lld", &a[i]);
	dfs(1, 1, 0);
	cout << ans;
	return 0;
}