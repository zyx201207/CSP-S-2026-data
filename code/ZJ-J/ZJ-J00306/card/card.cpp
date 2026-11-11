#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], f[500005], c[300005];
vector<int> b[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m, f[1] = 1;
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[a[i]].push_back(i);
	if(b[a[1]].back() == 1) c[a[1]]++;
	for(int i = 2; i <= n; i++)
	{
		f[i] = 1;
		if(b[a[i - 1]].back() == i - 1)
			f[i] += f[i - 1];
		if(b[a[i]].back() == i)
		{
			for(int j = 0; b[a[i]][j] < i; j++)
				f[i] += f[b[a[i]][j]];
			c[a[i]] += f[i];
		}
	}
	for(int i = 1; i <= m; i++)
		printf("%d ", c[i]);
	return 0;
}
