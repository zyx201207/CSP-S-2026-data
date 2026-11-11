#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5e5 + 5;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;

static int n, m;
static long long a[N];
static long long pre[N];
static long long maxN = -INF;

static bool check(const long long len)
{
	int res = 0;
	for(int i = 1; i <= len; i++)
		res += pre[i];
	res -= len * (maxN - a[len + 1]);
	for(int i = len + 1; i < n; i++)
	{
		if(res <= m)
			return true;
		res += len * (maxN - a[i]);
		res -= len * (maxN - a[i + 1]);
		res -= pre[i - len];
		res += pre[i];
	}
	return res <= m;
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef DEBUG
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
#endif // DEBUG
#ifdef DEBUG
#endif // DEBUG
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxN = max(maxN, a[i]);
	}
	sort(a + 1, a + n + 1);
	for(long long i = 1; i < n; i++)
		pre[i] = maxN - a[i];
	long long l = 0, r = n - 1;
	long long ans = 1;
	while(l <= r)
	{
		long long mid = (l + r) >> 1;
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	cout << ans + 1 << '\n';

	return 0;
}

