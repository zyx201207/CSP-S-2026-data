# include <bits/stdc++.h>
using namespace std;
# define int long long 
typedef long long ll;
typedef unsigned long long ull;
# define lc (u << 1)
# define rc (u << 1 | 1)
# define fi first
# define se second 
const int N = 500005;

int n, m;
int a[N];
void solve ()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		cin >> a[i];
	sort (a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1, j = 1, sum = 0; i <= n; i ++ )
	{
		sum += (i - j) * (a[i] - a[i - 1]);
		while (j < i && sum > m)
		{
			j ++ ;
			sum -= a[i] - a[j];
		}
		ans = max (ans, i - j + 1);
	}
	cout << ans << endl;
}
signed main ()
{
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	freopen ("crystal.in", "r", stdin), freopen ("crystal.out", "w", stdout);
	int T; T = 1;
	while (T -- )
		solve ();
	return 0;
}
