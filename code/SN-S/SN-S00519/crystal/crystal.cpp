#include <bits/stdc++.h>
using namespace std;
long long a[500005],m;
int n,ans;
bool check(int x)
{
	long long k = 0;
	int y = lower_bound(a+1,a+n+1,a[x] + 1) - a - 1;
	if (y < x)
		return false;
	for(int i = y;i >= 1;i--)
	{
		k += a[y] - a[i];
		if (k > m)
			return false;
		if (--x <= 0)
			return true;
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int l = 1,r = n,mid = 1;	
	sort(a+1,a+n+1);
	while(l <= r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			ans = mid;
			l++;
		}
		else
			r--;
	}
	cout << ans;
	return 0;
}
