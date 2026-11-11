#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005], m, sum[500005];
bool check(int x)
{
	for(int i = x; i <= n; i++)
	{
		long long tmp = sum[i] - sum[i - x];
		if(a[i] <= (m + tmp) / x)return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)sum[i] = a[i] + sum[i - 1];
	int l = 1, r = n;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(check(mid))l = mid + 1;
		else r = mid - 1;
	}
	cout << r;
	return 0;
}
