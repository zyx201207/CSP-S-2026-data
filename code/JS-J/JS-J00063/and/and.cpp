#include <bits/stdc++.h>
using namespace std;

/*
 * 0011
 * 1111
 * 1100
 * 1100
*/

vector<int> a;
vector<bool> t, f;

int main()
{
#ifndef DEBUG
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);

	int n, m, Max = 0, ans = 0;

	cin >> n >> m;
	a.resize(n);
	t.resize(n);
	f.resize(n);
	for (int i = 0; i < n; i++)
	{
		f[i] = 1;
		cin >> a[i];
		Max = max(Max, a[i]);
	}

	// clog << ceil(log(Max))+1 << " " << Max;

	for (int i = 31; i >= 0; i--)
	{
		// clog << "i=" << i << endl;
		for (int j = 0; j < n; j++)
		{
			t[j] = ((a[j] >> i) & 1) & f[j];
			// clog << t[j] << " ";
		}
		// clog << endl;
		// for (int j = 0; j < n; j++)
		// {
		// 	clog << f[j] << " ";
		// }
		int _ = count(t.begin(), t.end(), 1);
		// clog << endl
		// 	 << _ << " " << (_ >= m) << endl
		// 	 << endl;
		if (_ >= m)
		{
			for (int j = 0; j < n; j++)
			{
				f[j] = f[j] & t[j];
			}
			ans += (1 << i);
		}
	}

	cout << ans << endl;

	return 0;
}