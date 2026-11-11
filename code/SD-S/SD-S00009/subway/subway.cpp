#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505,M = 5e5 + 5,inf = 1e18;
int c,n,m,d,q;
int f[N][N],w[M],cnt[M];
vector <int> b[N];
struct node
{
	int a,t;
}t[M][23];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	memset(f,0x3f,sizeof f);
	for (int i = 1; i <= m; i ++)
		cin >> w[i];
	for (int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j ++)
		{
			int a,tt;
			cin >> a >> tt;
			t[a][++cnt[a]].a = i,t[a][cnt[a]].t = tt;
			b[i].push_back(a);	
			//cout << a << "ttt\n";		
		}	
	}
	for (int i = 1; i <= n; i ++)
	{
		for (int a : b[i])
		{
			int tt = 0;
			for (int j = 1; j <= cnt[a]; j ++)
			{
				if (t[a][j].a == i)
				{
					tt = t[a][j].t;
					break;	
				}		
			}
			//cout << i << " "<< a << " " << tt << "tt\n";
			for (int j = 1; j <= cnt[a]; j ++)
			{
				if (t[a][j].a == i)
					continue;
				f[i][t[a][j].a] = min(f[i][t[a][j].a],tt + t[a][j].t);
				f[t[a][j].a][i] = f[i][t[a][j].a];	
				//cout << i << " " << t[a][j].a << " " << f[i][t[a][j].a] << endl;
			}	
		}	
	}
	for (int i = 1; i <= n; i ++)
		f[i][i] = 0;
	for (int k = 1; k <= n; k ++)
	{
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= n; j ++)
			{
				f[i][j] = min(f[i][k] + f[k][j],f[i][j]);	
			}	
		}	
	}
	//cout << f[1][2] << "\n";
	while(q --)
	{
		int x,y;
		cin >> x >> y;
		int ans = inf;
		for (int i = 1; i <= cnt[x]; i ++)
		{
			for (int j = 1; j <= cnt[y]; j ++)
			{
				ans = min(ans,f[t[x][i].a][t[y][j].a] + w[x] + w[y] + t[x][i].t + t[y][j].t);
				//cout << t[x][i].a << " " << t[y][j].a << " " <<	w[x] + w[y] << " "<< t[x][i].t<<" " << t[y][i].t << "\n";	
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

