#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[1000001];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	if(n == 1)
	{
		cin >> n;
		return 0;
	}
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long t = abs(a[1] - a[2]);
	long long ans = 0;
	long long i = 0;
	while(m >= i)
	{
		m -= i;
		i+=t;
		ans++;
	}
	cout << ans;
	return 0;
}
