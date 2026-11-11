#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[N], b[N], cnt[N], ans[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++) cnt[j] = 0;
		int L = 0;
		for(int j = i;j <= n;j++)
		{
			int x = a[j];
			if(cnt[x] != 0)
			{
				int t = cnt[x] - 1;
				for(int k = cnt[x];k <= L;k++) cnt[b[k]] = 0;
				L = t;
			}
			L++, cnt[x] = L, b[L] = x;
		}
		for(int j = 1;j <= m;j++)
		{
			if(cnt[j] != 0) ans[j]++;
		}
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
