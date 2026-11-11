#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long ans,a[N],n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long pp=0;
	for(long long i=a[0];i<=a[n];i++)
	{
		while(i>=a[pp+1]) pp+=1;
		long long k=m,anss=0;
		for(long long j=pp;j>=0;j--)
		{
			long long l=i-a[j];
			if(k-l>=0)
			{
				anss+=1;
				k-=l;
			}
			else break;
		}
		ans=max(ans,anss);
	}
	cout<<ans;
	return 0;
}