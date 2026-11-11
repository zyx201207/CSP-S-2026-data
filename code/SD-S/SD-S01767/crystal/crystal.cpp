#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,s;
	cin>>a>>s;
	long long q[a+10],sum[a+10];
	sum[0]=0;
	bool bjh=0;
	for(int i=1;i<=a;i++)
	{
		cin>>q[i];
		if(q[i]>N)
		{
			bjh=1;
		}
	}
	if(bjh==1)
	{
		sort(q+1,q+a+1);
		for(long long i=2;i<=a;i++)
		{
			long long l;
			l=((q[i]-q[1])+(q[i]-q[i-1]))*i/2;
			if(l>s)cout<<i-1;
		}
	}
	sort(q+1,q+a+1);
	for(int i=1;i<=a;i++)
	{
		sum[i]=sum[i-1]+q[i];
	}
	for(long long i=1;i<=a;i++)
	{
		if(q[i]*(i-1)>sum[i]+s-q[i])
		{
			cout<<i-1;
			return 0;
		}
	}
	cout<<a;
	return 0;
}
