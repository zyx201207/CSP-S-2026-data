//高一轩 SN-S00455 交大附中 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool check(long long x)
{
	long long sum=m;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x)
		{
			sum-=(x-a[i]); 
		}
		if(sum<0) return false;
	}
	if(sum>=0)
	{
		return true;
	}
	else return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long l=-1000000000000,r=1000000000000;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		//l=min(l,a[i]);
		//r=max(r,a[i]);
	}
	long long mid=(l+r)/2,t=0;
	while(l<r)
	{
		//cout<<l<<" "<<r<<endl;
		mid=(l+r)/2;
		//cout<<l<<" "<<r<<endl;
		bool flag=check(mid);
		if(flag==true)
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	if(l>mid) t=r;
	else if(r<mid) t=l;
	else t=mid;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=t)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
