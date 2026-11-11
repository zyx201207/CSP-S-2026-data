#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, summ, f[33];
bool fl;
struct S
{
	int aa;
	bool b = 0;
};
S a[200005];
bool cmp(S x, S y)
{
	return x.aa > y.aa;
}
signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].aa;
	}
	f[0] = 0;
	for (int i = 1, j = 2; i <= 32; i++, j *= 2)
	{
		f[i] = j;
	}
	sort(a + 1, a + n + 1, cmp); 
	int i;
	for (i = 1; i <= m; )
	{
		fl = 0;
		for (int j = 1; j <= 32; j++)
		{
			if (a[i].aa == f[j]) 
			{
				fl = 1;
				a[i].b = 1;
			}
			if (a[i].aa + a[i - 1].aa + 1 == f[i] && i != 1 && !a[i - 1].b)
			{
				fl = 1;
			}
		}
		if (fl) continue;
		else
		{
			i++;
		}
	}
	cout << a[i].aa;
//	for (int i = 1; i <= n; i++)
//	{
//		cout << a[i] << " ";
//	}
	return 0;
 } 
