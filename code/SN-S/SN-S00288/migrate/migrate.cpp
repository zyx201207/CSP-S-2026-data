// migrate

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e6 + 5;

int c, T, n, d, z;
int a[N], f[N], g[N];
int h, t, q[N], l[N];

inline void init(int lll, int rrr)
{
	for (int i = lll; i <= rrr; i ++)
	{
		l[f[i]] = 0;
		f[i] = 0;
		g[i] = 0;
	}
}

inline void work(int p)
{
	int cnt = 0;
	h = 1;
	t = 0;
	q[++ t] = p;
	l[f[p] = 0] += (g[p] = 1);
	for (int i = p + 1; i <= n; i ++)
	{		
		while (h <= t && a[q[h]] + d < a[i])
		{
			l[f[q[h]]] -= g[q[h]];
			cnt -= (g[q[h]] >= 3);
			h ++;
		}
		if (h > t || cnt == t - h + 1)
		{
			init(p, i);
			return;
		}
		f[i] = f[q[h]] + 1;
		g[i] = l[f[q[h]]];
		if (g[i] == 2) z ++;
		while (h <= t && f[q[t]] > f[i])
		{
			l[f[q[t]]] -= g[q[t]];
			cnt -= (g[q[t]] >= 3);
			t --;
		}
		q[++ t] = i;
		l[f[i]] += g[i];
		cnt += (g[i] >= 3);
		
//		// --------
//		clog << endl;
//		clog << i << " " << h << " " << t << endl;
//		for (int i = h; i <= t; i ++)
//			clog << q[i] << " ";
//		clog << endl;
//		for (int i = 1; i <= n; i ++) clog << f[i] << " "; clog << endl;
//		for (int i = 1; i <= n; i ++) clog << g[i] << " "; clog << endl;
//		// -------- 
	}
	init(p, n);
}

inline void solve()
{	
	cin >> n >> d;
//	clog << n << " " << d << endl;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	if (n > 5000)
	{
		int ttt = d / (a[2] - a[1]);
		if (ttt < 2)
		{
			cout << 0 << endl;
			return;
		}
		cout << max(0ll, n - (ttt * 2 - 1)) << endl;
		return;
	}
	for (int i = 1; i <  n; i ++) work(i);
	cout << z << endl;
}

inline void clear()
{
	z = 0;
	
//	clog << endl;
//	clog << "------------" << endl;
//	clog << endl;
}

signed main()
{
	freopen("migrate.in" , "r", stdin );
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> c >> T;
	while (T --)
	{
		solve();
		clear();
	}
	
	return 0;
}
