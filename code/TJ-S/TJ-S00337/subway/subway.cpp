#include <bits/stdc++.h>
using namespace std;

long long n,m,d,q,w[500010],k[500],a[500][500010],t[500][500010],x[100010],y[100010];

int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> n >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
			cin >> a[i][j] >> t[i][j];
	}
	for(int r = 1;r <= q;r++)
	{
		cin >> x[r] >> y[r];
		
	}
	return 0;
}
