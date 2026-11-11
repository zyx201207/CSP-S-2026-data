#include<bits/stdc++.h>
using namespace std;

long long a[500005], ct[300003];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) //第几局游戏 
	{
		bool ok[300003] = {false};
		int where[300003]; 
		for (int j = i; j < n; j++)
		{
			if (!ok[a[j]])
			{
				ok[a[j]] = true;
				where[a[j]] = j;
			}
				
			else
			{
				for (int k = where[a[j]]; k < j; k++) //该牌右边的所有牌清空 
					ok[a[k]] = false;
				ok[a[j]] = true;
				where[a[j]] = j;
			}
		} 
		for (int j = 1; j <= m; j++)
		{
			if (ok[j])
				ct[j]++;
		}
	}
	for (int j = 1; j <= m; j++)
		cout << ct[j] << " ";
	return 0;
} 
