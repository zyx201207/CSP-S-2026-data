#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5, NX = 3e5;
int a[MX + 10], cnt[NX + 10], t[NX + 10];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, i, j;
	cin >> n >> m;
	for (i = 1; i <= n; i ++ )
	{
		cin >> a[i];
		t[a[i]] = i;
	}
	for (i = 1; i <= n; i ++ )
	{
		for (j = i; j <= n; j = t[a[j]] + 1)
		{
			cnt[a[j]] ++ ;
		}
	}
	for (i = 1; i <= m; i ++ )
	{
		cout << cnt[i] << ' ';
	}
	cout << '\n';
	return 0;
}
