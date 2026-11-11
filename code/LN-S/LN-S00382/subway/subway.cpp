#include <bits/stdc++.h>
using namespace std;
#define int long long
bool flag1 = 1;
int c,n,m,d,q,w[500005],k[500005],a[505][500005],t[505][500005];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++) cin >> w[i];
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j++) cin >> a[i][j] >> t[i][j];
	}
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		cout << w[x] + t[x][x] + t[x][y] + w[y] << '\n';
	}
	return 0;
}
