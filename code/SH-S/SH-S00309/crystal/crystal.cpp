#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int n, m, a[500005];
bool check(int mid)
{
	int now = 0;
	for(int i = n; i >= n-mid+1; i--) now += a[n]-a[i];
	for(int i = n-mid; i >= 1; i--) 
	{
		now -= mid*(a[i+mid]-a[i+mid-1]), now += a[i+mid-1]-a[i];
		if(now <= m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int l = 1, r = n;
	sort(a+1, a+n+1);
	while(l < r)
	{
		int mid = l+r+1>>1;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout << l;
} 
