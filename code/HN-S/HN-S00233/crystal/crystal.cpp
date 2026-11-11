#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[500005],b[500005],sum,ans,maxx=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=i)
			f=1;
	}
	
	if(f==0)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(sum<=m&&sum+i>m)
			{
				cout<<(i-1);
				return 0;
			}
			sum+=i;
		}
	}
	
	sort(a+1,a+n+1);
	for(int i=a[1];i<=a[n];i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]<=i)
				b[j]=(i-a[j]);
			else
				b[j]=1e18;
		}
		sort(b+1,b+n+1);
		int sum=0,ans=0;
		for(int j=1;j<=n;j++)
		{
			if(sum+b[j]>m)
				break;
			sum+=b[j];
			ans++;
		}
		for(int j=1;j<=n;j++)
			b[j]=0;
		maxx=max(maxx,ans);
	}
	cout<<maxx;
 } 
