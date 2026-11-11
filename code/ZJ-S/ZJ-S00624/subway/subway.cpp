#include <bits/stdc++.h>
#define int long long
using namespace std;
const int CN = 505,CM = 6e5+5,inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,qq,k,x,y,t,ans,a[CM],f[CN][CN];
vector <pair<int,int> > e[CM];
#undef int
int main()
#define int long long
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> m >> n >> d >> qq;
	m += n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = n+1;i <= m;i++)
	{
		cin >> k;
		while (k--)
		{
			cin >> x >> t;
			e[x].push_back({i,t});
			e[i].push_back({x,t});
		}
	}
	m -= n;
	memset(f,0x3f,sizeof(f));
	for (int i = 1;i <= m;i++)
		f[i][i] = 0;
	for (int x = 1;x <= n;x++)
		for (auto [i,w1]:e[x])
			for (auto [j,w2]:e[x])
				f[i-n][j-n] = min(f[i-n][j-n],w1+w2);
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= m;j++)
			for (int k = 1;k <= m;k++)
				f[j][k] = min(f[j][k],f[j][i]+f[i][k]);
	while (qq--)
	{
		cin >> x >> y;
		ans = inf;
		for (auto [i,w1]:e[x])
			for (auto [j,w2]:e[y])
				ans = min(ans,a[x]+a[y]+w1+w2+f[i-n][j-n]);
		cout << ans << '\n';
	}
	return 0;
}