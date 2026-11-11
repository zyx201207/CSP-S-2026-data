#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 505, M = 5e5+5, inf = 0x7f7f7f7f7f7f7f7f;
ll w[M];
vector<pair<ll, ll> > pt[M];
vector<ll> a[M], t[M];
int n, m, ql, d, c;
int l, r;
ll dp[N][N];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> ql;
	for(int i=1; i<=m; i++)
		cin >> w[i];
	memset(dp, 0x7f, sizeof dp);
	for(int i=1; i<=n; i++)
	{
		int k;
		cin >> k; a[i].resize(k+1, 0); t[i].resize(k+1, 0);
		for(int j=1; j<=k; j++)
		{
			cin >> a[i][j] >> t[i][j];
			pt[a[i][j]].push_back({i, t[i][j]});
		}
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<a[i].size(); j++)
			for(auto k:pt[a[i][j]])
				if(i != k.first)
					dp[i][k.first] = min(dp[i][k.first], k.second + t[i][j]);
//	for(int l=1; l<=n; l++)
//	{
//		for(int r=1; r<=n; r++)
//			cout << dp[l][r] << ' ';
//		cout << '\n';
//	}
	for(int l=1; l<=n; l++)dp[l][l] = 0;
	for(int l=1; l<=n; l++)
		for(int r=1; r<=n; r++)
			for(int k=1; k<=n; k++)
				if(dp[l][k] != inf && dp[k][r] != inf)
					dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r]);

	for(int i=1; i<=ql; i++)
	{	
		ll ans = inf;
		cin >> l >> r;
		for(auto x:pt[l])
			for(auto y:pt[r])
			{
				int a = x.first, b = y.first;	
//				cout << a << " " << b << '\n';
				int w1 = x.second, w2 = y.second;
				ans = min(ans, dp[a][b] + w[l] + w[r] + w1 + w2);	
			}
			
		cout << ans << '\n';
	}
	return 0;
}