#include<bits/stdc++.h>
#define IO ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define ull unsigned long long
#define int long long
#define endl '\n'
using namespace std;
int n,k; 
int a[500010];
int f[500010];
bool check(int mid)
{
	int x=0;
	for(int i=mid;i<=n;i++)
	{
		x=a[i]*mid;
		if(x-f[i]+f[i-mid]<=k)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	IO;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+a[i];
	}
	int ans=1;
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout << ans;
	return 0;
}
//呃呃呃呃呃呃呃呃呃为什么是ABCDF，也是挂分了 ，J T1没过这把没了 
