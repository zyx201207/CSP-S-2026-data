#include <bits/stdc++.h>
using namespace std;
char a[109009009],f[109009009];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b,e = 0,g = 0;
	char c;
	g = 0;
	cin >> n;
	for (int i = 0;i < n;i += 1)
	{
		cin >> b >> c;
		for (int d = e;d < b;d += 1)
		{
			a[d] = c;
		}
		e += b; 
	}
	for (int i = 0;i < e;i += 1)
	{
		f[i] = a[e - 1 - i];
	}
	for (int i = 0;i < e / 2;i += 1)
	{
		if (f[i] != a[i])
		{
			g += 1;
		}
		else
		{
			continue;
		}
	}
	cout << g;
	return 0;
}
