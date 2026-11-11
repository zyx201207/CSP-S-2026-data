#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define FOR(w, a) for(i64 i = w; i <= a; i++)
#define I ios::sync_with_stdio(0);
#define AC cin.tie(0);
#define T3 cout.tie(0);
#define l first
#define r second
#define pb push_back
i64 a[200010];
i64 f[50], mx;
i64 n, m;
void dfs(int p, int cnt)
{
	if(p > n || cnt == m)
	{
		if(cnt == m)
		{
			i64 ans = INT_MAX;
			FOR(1, n) if(f[i] == 1) ans &= a[i];
			mx = max(mx, ans);
		}
		return;
	}
	f[p] = 1;
	dfs(p + 1, cnt + 1);
	f[p] = 0;
	dfs(p + 1, cnt + 1);
	return;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	I AC T3
	cin >> n;
	cin >> m;
	FOR(1, n) cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	if(m == 1) cout << a[1];
	if(m == n)
	{
		i64 ans = a[1];
		FOR(1, n) ans &= a[i];
		cout << ans; 
	}
	else if(m == n - 1)
	{
		i64 ans = 0;
		FOR(1, n)
		{
			i64 sum = a[1];
			if(i == 1) sum = a[2];
			for(int j = 1; j <= n; j++) if(j != i) sum &= a[j];
			ans = max(sum, ans);
		}
		cout << ans;
	}
	else if(m == 2)
	{
		i64 ans = 0;
		FOR(1, n) for(int j = i + 1; j <= n; j++) ans = max(ans, a[i] & a[j]);
		cout << ans;
	}
	else if(n <= 20)
	{
		dfs(1, 0);
		cout << mx;
	}
	else
	{
		cout << a[m];
	}
	return 0;
}
