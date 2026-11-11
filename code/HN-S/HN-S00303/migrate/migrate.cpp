#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int N = 2e6 + 10;
int n, x[N], d, c, t, f[N], ans;
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		ans = 0;
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> x[i];
		for(int i = 1; i <= n; i ++)
		{
			memset(f, 0, sizeof f);
			int j;
			for(j = i; j <= n; j ++)
			{
				if(x[j] - x[i] > d) break;
				f[j] = 1;
			}
			for(; j <= n; j ++)
			{
				int minn = INF, cnt = 0;
				for(int k = 1; x[j] - x[j - k] <= d; k ++)
				{
					if(f[j - k] < minn)
					{
						minn = f[j - k];
						cnt = 1;
					}else if(f[j - k] == minn) cnt ++;
				}
				f[j] = minn + 1;
				if(cnt == 2) ans ++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

