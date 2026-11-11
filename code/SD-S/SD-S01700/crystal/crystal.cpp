#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define int long long
int n, m, ans;
int l = 1;
int a[maxn], ch[maxn], he[maxn];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++)
		ch[i] = a[i] - a[i - 1];
	for (int i = 2; i <= n; i++)
		he[i] = he[i - 1] + ch[i];
	for (int r = 2; r <= n; r++)
	{
		int del = 0;
		for (int i = l; i <= r; i++)
			del += he[r] - he[i];
		if (del <= m)
			ans = max(ans, r - l + 1);
		else
		{
			while(del < m)
			{
				del = del - (he[r] - he[l]);
				l ++;
			}
		}	
	}
	cout << ans << endl;
	return 0;
}
