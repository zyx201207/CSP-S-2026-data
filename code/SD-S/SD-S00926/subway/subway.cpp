#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mk make_pair
#define fi first
#define se second
const int M = 5e5 + 10,N = 510;
int C,n,m,d,q;
ll w[M],a[N][N];
vector< pair<int,ll> > vec[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> C >> n >> m >> d >> q;
	for(int i = 1;i <= m;++i) cin >> w[i];
	for(int i = 1;i <= n;++i)
	{
		int k;
		cin >> k;
		for(int j = 1;j <= k;++j)
		{
			int x;
			ll z;
			cin >> x >> z;
			vec[x].emplace_back(mk(m + i,z));
		}
	}
	for(int i = 1;i <= n;++i) for(int j = 1;j <= n;++j) a[i][j] = 1e18;
	for(int i = 1;i <= n;++i) a[i][i] = 0;
	for(int i = 1;i <= m;++i)
	{
		for(int j = 0;j < vec[i].size();++j)
		{
			for(int k = 0;k < vec[i].size();++k)
			{
				if(j == k) continue;
				int x = vec[i][j].fi - m,y = vec[i][k].fi - m;
				ll z = vec[i][j].se,zz = vec[i][k].se;
				a[x][y] = min(a[x][y],z + zz);
				a[y][x] = min(a[y][x],z + zz);
			}
		}
	}
	for(int k = 1;k <= n;++k)
	{
		for(int i = 1;i <= n;++i)
		{
			for(int j = 1;j <= n;++j)
			{
				a[i][j] = min(a[i][j],a[i][k] + a[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		ll ans = 1e18;
		for(int i = 0;i < vec[x].size();++i)
		{
			for(int j = 0;j < vec[y].size();++j)
			{
				ans = min(ans,vec[x][i].se + a[vec[x][i].fi - m][vec[y][j].fi - m] + vec[y][j].se);
			}
		}
		ans += w[x] + w[y];
		cout << ans << '\n';
	}
	return 0;
}
