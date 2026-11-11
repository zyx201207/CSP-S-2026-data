#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long a[500005];
long long lef=-10e13,righ=10e13;
long long as;

bool check(long long x)
{
	long long cnt=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x)
		{
			continue;
		}
		
		if(cnt+(x-a[i])<=m)
		{
			ans++;
		}
		cnt+=(x-a[i]);
	}
	as=max(as,ans);
	if(cnt>m)
	{
		return false;
	}
	if(cnt<=m)
	{
		return true;
	}
}



int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long mid=0;
	while(lef+1<righ)
	{
		mid=(lef+righ)/2;
		if(check(mid))
		{
			lef=mid;
		}
		else
		{
			righ=mid-1;
		}
		//cerr<<"    "<<lef<<"   "<<righ<<"\n";
	}
	for(int i=1;i<=n;i++) 
	{
		if(a[i]==lef)
		{
			as++;
		}
	}
	cout<<as;
	return 0;
} 