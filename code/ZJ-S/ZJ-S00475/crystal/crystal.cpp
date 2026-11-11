#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long t[500010];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		int k=(t[i]-t[i-x+1])-(a[i]-a[i-x+1])*(i-x);
		if(k<=m)
			return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		t[i]=t[i-1]+(a[i]-a[i-1])*(i-1);
	int l=1,r=n;
	int ans=1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}

