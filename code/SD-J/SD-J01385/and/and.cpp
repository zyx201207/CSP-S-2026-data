#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10; 

int n,m;
int a[N];


signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	if(m==1)
	{
		int maxx=-2147483647;
		for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,a[i]);
		}
		printf("%d",maxx);
		return 0;
	}
	if(m==n)
	{
		int ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		printf("%d",ans);
		return 0;
	}
	if(m==n-1)
	{
		int ans1=a[1];
		for(int i=2;i<=n-1;i++)
		{
			ans1=ans1&a[i];
		}
		int ans2=a[2];
		for(int i=3;i<=n;i++)
		{
			ans2=ans2&a[i];
		}
		int ans=max(ans1,ans2);
		printf("%d",ans);
		return 0;
	}
	if(m==2)
	{
		int maxx=-2147483647;
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		printf("%d",maxx);
		return 0;
	}
	
	int maxx=-2147483647;
	for(int i=1;i<=n-m;i++)
	{
		for(int j=i+1;j<=n-m;j++)
		{
			int cans=a[1];
			for(int k=j;k<=m;k++)
			{
				cans=cans&a[k];
			}
			maxx=max(maxx,cans);
		}
	}
	printf("%d",maxx);
	return 0;
}
