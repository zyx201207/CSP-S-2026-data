#include<bits/stdc++.h>
using namespace std;
long long a[500005]={0};
long long n;
long long m;
long long ans(long long x)
{
	long long k=m;
	long long s=0;
	for(long long i=x;i>=1;i--)
	{
		k-=a[x]-a[i];
		if(k<0) break;
		s++;
	}
	return s;
}
int main()
{
	long long cnt=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++)
	{
		if(cnt<ans(i))
		{
			cnt=ans(i);
		}
	}
	cout<<cnt;
	return 0;
}
