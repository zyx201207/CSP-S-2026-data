/* construct : OCT 31'26 */
#include	<algorithm>
#include	<iostream>
#include	<cstring>
#include	<map>
#define		int		long long
using namespace std;
constexpr int maxn = 5e5+4;

int a[maxn];
int b[maxn];
int n, m, ans;

void dfs (int dep, int m)
{
	if (dep == n + 1)
	{
		map<int,int> mp;
		for (int i = 1; i <= n; i++)
			mp[a[i]]++;
		for (auto [_, val] : mp)
			ans = max (ans, val);
		// if (a[1] == 4 && a[2] == 4)
		// {
		// 	for (int i = 1; i <= n; i++)
		// 		cout << a[i] << ' ';
		// 	cout << endl;
		// }
		return ;
	}
	for (int i = 0; i <= m; i++)
	{
		a[dep] += i;
		dfs (dep + 1, m - i);
		a[dep] -= i;
	}
}

signed main (void)
{
	// freopen ("crystal.in", "r", stdin);
	// freopen ("crystal.out", "w", stdout);
	scanf ("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", a + i);
	dfs (1, m);
	printf ("%lld\n", ans);
	return 0;
}
