#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c, t, n, d, x[2000005], mat[5005][5005], num[5005][5005];

// RP++
int main()
{
	freopen("migrate.in", "r", stdin);
//	freopen("..\\csps\\down\\migrate\\migrate3.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("..\\csps\\down\\migrate\\migrate.out", "w", stdout);
	
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	
	scanf("%lld%lld", &c, &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &d);
		for (ll i = 0; i < n; i++)
			scanf("%lld", x + i);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				mat[i][j] = 0x7fffffffffffffff;
		
		ll total = 0;
		for (ll i = 0; i < n - 1; i++)
			mat[i][i + 1] = x[i + 1] - x[i] <= d ? 1 : -1;
		for (ll i = 2; i <= n; i++)
			for (ll j = 0; j + i < n; j++)
			{
				if (x[i + j] - x[j] <= d)
				{
					mat[j][i + j] = num[j][i + j] = 1;
					continue;
				}
				bool jjj = true;
				for (ll k = j + 1; k < j + i; k++)
				{
					if (mat[j][k] < 0 || mat[k][j + i] < 0)
						continue;
					jjj = false;
					int temp = mat[j][k] + mat[k][j + i];
					if (temp < mat[j][j + i])
						mat[j][j + i] = temp, num[j][j + i] = 1;
					else if (temp == mat[j][j + i])
						num[j][j + i]++;
				}
				if (jjj)
					mat[j][j + i] = -1;
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (num[i][j] == 2)
					total++;
		printf("%lld%s", total, t ? "\n" : "");
	}
	
	// *0
	// while(1)
	// for(;;)
	// y1
	// confront
	// testify
	// 2U
	
	return 0;
}