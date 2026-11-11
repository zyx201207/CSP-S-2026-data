#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long
#define N (int)(5e5 + 10)

ll n, m, a[N];

bool check(int mid)
{
	ll cnt = 0;
	for(int i = 1; i < mid; i++)
		cnt += a[mid] - a[i];
	if(cnt <= m)
		return true;
	for(int i = mid + 1; i <= n; i++)
	{
		cnt -= a[i - 1] - a[i - mid];
		cnt += (mid - 1) * (a[i] - a[i - 1]);
		if(cnt <= m)
			return true;
	}
	return false;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	ll l = 1, r = n, mid;

	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(check(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}

	cout << l - 1;
	
	return 0;
}
