#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 10,M = 550;
typedef long long LL;
vector<pair<LL,LL>> a[N];
LL f[M][M];
LL w[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	LL id,n,m,d,q;
	cin>>id>>n>>m>>d>>q;
	for(int i = 1; i <= m; i ++) cin>>w[i];
	for(int i = 1,k,x,y; i <= n; i ++)
	{
		cin>>k;
		while(k --) cin>>x>>y,a[x].push_back({i,y});
	}
	memset(f,0x3f,sizeof f);
	for(int i = 1; i <= m; i ++)
		for(auto x : a[i])
			for(auto y : a[i])
				if(x.first != y.first)
				{
					f[x.first][y.first] = min(f[x.first][y.first],x.second + y.second);
					f[y.first][x.first] = min(f[y.first][x.first],x.second + y.second);
				}
	for(int i = 1; i <= n; i ++) f[i][i] = 0;
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++) f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
	while(q --)
	{
		int x,y;
		cin>>x>>y;
		LL res = 1e18;
		for(auto i : a[x])
			for(auto j : a[y]) res = min(res,f[i.first][j.first] + i.second + j.second);
		cout<<res + w[x] + w[y]<<'\n';
	}
	return 0;
}
//station-t->line
//line-t->station
//line-line
//w_x+w_y+stationx->stationy
//15:22
