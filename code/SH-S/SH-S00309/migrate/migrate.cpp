#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue> 
#define int long long
using namespace std;
int a[5005], f[5005], cnt[5005], n, m;
void func()
{
	cin >> n >> m;
	int ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		memset(f, 63, sizeof f);
		f[i] = 0;
		cnt[i] = 1;
		for(int j = i; j <= n; j++)
		{
			int p = upper_bound(a+1, a+n+1, a[j]+m)-a-1;
			for(int k = j+1; k <= p; k++)
			{
				if(f[k] > f[j]+1) f[k] = f[j]+1, cnt[k] = cnt[j];
				else if(f[k]==f[j]+1) cnt[k] += cnt[j];
			}
		}
//		for(int j = i; j <= n; j++) cout << cnt[j] << " ";
		for(int j = i; j <= n; j++) if(cnt[j] == 2) ans++;
//		cout << "\n";
	}
	cout << ans << "\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t;
	cin >> t >> t;
	while(t--) func();
}
