#include <bits/stdc++.h>
using namespace std;
int n,a[200009],x,y;
char c[200009];
long long sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
	}
	x = 1;
	y = n;
	while (x != y)
	{
		if (c[x] != c[y])
		{
			sum += min(a[x],a[y]);
		}
		a[x] = max(0,a[x] - a[y]);
		a[y] = max(0,a[y] - a[x]);
		if (a[x] == 0)
		{
			x++;
		}
		if (a[y] == 0)
		{
			y--;
		}
	}
	cout << sum;
	return 0;
}
