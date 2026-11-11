#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], s[500005], cnt[300005], id[300005], top = 0;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		top = 0;
		for (int j = i; j <= n; j++)
		{
			for (int k = top; k >= 1; k--)
			{
				if (a[s[k]] == a[i]) top = k - 1;
			}
			s[++top] = i;
		}
		for (int j = 1; j <= top; j++)
		{
			cnt[a[s[j]]]++;
		}
	}
	for (int j = 1; j <= m; j++)
	{
		cout << cnt[j] << " ";
	}
	cout << endl;
	return 0;
}
