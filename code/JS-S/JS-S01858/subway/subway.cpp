#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 502, M = 500005;
int C, n, m, d, Q;
int k, a, t, xr, yr;
int w[M];
//map<pair<int, int>, int> s2l;//station to line
vector<pair<int, int>> station[M];

int  f[N][N];



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		
		for(int j = 1;j <= k;j++)
		{
			cin >> a >> t;
			station[a].push_back({i, t});
		}
	}
	//init
	memset(f, 0x3f , sizeof f);
	for(int i = 1;i <= n;i++)
		f[i][i] = 0;
	for(int i = 1;i <= m;i++)
		for(auto u:station[i])
			for(auto v:station[i])
			{
				int up = u.first, vp = v.first, ut = u.second, vt = v.second;
				if(up == vp) continue;
				f[up][vp] = min(f[up][vp], ut+vt);
			}
		
	
	
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(Q--)
	{
		cin >> xr >> yr;
		int res = INF;
		for(auto u:station[xr])
			for(auto v:station[yr])
			{
				int up = u.first, vp = v.first, ut = u.second, vt = v.second;
				res = min(res, f[up][vp] + ut + vt);
			}
		res += w[xr] + w[yr];
		cout << res << "\n";
	}
	return 0;
}
