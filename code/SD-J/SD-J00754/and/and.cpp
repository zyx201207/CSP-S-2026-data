#include<bits/stdc++.h>
using namespace std;


long long a[200000];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int set=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	if(m==2){
	

	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++){
			ans=max(a[i]&a[j],ans);
		}
		set=1;
	}}
	long long k=a[1];
	long long y=a[2];
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans=k&a[i];
			long long p=k&a[i];
			k=p;
		}
		set=1;
	}
	if(m==1)
	{
		set=1;
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,a[i]);
		}
	}
	if(m==n-1)
	{
		set=1;
		for(int i=1;i<=n;i++)
		{
			long long ans1=0;
			for(int j=1;j<=n ;j++)
			{
				if(j==i)continue;
				if(i==1){
				ans1=y&a[j];
				long long p=y&a[j];
				y=p;
			}
			ans=max(ans,ans1);
		}
	}
}
	if(set==0)
	{
		for(int i=n;i>=n-m+1;i--)
		{
			ans=a[i];
		}
	}
cout<<ans;
	return 0;
}

