#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int c , n , m , d , q;
int w[N];
struct node
{
	int a , t;
};
int k[505];
int f[505][505];
vector <node> zt[N];
void add_edge(int u , int v , int w)
{
	f[u][v] = min(f[u][v] , w);
	f[v][u] = min(f[v][u] , w);
}
void floyd()
{
	for(int k = 1;k <= n;k ++)
	{
		for(int i = 1;i <= n;i ++)
		{
			for(int j = 1;j <= n;j ++)
			{
				f[i][j] = min(f[i][j] , f[i][k] + f[k][j]);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	memset(f , 0x3f , sizeof(f));
	for(int i = 1;i <= n;i ++)
	{
		f[i][i] = 0;
	}
	for(int i = 1;i <= n;i ++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++)
		{
			int aa , tt;
			cin >> aa >> tt;
			zt[aa].push_back({i , tt});
		}
	}
	for(int i = 1;i <= m;++ i)
	{
		int tmp = zt[i].size();
		for(int j = 0;j < tmp;++ j)
		{
			for(int k = j + 1;k < tmp;++ k)
			{
				add_edge(zt[i][j].a , zt[i][k].a , zt[i][j].t + zt[i][k].t);
			}
		}
	}
	floyd();
	while(q --)
	{
		int u , v;
		cin >> u >> v;
		int ans = 1e18;
		for(int i = 0;i < zt[u].size();i ++)
		{
			for(int j = 0;j < zt[v].size();j ++)
			{
				ans = min(ans , w[u] + w[v] + zt[u][i].t + zt[v][j].t + f[zt[u][i].a][zt[v][j].a]);
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
//Expected 100pts

//bu yao tian cuo zhun kao zheng hao!!!!!!!!!!!!!!!!!!!!
//bu yao xie cuo wen jian ming
//bu yao bu kai freopen
//bu yao bu kai longlong
//bu yao kai xiao shu zu

//start at 15:22
//finish at 15:40


