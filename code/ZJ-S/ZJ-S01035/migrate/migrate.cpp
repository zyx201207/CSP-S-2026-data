#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5,maxn = 5e3 + 5;
int x [N],nxt [N];
int c,T;
int n,d;
int dis [maxn] [maxn],s [maxn] [maxn];
void solve1 ()
{
	cin >> n >> d;
	for (int i = 1;i <= n;i ++) cin >> x [i];
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= n;j ++) dis [i] [j] = -2,s [i] [j] = 0;
	for (int i = 1;i <= n;i ++)
	{
//		nxt [i] = upper_bound (x + i + 1,x + n + 1,x [i] + d) - x - 1/*,cout << nxt [i] << ' '*/;
		for (int j = i;j <= n;j ++)
			if (x [j] - x [i] <= d) nxt [i] = j;
			else break;
	}
//	cout << endl;
	for (int i = 1;i <= n;i ++)
	{
		dis [i] [i] = 0,s [i] [i] = 1;
		int j = i,lst = i,f = 0;
		while (j != nxt [j])
		{
			j = nxt [j];
			f ++;
			for (int k = lst + 1;k <= j;k ++) dis [i] [k] = f,s [i] [k] = 1;
			lst = j;
		}
	}
//	for (int l = 1;l <= n;l ++)
//	{
//		for (int r = l;r <= n;r ++) cout << l << ' ' << r << ' ' << dis [l] [r] << endl;
//	}
	int ans = 0;
	for (int len = 2;len <= n;len ++)
	{
		for (int l = 1;l + len - 1 <= n;l ++)
		{
			int r = l + len - 1;
			for (int k = l + 1;k <= nxt [l];k ++)
				if (dis [l] [r] == 1 + dis [k] [r]) s [l] [r] += s [k] [r];
			s [l] [r] --;
//			cout << l << ' ' << r << ' ' << s [l] [r] << endl;
			ans += (s [l] [r] == 2);
//			if (s [l] [r] == 2) cout << l << ' ' <<r << endl;
		}
	}
	cout << ans << endl;
}
void solve2 ()
{
	cin >> n >> d;
	for (int i = 1;i <= n;i ++) cin >> x [i];
	int t = x [n] - x [n - 1];
	if (d <= t || d >= t * (n - 1))
	{
		cout << "0\n";
		return ;
	}
	int k = d / t;
	cout << max (n - 2 * k + 1,0LL) << endl;
}
signed main ()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> T;
	if (c == 11 || c == 12) while (T --) solve2 ();
	else while (T --) solve1 ();
	return 0;
}