#include <bits/stdc++.h>
#define int long long
#define N 510
#define M 500010
//韩心尧 SN-S00467 西安市铁一中学 
using namespace std;

struct tms
{
	int l,t;
};
int c,n,m,d,q;
int k[N];
int w[M];
vector<tms> sl[M];
struct pl
{
	int u,v;
}pls[100010];
int f[N][N];
int ans;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out ","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(f,0x3f,sizeof(f));
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= n;i++)
	{
		f[i][i] = 0;
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++)
		{
			int a,t;
			cin >> a >> t;
			sl[a].push_back({i,t});
		}
	}
	for (int i = 1;i <= q;i++)
	{
		int x,y;
		cin >> x >> y;
		pls[i] = {x,y};
	}
	for (int i = 1;i <= m;i++)
	{
		for (auto it1 = sl[i].begin();it1 != sl[i].end() - 1;it1++)
		{
			for (auto it2 = it1 + 1;it2 != sl[i].end();it2++)
			{
				tms sta1 = *it1,sta2 = *it2;
				int u1 = sta1.l,u2 = sta2.l,ta = sta1.t,tb = sta2.t;
				f[u1][u2] = f[u2][u1] = min(f[u1][u2],ta + tb);
			}
		}
	}
	for (int k = 1;k <= n;k++)
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
			}
		}
	}
//	for (int i = 1;i<= n;i++)
//	{
//		for (int j = i + 1;j <= n;j++)
//		{
//			//printf("dis (%d,%d) = %d\n",i,j,f[i][j]);
//		}
//	}
	for (int i = 1;i <= q;i++)
	{
		//printf("q = %d\n",i);
		ans = (int)1000000000000000000;
		int u = pls[i].u,v = pls[i].v;
		for (auto it1 = sl[u].begin();it1 != sl[u].end();it1++)
		{
			for (auto it2 = sl[v].begin();it2 != sl[v].end();it2++)
			{
				tms sta1 = *it1,sta2 = *it2;
				int u1 = sta1.l,u2 = sta2.l,ta = sta1.t,tb = sta2.t;
				ans = min(ans,f[u1][u2] + ta + tb + w[u] + w[v]);
				//printf("ans:%d = min(ans,f[%d][%d]:%d + t[%d][%d]:%d + t[%d][%d]:%d + w[%d]:%d + w[%d]:%d)\n",ans,u1,u2,f[u1][u2],u1,u,ta,u2,v,tb,u,w[u],v,w[v]);
				
			}
		}
		cout << ans<<endl;
	}
	
	return 0;
}
