#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,l,r,f;
long long a[500005];
long long tot(long long x)
{
	long long tmp=m,res=0;
	f=1;
	for(int i=n;i>=1;i--)
	{
		if(a[i]>x)continue;
		tmp-=x-a[i];
		if(tmp<0)
		{
			f=0;
			res--;
			return res;
		}
	}
	return res;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf(" %d",&a[i]);
	cout<<111;
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r)
	{
		long long mid=(l+r)/2;
		long long s=tot(a[mid]);
		if(s>ans)
		{
			ans=s;
			if(ans==n)break;
			if(f==1)l=mid+1;
			else r=mid-1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}