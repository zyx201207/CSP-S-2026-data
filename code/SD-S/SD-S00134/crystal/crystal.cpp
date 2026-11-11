#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 86;
ll n , m , a[N] , sum[N] , l = 1 , r , ans , tot; 
bool check(ll op)
{
	for (int i = op - 1;i <= n - 1;i ++)
	{
		tot = sum[i] - sum[i - op + 1];
		if((op - 1) * a[i + 1] - tot <= m)
		{
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1);
	for (int i = 1;i <= n;i ++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	r = n;
	while (l <= r)
	{
		ll mid = l + r >> 1;
		if (check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}


