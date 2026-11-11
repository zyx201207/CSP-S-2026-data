#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
const int maxn = 5e2+5 , maxm = 1e6+5;
int n , m , d , q , w[maxm] , cnt[maxn];
ll dis[maxn][maxn];
//pii g[maxm][20];
vector<pii>g[maxm];
int read()
{
	char ch=getchar_unlocked(); int x=0;
	while(!isdigit(ch))ch=getchar_unlocked();
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar_unlocked();
	return x;
}
signed main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c;
	scanf("%d%d%d%d%d" , &c , &n , &m , &d , &q);
//	cin >> c >> n >> m >> d >> q;
	memset(dis , 0x3f , sizeof(dis));
//	cerr << c << " " << n << " " << m << d << " " << q << endl;
//	return 0;
	for (int i = 1; i <= m; i++)w[i]=read();
	for (int i = 1; i <= n; i++)dis[i][i]=0;
//	return 0;
	for (int i = 1; i <= n; i++)
	{
		int t;
		scanf("%d" , &t);
		while(t--)
		{
			int v=read() , a=read();
//			scanf("%d%d" , &v , &a);
//			g[v][cnt[v]++]={i,a};
			g[v].pb({i , a});
//			cnt[v]++;
		}
	}
//	for (int i = 1; i <= m; i++)cout << cnt[i] << endl;
//	return 0;
	for (int i = 1; i <= m; i++)
	{
		for (auto [u , w1] : g[i])
		{
			for (auto [v , w2] : g[i])
			{
				if (u == v)continue;
				dis[u][v]=dis[v][u]=w1+w2;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			if (i == k)continue;
			for (int j = 1; j <= n; j++)
			{
				dis[i][j]=min(dis[i][j] , dis[i][k]+dis[k][j]);
			}
		}
	}
//	return 0;
	while(q--)
	{
		int x , y;
		cin >> x >> y;
		ll res = 1e18;
		for (auto [u , w1] : g[x])
		{
			for (auto [v , w2] : g[y])
			{
				res=min(res , w1 + w2 + dis[u][v]);
			}
		}
		res+=w[x]+w[y];
		printf("%lld\n" , res);
//		cout << res << "\n";
	}
	return 0;
}