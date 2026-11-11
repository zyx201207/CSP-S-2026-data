#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+5;

ll c, n, m, d, q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数 
ll w[N], a[N][20], t[N][20];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> a[j][i] >> t[j][i];
		}
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		ll ans = 0;
		ans = w[x] + w[y] + t[x][1] + t[y][1];
		cout << ans << "\n";
	}
	return 0;
}
