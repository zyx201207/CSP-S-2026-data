#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=-1,go,sum[2000005],k;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==n)
	{
		go=a[1];
		for(int i=2;i<=n;i++)
		{
			go=go&a[i];
		}
		cout<<go;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum[++k]=a[i]&a[j];
			}
		}
		for(int i=1;i<=k;i++)
		{
			maxn=max(maxn,sum[i]);
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
