#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long MAXN=5e5+5;
long long n;
long long a[MAXN];
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=1,maxnn=0,stpos=0,ma=0;
	bool fl=0;
	for(long long i=2;i<=n;i++)
	{
		long long subn=a[i]-a[i-1];
		if(fl==0)
		{
			if(a[i+1]-a[i]>=a[i]-a[i-1])
			{
				fl=1;
				stpos=i;
			}
			else continue;
		}
		if(a[i]==a[i-1])
		{
			ans++;
			continue;
		}
		if(maxnn+subn*(i-stpos+1)>m)
		{
			ma=a[i-1];
			break;
		}
		else
		{
			ans++;
			maxnn+=subn*(i-stpos+1);
		}
	}
	m-=maxnn;
	for(int i=stpos;i>=1;i--)
	{
		if(ma-a[i]<=m)
		{
			ans++;
			m-=ma-a[i];
		}
	}
	cout<<ans;
	return 0;
}
