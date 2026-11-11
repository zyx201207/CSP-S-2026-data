#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	    cin >> a[i];
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			for(int k = n - 1; k > j; k--)
				if(a[k] == a[j])
				{
					j = k;
					break;
				}
			cnt[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++)
		cout << cnt[i] << ' ';
	return 0;
}