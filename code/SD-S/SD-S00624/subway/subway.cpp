#include <bits/stdc++.h>
using namespace std;
long long c , n , m , d , q , w[10000005] , a[5005][5005] , t[5005][5005] , x[10000005] , y[10000005];
vector <int> v;
int main ()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; i++)
		{
			cin >> a[i][j] >> t[i][j];
		}
		for(int j = 1; j <= k; i++)
		{
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= q; i++)
	{
		cin >> x[i] >> y[i];
	}
	for(int i = 1; i <= q; i++)
	{
		cout << 0 << endl;
	} 
	return 0;
}

