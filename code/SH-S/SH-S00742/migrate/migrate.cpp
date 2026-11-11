#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll point_id, t;
ll n, d, ans;
ll x[200005];
pair<ll, ll> f[5003][5003];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> point_id >> t;
	while(t--)
	{
		cin >> n >> d;
		if(n > 300)
		{
			cout << 0 << "\n";
			continue;
		}
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		memset(f, 0x3f, sizeof(f));
		for(ll l = 2; l <= n; l++)
			for(ll i = 1; i <= n; i++)
			{
				ll j = i + l - 1;
				if(j > n) continue;
				if(x[j] - x[i] <= d)
				{
					f[i][j] = {1, 1};
					continue;
				}
				for(int k = i + 1; k <= j - 1; k++)
				{
					if(f[i][k].first > 1e9 || f[k][j].first > 1e9)
						continue;
					ll len = f[i][k].first + f[k][j].first;
					if(len < f[i][j].first)
						f[i][j] = {len, 
						f[i][k].second * f[k][j].second};
					else if(len == f[i][j].first)
						f[i][j].second += 
						f[i][k].second * f[k][j].second;
				}
				//cout << i << "," << j << "=" 
				//<< f[i][j].first << "/" << f[i][j].second<<"-"<<f[i][j].second / (f[i][j].first-1) << endl;
				f[i][j].second /= f[i][j].first - 1;
			}
		ans = 0;
		for(ll i = 1; i <= n; i++)
			for(ll j = i + 1; j <= n; j++)
				if(f[i][j].second == 2)
					ans++;
		cout << ans << "\n";
	}
	return 0;
}

