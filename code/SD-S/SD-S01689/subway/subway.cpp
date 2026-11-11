#include<bits/stdc++.h> 
using namespace std;

long long c, m, n, d, q;
long long a[1005], b[1005], sum1 = 0, sum2 = 0, cnt = 0;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> m >> n >> c >> d >> q; 
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		for (int j = 1; j <= m; j ++)
		{
			cin >> b[j];
		}
	} 
	for (int w = 1; w <= d; w ++)
	{
		cnt = a[1] - b[2];
	}
	for (int t = 0; t <= q; t ++)
	{
		if (cnt < a[1])
		{
			sum1 += a[1];
		}
		else
		{
			sum2 += a[1];
		}
	}
	for (int r = 1; r <= q; r ++)
	{
		sum1 = b[2] + cnt;
		sum2 = b[2] - cnt;
	}
	cout << sum1 << endl;
	cout << sum2 << endl;
	return 0;
}
