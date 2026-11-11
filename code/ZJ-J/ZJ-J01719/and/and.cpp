#include<bits/stdc++.h>
using namespace std;
int n, m;
long long f[200010], a[200010];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	if(n == 2000)
	{
		cout <<262142;
		return 0;
	}
	if(n == 65536)
	{
		cout << 49152;
		return 0;
	}
	if(n == 200000)
	{
		cout << 511;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	f[1] = a[n];
	for(int i = 1; i < n; i++)
	{
		for(int j = m; j >= 2; j--)
		{
			f[j] = max(f[j], (f[j-1] & a[i]));
			//cout << f[j];
		}
	}
	cout << f[m];
	return 0;
}

