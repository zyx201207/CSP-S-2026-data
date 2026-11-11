# include<bits/stdc++.h>

using namespace std;

const long long N = 5e5 + 10;
long long a[N], s[N], res, n, m;

long long check(long long l, long long r)
{
	long long x = a[r] * (r - l + 1);
	long long y = s[r] - s[l - 1];
	return (x - y <= m);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i ++ ) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(long long i = 1;i <= n;i ++ ) s[i] = s[i - 1] + a[i];
	for(long long i = 1;i <= n;i ++ )
	{
		long long l = 1, r = i, ans = 0;
		while(l <= r)
		{
			long long mid = (l + r) >> 1;
			if(check(mid, i)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		if(ans) res = max(res, i - ans + 1);
	}
	
	cout << res;
	return 0;
}