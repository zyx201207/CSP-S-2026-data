#include<bits/stdc++.h>
using namespace std;
int a[200005];
int pre[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int mx=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i!=1) pre[i]=(pre[i-1]&a[i]);
		else pre[i]=a[i];
		mx=max(mx,a[i]);
	} 
	if(m==1)
	{
		cout<<mx<<"\n";
		return 0;
	}
	if(m==n)
	{
		cout<<pre[n];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans=max(ans,(1LL*a[i]&a[j]));
			}
		}
		cout<<ans<<"\n";
		return 0;
	}
	if(m==n-1)
	{
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j==1) cnt=a[1]; 
				if(i!=j) cnt=(cnt&a[j]);
			}
			ans=max(ans,cnt);
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int S=0;S<=(1<<n);S++)
	{
		long long cnt=0;
		int h=0;
		for(int i=0;i<n;i++)
		{
			if(h>=m) break;
			if((S>>i)&1)
			{
				if(h==0)
				{
					cnt=a[i+1];
				}
				else cnt=(cnt&a[i+1]);
				h++;
			} 
		}
		if(h==m) ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}