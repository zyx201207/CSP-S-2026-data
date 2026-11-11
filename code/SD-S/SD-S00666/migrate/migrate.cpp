#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5e3 + 10;

int n, d;
int x[N];
int a[N];
map<int, int> mp;

void solve()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int u = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
		a[i] = u;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		mp.clear();
		int maxx = 0;
		for(int j = i; j <= n; j++)
		{
			mp[a[j]]++;
			maxx = max(maxx, mp[a[j]]);
			if(maxx == 3 && mp.size() >= 2)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--)
	{
		solve();
	}
	return 0;
}
//Oct31==Dec25?
