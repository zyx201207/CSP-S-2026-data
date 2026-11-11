#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, a[N], ans;
bool vis[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 29; i >= 0; i --)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j ++)
		{
			if(vis[j]) continue;
			cnt += ((a[j] >> i) & 1);
		}
		if(cnt >= m)
		{
			ans |= (1 << i);
			for(int j = 1; j <= n; j ++)
			{
				if(!((a[j] >> i) & 1))
					vis[j] = 1;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
