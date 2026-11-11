#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[5005],s[5005][5005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			s[i][j]=a[j]-a[i];
		}
	}
	long long maxx=0;
	for(long long i=1;i<=n;i++)
	{
		long long sum=0,ans=0;
		for(long long j=1;j<=n;j++)
		{
			if(s[i][j]>0) break;
			sum-=s[i][j];
			ans++;
			if(sum>m)
			{
				ans--;
				sum+=s[i][j];
				break;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
