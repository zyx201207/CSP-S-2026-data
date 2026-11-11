#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n , m , a[N] , ans;
int pre[N];
int sumv(int l , int r)
{
	return pre[r] - pre[l - 1];
}
int check(int l , int r)
{
	return a[r] * (r - l + 1) - sumv(l , r);
}
signed main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for(int i = 1;i <= n;i ++)
	{
		pre[i] = pre[i - 1] + a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		int l = 1 , r = i;
		while(l < r)
		{
			int mid = (l + r) / 2;
			if(check(mid , i) <= m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans , i - l + 1);
	}
	cout << ans;
    return 0;
}
//Expected 100pts
//mondayrain
//sfdsdgdsgfsdfg
