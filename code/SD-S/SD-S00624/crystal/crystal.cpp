#include <bits/stdc++.h>
using namespace std;
long long a[500010] , d[500010] , b[500010] , n , m , minn = 1e9 , xx = 1;
bool check(long long x)
{
	for(long long i = 2; i <= n; i++)
	{
		long long cnt = 0 , cot = 1;
		for(int j = i;  j <= n; j++)
		{
			cnt += d[j] * cot;
			cot++;
			if(cnt > m) return 0;
			if(cot == x) return 1;
		}
	}
}
int main ()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];	
	}
	sort(a + 1 , a + n + 1);
	for(long long i = 2; i <= n; i++)
	{
		d[i] = abs(a[i] - a[i - 1]);
		
	}
	for(long long i = 3; i <= n; i++)
	{
		if(d[i] != d[i - 1]) xx = 0;
	}
	if(xx == 1)
	{
		long long ans = 1 , cnt = 0;
		for(long long i = 2; i <= n; i++)
		{
			cnt = d[i] * ans;
			ans++;
			if(cnt == n)
			{
				break;
			}
		}
		cout << ans - 1;
		return 0;
	}
	long long l = 1 , r = n;
	while(l < r)
	{
		long long mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}

