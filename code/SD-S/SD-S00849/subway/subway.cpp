#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N = 505,M = 500005;
int c,n,m,d,q,w[M],k[N],f[N][N];
struct node
{
	int ln,t;
};
vector<node>vec[M];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int x,y;
			cin >> x >> y;
			vec[x].push_back({i,y});
		}
	}
	memset(f,0x3f,sizeof f);
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (node j: vec[i])
			for (node k: vec[i])
			{
				if (j.ln != k.ln)
				{
					f[j.ln][k.ln] = min(f[j.ln][k.ln],j.t+k.t);
				}
			}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][k]+f[k][j],f[i][j]);
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		int ans = 0x3f3f3f3f3f3f3f3f;
		for (node j: vec[x])
			for (node k: vec[y])
				ans = min(ans,j.t+k.t+f[j.ln][k.ln]);
		cout << ans+w[x]+w[y] << '\n';
	}
	return 0;
}
