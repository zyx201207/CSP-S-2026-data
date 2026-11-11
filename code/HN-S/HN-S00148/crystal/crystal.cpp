#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;
	cin>>n>>m;
	long long  a[n+5];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<n-2;i++)
		{
			if((a[i]+a[i+1]+m)%a[i+2]==0)
			{
				a[i]=a[i+2];
				a[i+1]=a[i+2];
				ans+=3;
				break;
			}
		}
	for(int i=2;i<n-1;i++)
	{
		if(a[i]==a[i+1])
		{
			ans++;
		}
	}
	if(ans==0)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i+1]-a[i]<=m)
			{
				ans+=2;
				m-=a[i+1]-a[i];
			}
		}
	}
	cout<<ans;
	return 0;
 } 
