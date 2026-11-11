#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a[200086];
	long long sum = 0, num = 0, q = 1, w = 1;
	char c[200086];
	string s1, s2;
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		cin >> c[i];
	}while(q < (n+1-w))
	{
		if(c[q] != c[n + 1 - w])
		{
			num += min(a[n + 1 - w], a[q]);
		}a[q] -= min(a[n + 1 - w], a[q]);
		a[n + 1 - w] -= min(a[n + 1 - w], a[q]);
		if(a[q] <= 0)
		{
			q++;
		}if(a[n + 1 - w] <= 0)
		{
			w++;
		}
	}cout << num;
	return 0;
}
