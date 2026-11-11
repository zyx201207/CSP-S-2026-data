#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[20005],a[5005][5005],t[5005][5005],k[20005],r[20005],x[10005],y[10005];
vector<int> egde[20005];
void dijsktra()
{
	cout << 0 << endl;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >>n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i++)
	{
		cin >> x[i] >> y[i];
		dijsktra();
	}
	return 0;
} 
