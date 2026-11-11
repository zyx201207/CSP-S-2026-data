#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int maxn = -1;
	int minn = 20000000000000;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		if (a[i] > maxn)
		{
			maxn = a[i];
		}
	}
	if (m == 1)
	{
		cout << maxn;
	}
	return 0;
} 
