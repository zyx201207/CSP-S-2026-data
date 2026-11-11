#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 3e5 + 5;
int n, m;
int card[maxn];
int tot[maxm], t[maxm];
int table[maxn];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> card[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		memset(t, 0, sizeof(t));
		memset(table, 0, sizeof(table));
		int len = 0;
		for (int j = i; j <= n; ++j)
		{
			if (!t[card[j]])
			{
				t[card[j]] = j;
				table[++len] = card[j];
			}
			else
			{
				for (int k = len; k > t[card[j]]; --k)
				{
					table[k] = 0;
				}
				len = t[card[j]] - i + 1;
			}
		}
		for (int j = 1; j <= len; ++j)
		{
			tot[table[j]]++;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		cout << tot[i] << " ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
fuck.
*/
// ¹Ø×¢Sourceless482Ð»Ð»ß÷
