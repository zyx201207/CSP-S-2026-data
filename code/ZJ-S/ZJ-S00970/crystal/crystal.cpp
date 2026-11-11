#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[int(5e5) + 5], sum[int(5e5) + 5], ans;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) 
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(a[i] * (i - 1) - sum[i - 1] > m)
		{
			cout << i - 1;
			return 0;
		}
	}
	
	return 0;
}

