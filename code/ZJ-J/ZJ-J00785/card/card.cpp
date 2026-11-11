#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5 + 5;
int a[N], c[N], d[N];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = 0;
		for (int j = i; j <= n; j++)
		{
			for (int k = 1; k <= ans; k++)
				if (c[k] == a[j])
				{
					for (int l = k; l <= ans; l++)
						c[l] = 0;
					ans = k - 1;
				}
			ans++; c[ans] = a[j];
		}
		for (int j = 1; j <= ans; j++)
			d[c[j]]++;
	}
	for (int i = 1; i <= m; i++)
		cout << d[i] << " ";
	cout << endl;
	return 0;
}
