/* construct : OCT 31'26 */
#include	<algorithm>
#include	<iostream>
#define		int		long long
using namespace std;
constexpr int maxn = 5e5+4;

int n, m;
int a[maxn];
int p[maxn];

signed main (void)
{
	// freopen ("crystal.in", "r", stdin);
	// freopen ("crystal.out", "w", stdout);
	scanf ("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%lld", a + i);
	sort (a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		p[i] = p[i - 1] + a[i];
	for (int l = 1, r = 1; r <= n; r++)
	{
		// cout << l << ' ' << r << " : ";
		while (a[r] * (r - l + 1) - (p[r] - p[l - 1]) > m)
			l++;
		// cout << l << ' ' << r << endl;
		ans = max (ans, r - l + 1);
	}
	printf ("%lld\n", ans);
	return 0;
}
