#include <bits/stdc++.h>
using namespace std;
int pos[300000], a[500000], h[300000];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, top = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		memset(pos, -1, sizeof(pos));
		for (int j = i; j < n; j++)
		{
			if (pos[a[j]] == -1)
				pos[a[j]] = top++;
			else
			{
				for (int k = pos[a[j]] + 1; k < top; k++)
					pos[a[k]] = -1;
				top = pos[a[j]];
			}
		}
		for (int j = 1; j <= m; j++)
			h[j] += pos[j] > -1;
	}
	for (int i = 1; i <= m; i++)
		cout << h[i] << ' ';
}
