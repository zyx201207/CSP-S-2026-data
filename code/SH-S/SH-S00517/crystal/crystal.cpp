#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m;
int a[500005];
int sum[500005];
bool check(int x)
{
	for (int i=1;i<=n-x+1;i++)
	{
		if (x*a[i+x-1]-(sum[i+x-1]-sum[i-1])<=m)	return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while (l<r)
	{
		int mid=(l+r+1)/2;
		if (check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}

