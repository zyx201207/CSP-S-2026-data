#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[2000005],tong[2000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long maxx=-1e9;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	if((a[n]-a[1])*n<m)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++) maxx=max(maxx,a[i]-a[i-1]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[i]-a[j]>m||a[i]-a[j]==maxx) continue;
			if(a[j]<=a[i]&&m-(a[i]-a[j])>=0)
			{
				m-=a[i]-a[j];
				a[j]=a[i];
			}
		}
	}
	long long ans=-1e9;
	for(int i=1;i<=n;i++)
	{
		tong[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,tong[i]);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
6 7
-3 -9 1 1 2 3
*/
