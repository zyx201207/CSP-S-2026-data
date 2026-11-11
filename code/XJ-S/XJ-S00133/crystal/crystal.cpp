#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long d[500005];
long long c,b=1,ans;
long long shu[500005],nin,shi[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			b++;
		}
		else
		{
			ans=max(ans,b);
			b=1;
		}
		
		d[i]=d[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(long long i=n;i>=1;i--)
	{
		if(d[i]<=m)
		{
			ans=max(i,ans);
			nin=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		shu[i]=1;
 	}
 	
	for(long long i=n;i>nin;i--)
	{
		shu[i]+=shu[i+1]-2;
		shi[i]=shi[i+1]-(a[i+1]-a[i])*(shu[i+1]-1);
		if(i==n)
		{
			shi[i]=0;
			shu[i]=1;
		}
		for(long long j=i-shu[i];j>=1;j--)
		{
			shi[i]+=a[i]-a[j];
			if(shi[i]==m)
			{
				shu[i]++;
				break;
			}
			if(shi[i]>m)
			{
				shi[i]-=a[i]-a[j];
				break;
			}
			
			shu[i]++;
		}
		ans=max(shu[i],ans);
	}
	cout<<ans;
	return 0;
 } 
