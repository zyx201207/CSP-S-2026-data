#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans;
long long m,a[N],cha[N];
bool check(int mid)
{
	for(int i=2;i<=n-mid+1;i++)
	{
		long long sum=0;
		for(int j=0;j<mid;j++)
		{
			sum+=cha[i+j]*(j+1);
			if(sum>m or sum<0)break;
		}
		if(sum<=m and sum>=0)return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)cha[i]=a[i]-a[i-1];
		int l=0,r=n-1;
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
		cout<<ans+1;
	}
	else
	{
		cin>>a[1]>>a[2];
		long long t=m/abs(a[2]-a[1]),sum=0,k=1;
		while(1)
		{
			sum+=k;
			if(sum>t)break;
			k++;
		}
		cout<<k;
	}
	return 0;
}
