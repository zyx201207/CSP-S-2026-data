#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1000;
long long n,m;
long long a[N];
long long da[N];
long long qian[N];
long long ans;
bool cmp(long long x,long long y)
{
	return x<y;
}
bool check(long long k)
{
	long long ca=m;
	for(int l=1,r=k;r<=n;l++,r++)
	{
		if(qian[r]-qian[l-1]<=m)
		{
			return true;
		}
	}
	return false;
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
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i!=1)
		{
			qian[i]=qian[i-1]+(a[i]-a[i-1])*(i-1);
		}
	}
	
	long long l=1,r=n;
	while(l<=r)
	{
		long long mid=l+(r-l)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
 }

