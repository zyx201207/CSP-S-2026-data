#include<bits/stdc++.h>
using namespace std;
int a[500055];
int n,m,ans = 0;
bool check(int x)
{
	for(int i = x;i <= n;i++)
	{
		if(a[i]-a[i-x]+m >= x*(a[i]-a[i-1]))
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i <= n;i++)
	{
		a[i] += a[i-1];
	}
	int l = 1,r = n;
	while(l <= r)
	{
		int mid = (l+r)>>1;
		if(check(mid))
		{
			ans = mid;
			l = mid+1;
		}
		else
		{
			r = mid-1;
		}
	}
	cout << ans << "\n";
	return 0;
}//crystal
