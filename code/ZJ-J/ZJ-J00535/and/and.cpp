#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int a[N];
int n,m;
long long maxx=-1;
long long ans;
long long f[N];
int maxxx=-1;
void run1(int lo,int isp,long long shu)
{
	if(lo>n)
	{
		ans=max(ans,shu);
		return ;
	}
	if(isp>m)
	{
		ans=max(ans,shu);
		return ;
	}
	if(n-lo+1<=m-isp)
	{
		for(int i=lo;i<=n;i++)
		{
			shu=shu&a[i];
		}
		ans=max(ans,shu);
		return ;
	}
	if(isp==0)
	{
		run1(lo+1,isp+1,a[lo]);
		run1(lo+1,isp,shu);
	}
	else{
		if(shu<shu&a[lo])
		{
			run1(lo+1,isp+1,shu&a[lo]);
		}else{
			run1(lo+1,isp+1,shu&a[lo]);
			run1(lo+1,isp,shu);
		}
	}
}
void run()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxxx=max(maxxx,a[i]);
	}
	if(m==1)
	{
		cout<<maxxx;
		return ;
	}
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return ;
	}
	if(maxxx<=4)
	{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return ;
	}
	if(n<=2000)
	{
		run1(1,0,0);
		cout<<ans;
		return ;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return ;
	}
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	run();
	return 0;
}