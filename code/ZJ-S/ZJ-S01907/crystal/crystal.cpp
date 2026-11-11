#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005],s[500005];
int ans;
bool check(int mid)
{
	for(int i=1;i+mid-1<=n;i++)
	{
		long long sum=s[i+mid-1]-s[i-1],tem=a[i+mid-1]*mid;
		if(tem-sum<=m) 
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) 
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}