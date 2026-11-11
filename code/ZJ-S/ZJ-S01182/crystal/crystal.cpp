#include<bits/stdc++.h>
using namespace std;
long long a[500007];
long long ans=0;
long long n,m;	
int main()
{		                
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	bool f=1;
	for(int i=1;i<=n-3;i++)
	{
		if(a[i+1]-a[i]!=a[i+3]-a[i+2]) 
		{
			f=0;
			break;
		}
	}
	sort(a+1,a+n+1);
	if(f)
	{
		for(int i=n;i>=1;i--)
		{	
			if(m-(a[n]-a[i])<0) break;
			m-=a[n]-a[i];
			ans++;
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		long long ss=0;
		long long cnt=1;
		bool f=1;
		for(int j=i-1;j>=1;j--)
		{
			if(ss-a[j]+a[i]<=m) ss+=a[i]-a[j],cnt++;
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}