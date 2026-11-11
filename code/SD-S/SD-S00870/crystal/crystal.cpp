#include<bits/stdc++.h>
using namespace std;

const int N=5e5;
long long a[N+5];
long long n,m;
bool check(long long mid)
{
	for(long long i=1;i<=n-mid+1;i++)
	{
		long long sum=0;
		for(long long j=i;j<=i+mid-1;j++)
		{
			sum+=a[i+mid-1]-a[j];
			if(sum>m) break; 
		}
		if(sum<=m) return true;
	}
	return false;
}
bool check1(long long mid)
{
	if((a[mid]-a[1])*mid/2<=m) return true;
	return false;
}
int main()
{	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long d=a[2]-a[1];
	bool flag=true;
	for(long long i=3;i<=n;i++)
	{
		if(a[i]-a[i-1]!=d)
		{
			flag=false;
			break;
		}
	}
	if(flag)
	{
		long long l=0,r=n+1;
		while(l<r-1)
		{
			long long mid=(l+r)>>1LL;
			if(check1(mid)) l=mid;
			else r=mid;
		}
		cout<<l<<endl;
		return 0; 
	}
	long long l=0,r=n+1;
	while(l<r-1)
	{
		long long mid=(l+r)>>1LL;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}
