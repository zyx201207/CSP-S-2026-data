#include <bits/stdc++.h>
using namespace std;

#define int long long

int f[305][305], cnt[305][305], n, d;

inline void floyd()
{
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			if(i != k)
				for(int j = 0; j < n; j++)
					if(j != i && j != k && f[i][j] > f[i][k] + f[k][j])
						f[i][j] = f[i][k] + f[k][j];
 	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			if(i != k)
				for(int j = 0; j < n; j++)
					if(j != i && j != k && f[i][j] == f[i][k] + f[k][j])
						cnt[i][j] += cnt[i][k] * cnt[k][j];
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c, t;
	cin >> c >> t;
	if(c <= 6)
		while(t--)
		{
			memset(f, 0x3f, sizeof(f));
			memset(cnt, 0, sizeof(cnt));
			cin >> n >> d;
			vector<int> a(n);
			for(int i = 1; i <= n; i++) cin >> a[i - 1];
			sort(a.begin(), a.end());
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
				{
					if(abs(a[j] - a[i]) <= d)
						f[i][j] = 1, cnt[i][j] = 1;
				}
			floyd();
			int sum = 0;
			for(int i = 0; i < n - 1; i++)
				for(int j = i + 1; j < n; j++)
					sum += (cnt[i][j] == 2);
			cout << sum << '\n';
		}
	else
		while(t--)
		{
			cin >> n >> d;
			vector<int> a(n);
			for(int i = 1; i <= n; i++) cin >> a[i - 1];
			int x = 0;
			if(n > 1) x = a[1] - a[0];
			cout << (d - x + 1) / x + 1 << '\n';
		}

	return 0;
}

