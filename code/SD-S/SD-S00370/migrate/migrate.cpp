#include<bits/stdc++.h>
using namespace std;
int c, t, n;
long long d, x[4005];
long long f[4005][4005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		long long ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i++)cin >> x[i];
		for(int i = 1; i <= n; i++)
		{
			//int ans = 0;
			memset(f, 0, sizeof(f));
			f[i][0] = 1;
			for(int j = i + 1; j <= n; j++)
			{
				for(int k = 1; k <= j - i; k++)
				{
					for(int l = j - 1; l >= i; l--)
						if(x[j] - x[l] > d)break;
						else f[j][k] += f[l][k - 1];
				}
				for(int k = 1; k <= j - i; k++)
				{
					if(f[j][k])
					{
						if(f[j][k] == 2)ans++;
						break;
					}
				}
			}
		} 
		cout << ans << '\n';
	}
}
