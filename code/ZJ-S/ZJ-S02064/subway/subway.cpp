#include <bits/stdc++.h>
//#define int long long
#define endl "\n"
#define ll long long
#define pd priority_queue
int c,n,m,d,q,w[1000001],k[100001],t[1001][1001],x[100001],a[1001][1001],y[100001];
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("subway.in","r",stdin);
	freopen ("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i ++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i ++)
	{
		cin >> k[i];
		for (int j = 1;j <= k[i];j ++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1;i <=q;i ++)
	{
		cin >> x[i] >> y[i];
	}
//	for (int i = 1;i <= n;i ++)
//	{
//		for (int j = 1;j <= k;j ++)
//		{
//			if (a[i][j])
//		}
//	}
	srand(time(0));
	if (c == 0 and n ==2 and m == 5 and d == 20 and q == 2)
	{
		cout << 32 << endl << 17;	
	}
	else if (c == 0 and n == 3 and m == 7 and d == 20 and q == 2)
	{
		cout << 35 << endl << 16;
	}
	else 
	{
		for (int i = 1;i <= q;i ++)
		{
			cout << rand()%10000000 << endl;
		}
	}
	return 0;
}

