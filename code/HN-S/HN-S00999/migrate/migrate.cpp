#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000005];
int farest[2000005];
int dis[5005][5005];
int cnt[5005][5005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		for(int i = 1;i <= n;i++)
		{
			farest[i] = upper_bound(x+1,x+n+1,x[i]+d)-x-1;
		}
		for(int i = 1;i <= n;i++)
		{
			dis[i][i] = 0;
			cnt[i][i] = 1;
		}
		int ans = 0;
		for(int j = 2;j <= n;j++)
		{
			for(int i = j-1;i >= 1;i--)
			{
				if(i == farest[i])
				{
					dis[i][j] = 1e18;
					cnt[i][j] = 0;
					continue;
				}
				dis[i][j] = dis[farest[i]][j]+1;
				cnt[i][j] = 0;
				for(int k = min(farest[i],j);k > i;k--)
				{
					if(dis[k][j] == dis[farest[i]][j])cnt[i][j] += cnt[k][j];
					else break;
				}
				ans += (cnt[i][j] == 2); 
			}
		}
//		for(int i = 1;i < n;i++)
//		{
//			for(int j = i+1;j <= n;j++)
//			{
//				cout << dis[i][j] << " ";
//			}
//			cout << "\n";
//		}
//		for(int i = 1;i < n;i++)
//		{
//			for(int j = i+1;j <= n;j++)
//			{
//				cout << cnt[i][j] << " ";
//			}
//			cout << "\n";
//		}
		cout << ans << "\n";
	}
	return 0;
}
/*
1 2 3 4
*/
