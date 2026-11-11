#include<bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005], f[300005];
int s[500005], top = 0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	for (int i = n; i >= 1; i--)
	{
		top++;
		s[top] = a[i];
		if (f[a[i]] == 0)
			f[a[i]] = top;
		int j = top;
		while (j > 0)
		{
			ans[s[j]]++;
			if (f[s[j]] == j) j--;
			else j = f[s[j]] - 1;
		}
		
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", ans[i]);
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/