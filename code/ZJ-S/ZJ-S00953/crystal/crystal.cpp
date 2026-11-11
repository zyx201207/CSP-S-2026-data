#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500007],s[500007];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		s[i] = s[i-1]+a[i];
	}
	int l = 1,r = n;
	while(l <= r)
	{
		int mid = (l+r)/2;
		long long mn = 2e18;
		for(int i = mid;i <= n;i++)
		{
			mn = min(a[i]*mid-(s[i]-s[i-mid]),mn);
		}
		if(mn <= m)l = mid+1;
		else r = mid-1;
	}
	cout << r;
}
