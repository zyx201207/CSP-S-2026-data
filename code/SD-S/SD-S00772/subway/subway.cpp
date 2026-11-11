#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXM = 5e5+5;
const int MAXN = 505;
const int MAXK = 5e5+5;
int c, n, m, d, q;
ll ans;
int w[MAXM];
int a[MAXN][MAXK], t[MAXN][MAXK];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		ans += w[x];
		for(int i = x; i <= y; i++)
		{
			
		}
	}

	return 0;
}//Oct31==Dec25?
