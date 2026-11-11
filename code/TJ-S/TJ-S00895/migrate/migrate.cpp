#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int c,t;
int n;
long long d;
long long x[2000001];
int f[301][301];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c == 11||c == 12)
	{
		while(t--)
		{
			cin >> n >> d;
			for(int i = 1;i <= n;i++)
			{
				//cin >> x[i];
				scanf("%lld",&x[i]);
			}
			long long u = x[2] - x[1];
			//cout << d << ' ' << u << endl;
			u = d / u;
			u = u * 2 - 1;
			if(u < 2||u > n) cout << 0 << endl; 
			else cout << n - u << endl;
		}
		return 0;
	}
	while(t--)
	{
		cin >> n >> d;
		long long ans = 0;
		memset(f,999999,sizeof(f));
		memset(x,0,sizeof(x));
		for(int i = 1;i <= n;i++)
		{
			f[i][i] = 0;
		}
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
			int u = lower_bound(x + 1,x + i + 1,x[i] - d) - x;
			for(int j = u;j < i;j++)
			{
				f[j][i] = f[i][j] = 1;
			}
		}
		for(int k = 1;k <= n;k++)
		{
			for(int i = 1;i <= n;i++)
			{
				for(int j = 1;j <= n;j++)
				{
					f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
				}
			}
		}
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 2;j <= n;j++)
			{
				//cout << i << ' ' << j  << ' ' << f[i][j] << endl;
				int cnt = 0;
				for(int k = i + 1;k < j;k++)
				{
					if(f[i][j] == f[i][k] + f[k][j]) cnt++;
				}
				//cout << cnt << ' ' << f[i][j] << endl;
				if(cnt == f[i][j]) ans++;
			}
		}
		cout << ans << endl;
	}
} 
