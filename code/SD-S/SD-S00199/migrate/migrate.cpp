#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5010;
int a[N];
int f[N][N],ff[N][N],cnt[N][N];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while (t--)
	{
		int n,d;cin>>n>>d;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++) f[i][j] = 0x3f3f3f3f3f3f3f3f,ff[i][j] = 0x3f3f3f3f3f3f3f3f,cnt[i][j] = 1;
		for (int i = 1;i <= n;i++) cin>>a[i];
		for (int i = 1;i < n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				if(a[j]-a[i] > d) break;
				f[i][j] = f[j][i] = a[j]-a[i];
			}
		}
		
		for (int k = 1;k <= n;k++)
		{
			for (int i = 1;i <= n;i++)
			{
				for (int j = 1;j <= n;j++)
				{
					f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
		
		for (int k = 1;k <= n;k++)
		{
			for (int i = 1;i <= n;i++)
			{
				for (int j = 1;j <= n;j++)
				{
					if(ff[i][j] == 0x3f3f3f3f3f3f3f3f) continue;
					if(ff[i][j] == ff[i][k]+f[k][j] && ff[i][j] == f[i][j]) cnt[i][j]++;
					ff[i][j] = min(ff[i][j],ff[i][k]+ff[k][j]);
				}
			}
		}
		
//		for (int i = 1;i <= n;i++)
//		{
//			for (int j = 1;j <= n;j++)
//			{
//				cout<<cnt[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
			
		
		int ans = 0;
		for (int i = 1;i < n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				if(cnt[i][j] == 2) ans++;
			}
		}
			
				
		cout<<ans<<'\n';
	}
	return 0;
}
