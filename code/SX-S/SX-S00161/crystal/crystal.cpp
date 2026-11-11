#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
long long a[500005],s[500005];
int n;
long long m;
bool check(int x)
{
	long long minn=1e18;
	for(int i=x;i<=n;i++)
	{
		minn=min(minn,x*a[i]-s[i]+s[i-x]);
	}
	return minn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]+s[i-1];
	}
	int l=1,r=n,mid,ans=1;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}