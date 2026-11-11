#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[200005];
bool vis[200005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 29; ~i; i--)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
			if(!vis[j] && (a[j] & 1 << i))
				cnt++;
		if(cnt >= m)
		{
			ans |= 1 << i;
			for(int j = 1; j <= n; j++)
				if(!(a[j] & 1 << i))
					vis[j] = 1;
		}
	}
	cout << ans;
	return 0;
}
