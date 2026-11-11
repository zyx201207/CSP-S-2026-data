#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500510],aa,q[500510],qz[500510];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool b=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(i>1)q[i]=a[i]-a[i-1];
		qz[i]=q[i]+qz[i-1];
		if(i==2) aa=a[i]-a[i-1];
		if(i>2&&a[i]-a[i-1]!=aa) b=false;
	}
	if(b)
	{
		long long ans=1;
		for(int i=2;i<=n;i++)
		{
			if((a[i]-a[i-1])*ans<=m)
			{
				m-=(a[i]-a[i-1])*ans;
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	long long l=1,r=1,ma=0,cnt=0;
	while(r<=n&&l<=n)
	{
		while(r+1<=n&&q[r+1]*(r-l+1)+cnt<=m)
		{
			r++;
			cnt+=q[r]*(r-l);
			ma=max(ma,r-l+1);
		}
		cnt-=qz[r]-qz[l-1];
		l++;
	}
	cout<<ma;
	return 0;
}
