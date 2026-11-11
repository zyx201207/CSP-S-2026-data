#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n;
long long m;
long long a[MAXN];
long long sum[MAXN];
bool check(int x)
{
	for(int i = x; i<=n; i++)
	{
		long long tmp1 = sum[i]-sum[i-x];
		long long tmp2 = a[i]*x;
		long long tmp3 = tmp2-tmp1;
		if(tmp3<=m)
		{
			return true;
		}
	}
	return false;
}
int solve(int l, int r)
{
	int res = 1;
	while(l<=r)
	{
		int mid = (l+r)>>1;
		if(check(mid))
		{
			res = mid;
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1; i<=n; i++)
	{
		sum[i] = sum[i-1]+a[i];
	}
	cout<<solve(0,n);
	return 0;
}
