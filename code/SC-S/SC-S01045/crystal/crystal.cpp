#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6;
int a[N],n,m,b[N];
bool check(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		unsigned long long c=0;
		for(int j=i-1;j>=i-mid+1;j--)
		{
			c+=(a[i]-a[j]);
		}
		if(c<=m)
		{
			return true;
		}
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=l+((r-l)/2); 
		if(check(mid))
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}