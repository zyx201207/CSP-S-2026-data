#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int MAXN = 0x3f3f;
int w[MAXN],k[MAXN],a[MAXN][MAXN],t[MAXN][MAXN];
int x[MAXN],y[MAXN]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i =1;i <= m;i++)
	{
		cin >> w[i];
	} 
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for (int j = 1;j < n + 2;j++)
		{
			cin >> a[i][j];
			cin >> t[i][j]; 
		}
	}
	for (int r = 1;r <= q;r++)
	{
		cin >> x[r];
		cin >> y[r];
	}
	return 0;
}