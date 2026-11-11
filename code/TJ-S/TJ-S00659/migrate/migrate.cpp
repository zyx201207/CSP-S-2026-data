#include <bits/stdc++.h>
using namespace std;

long long c, t, n, m, a[2000006], f[1005][1005], f1[1005][1005], cnt[1005][1005];

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--)
	{
		cin >> n >> m;
		for (int i = 1;i <= n; i++)
		{
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				cnt[i][j] = cnt[j][i] = 0;
				if (a[j] - a[i]<=m)
				{
					f[i][j]=f[j][i]=a[j]-a[i];
					f1[i][j]=f1[j][i]=f[i][j];
				} else
				{
					f[i][j]=f[j][i] = 0x3f3f3f3f3f3f3f3f;
					f1[i][j]=f1[j][i]=f[i][j];
				}
			}
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (f[i][j] > f[i][k] +f[k][j])
					{
						f[i][j] = f[i][k] +f[k][j] ;
					}
				}
			}
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (f1[i][j] >= f1[i][k] +f1[k][j])
					{
						f1[i][j] = f1[i][k] +f1[k][j] ;
						if (f1[i][j] == f[i][j] && i != j && j != k && i != k)
						{
//							if (cnt[i][j] == 1)cout<<i<< " "<< " " << j <<" " << k << "\n";
							cnt[i][j]++;
						}

					}
				}
//				cout << "\n";
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
//				cout << cnt[i][j] <<" ";
				if (cnt[i][j] == 2) 
				{
//					cout << i << "  " << j << endl;
ans++;
				}
			}
//			cout << endl;
		}
		cout << ans << "\n";
	 } 
    // "\n"
    return 0;
}
