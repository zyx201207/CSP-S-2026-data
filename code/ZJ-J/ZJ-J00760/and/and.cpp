#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 30;i >= 0;i--)
	{
		int qz = 1 << i;
		int gs = 0;
		for(int j = 1;j <= n;j++)
		{
			gs += ((qz & a[j]) == qz);
		}
		if (gs < m) continue;
		for(int j = 1;j <= n;j++)
		{
			if((qz & a[j]) != qz) a[j] = 0;
		}
		a[0] += qz;
	}
	cout << a[0];
	return 0;
}