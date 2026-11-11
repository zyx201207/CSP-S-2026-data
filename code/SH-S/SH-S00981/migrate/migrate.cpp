#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 305;

ll a[N], f[N], dis[N][N];
int c;

void solve()
{
	int n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(c == 11 || c == 12)
	{
		cout<<max(0, n - 2 * d + 1) <<endl;
		return;
	}
	if(c == 13 || c == 14)
	{
		a[n + 1] = 3e18;
		int cur = 1;
		for(int i = 1; i <= n; i++)
		{
			while(a[cur] <= a[i] + d) ++cur;
			--cur;
			f[i] = cur;
		}
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(f[f[i]] == cur) ans += n - f[f[i] - 2];
			else ans += f[f[i]] - f[f[i] - 2];
		}
		cout<<ans<<endl;
		return;
	}
	a[n + 1] = 3e18;
	int cur = 1;
	for(int i = 1; i <= n; i++)
	{
		while(a[cur] <= a[i] + d) ++cur;
		--cur;
		f[i] = cur;
	}
	for(int i = 1; i <= n; i++)
	{
		int cnt = 1, cr = i;
		for(int j = i + 1; j <= n; j++)
		{
			if(j <= f[cr]) dis[i][j] = cnt;
			else
			{
				if(f[cr] == cr) dis[i][j] = 1e9;
				else
				{
					dis[i][j] = ++cnt;
					cr = f[cr];
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int flg = 0;
			for(int k = i + 1; k < j; k++)
			{
				if(dis[i][k] + dis[k][j] == dis[i][j]) ++flg;
			}
			if(flg == dis[i][j]) ++ans;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	int t;
	cin >> c >> t;
	while(t--) solve();
}
