#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m;

int a[N], b[N], fa[N];
int cnt[N];

int find(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		fa[i] = i;
		
		if (b[a[i]])
			fa[b[a[i]]] = i;
		b[a[i]] = i;
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			cnt[a[j]]++;
			j = find(j);
		}
	}
	
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
	
	return 0;
}