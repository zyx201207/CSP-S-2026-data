#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n, m, ans;
void dfs(int stp, int now, int ans1)
{
	if(now == m)
	{
		ans = max(ans, ans1);
		return;
	}
	for(int i = stp + 1; i <= n; i ++)
	{
		dfs(i, now + 1, ans1 & a[i]);
	}
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	dfs(0, 0, INT_MAX);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
