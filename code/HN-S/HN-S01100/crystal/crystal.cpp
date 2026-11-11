#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, ans;
long long m;
long long a[N], diff[N];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++)
	{
		diff[i] = a[i] - a[i - 1];
	} 
	long long k = 0;
	for(int i = 1, j = 1; i <= n;)
	{
		if(k > m)
		{
			ans = max(i - j, ans);
			k -= a[i] - a[j];
			j ++;
			continue;
		}
		if(diff[i + 1] * (i + 1 - j) > m)
		{
			ans = max(i - j + 1, ans);
			k -= a[i] - a[j];
			j ++;
			continue;
		}
		i ++;
		k += diff[i] * (i - j);
	}
	cout << ans;
	return 0;
}
