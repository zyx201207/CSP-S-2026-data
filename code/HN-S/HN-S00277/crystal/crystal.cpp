#include<bits/stdc++.h>
using namespace std;
long long n , m;
long long a[500010];
long long sum[500010];
long long ans = 1ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	sort(a+1 , a+n+1);
	for(long long i = 1;i <= n;++i)
	{
		sum[i] = sum[i-1] + a[i]; 
	}
	long long l = n;
	long long r = n;
//	long long ml , mr;
	while(l <= r && l >= 1)
	{
		if(a[r]*(r-l+1) - (sum[r]-sum[l-1]) <= m)
		{
//			if(r-l+1 >= ans)
//			{
//				ml = l;
//				mr = r;
//				ans = r-l+1;
//			}
			ans = max(ans , r-l+1);
			l--;
		}
		else
		{
			r--;
		}
	}
	cout << ans << '\n';
//	cout << ml << " " << mr << endl;
	
	return 0;
}
