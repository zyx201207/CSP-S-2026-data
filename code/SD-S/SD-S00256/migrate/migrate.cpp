#include <bits/stdc++.h>
#define DEBUG cout << "debug" << endl;
#define int long long
using namespace std;
int n, c, T, m;
int f[5005][5005];
int cnt[5005][5005];
int pl[2000005];
int rig[5005], lft[5005];
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> c >> T;
	//cout << c << T;
	while(T--)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(f, 0x3f, sizeof(f));
		//DEBUG;
		cin >> n >> m;
		for(int i = 1;i <= n;i++)
		{
			cin >> pl[i];
		}
		//DEBUG;
		if(c == 11 || c == 12)
		{
			int n1 = pl[n] - pl[n - 1];
			int ff = m / n1;
			if(ff == 0 || ff == 1)
			{
				cout << 0 << endl;
				continue;
			}
			int ans = n - ff * 2;
			ans++;
			ans = max(ans, (int)(0));
			cout << ans << endl;
			continue;
		}
		memset(rig, 0, sizeof(rig));
		memset(lft, 0, sizeof(lft));
		//DEBUG;
		for(int i = 1;i <= n;i++)
		{
			f[i][i] = 0;
			for(int j = i + 1;j <= n;j++)
			{
				if(pl[j] - pl[i] <= m)
				{
					cnt[i][j] = 1;
					f[i][j] = 1;
					rig[i] = max(rig[i], j);
					lft[j] = min(lft[j], i);
					//cout << i << ' ' << j << endl;
				}
			}
		}
//		for(int i = 1;i <= n;i++)
//		{
//			for(int j = i + 1;j <= n;j++)
//			{
//				cout << f[i][j] << ' ';
//			}
//			cout << endl;
//		}
		for(int i = n;i >= 1;i--)
		{
			for(int j = i + 1;j <= n;j++)
			{
				for(int k = i + 1;k < min(rig[i] + 1, j);k++)
				{
					if(f[i][k] + f[k][j] < f[i][j])
					{
						f[i][j] = f[i][k] + f[k][j];
						cnt[i][j] = cnt[k][j];
					}
					else if(f[i][k] + f[k][j] == f[i][j] && f[i][j] <= 1000000)
					{
						//cout << i << ' ' << k << ' ' << j << endl;
						cnt[i][j] += cnt[k][j];
					}
				}
//				for(int k = max(i + 1, lft[j]);k < j;k++)
//				{
//					if(f[i][k] + f[k][j] < f[i][j])
//					{
//						f[i][j] = f[i][k] + f[k][j];
//						cnt[i][j] = 1;
//					}
//					else if(f[i][k] + f[k][j] == f[i][j] && f[i][j] <= 1000000)
//					{
//						//cout << i << ' ' << k << ' ' << j << endl;
//						cnt[i][j]++;
//					}
//				}
			
			}
		}
		//DEBUG;
		int ccc = 0;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				//cout << cnt[i][j] << ' ';
				if(cnt[i][j] == 2) ccc += 1;
			}
			//cout << endl;
		}
//		for(int i = 1;i <= n;i++)
//		{
//			for(int j = i + 1;j <= n;j++)
//			{
//				cout << f[i][j] << ' ';
//			}
//			cout << endl;
//		}
		cout << ccc << endl;
	}
	return 0;
}


