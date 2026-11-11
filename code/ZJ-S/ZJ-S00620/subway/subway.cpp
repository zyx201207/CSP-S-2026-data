#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5,M = 5e5 + 5,D = 20 + 5;
const long long INF = 1e18;
int c,n,m,d,q;
int w[M];
int ra[M][D],ti[M][D],cur[M];
long long len[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> w[i];
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= n;j ++)
		{
			len[i][j] = INF;
		}
		len[i][i] = 0;
		int k;
		cin >> k;
		for(int j = 1;j <= k;j ++)
		{
			int a,t;
			cin >> a >> t;
			ra[a][++ cur[a]] = i;
			ti[a][cur[a]] = t;
		}
	}
	for(int i = 1;i <= m;i ++)
	{
		for(int j = 1;j < cur[i];j ++)
		{
			for(int k = j + 1;k <= cur[i];k ++)
			{
				int fir = ra[i][j],sec = ra[i][k];
				len[fir][sec] = min(len[fir][sec],0ll + ti[i][j] + ti[i][k]);
				len[sec][fir] = len[fir][sec];
			}
		}
	}
	for(int k = 1;k <= n;k ++)
	{
		for(int i = 1;i <= n;i ++)
		{
			for(int j = i + 1;j <= n;j ++)
			{
				len[i][j] = min(len[i][j],len[i][k] + len[k][j]);
				len[j][i] = len[i][j];
			}
		}
	}
	for(int i = 1;i <= q;i ++)
	{
		long long ans = 1e18;
		int x,y;
		cin >> x >> y;
		for(int j = 1;j <= cur[x];j ++)
		{
			for(int k = 1;k <= cur[y];k ++)
			{
				ans = min(ans,len[ra[x][j]][ra[y][k]] + ti[x][j] + ti[y][k]);
			}
		}
		ans += 0ll + w[x] + w[y];
		cout << ans << '\n'; 
	}
	return 0;
}
