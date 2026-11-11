#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
long long sum[N];
long long ans;
bool check(long long r,long long len)
{
	long long s1=a[r]*len;
	long long s2=sum[r]-sum[r-len];
	long long d=s1-s2;
	return m>=d;
}
void bs(long long q)
{
	long long l=1,r=q;
	while(l<=r)
	{
		long long mid=l+r>>1;
		if(check(q,mid))
		{
			ans=max(ans,mid);
			l=mid+1;
			//cout<<mid<<endl;
		}
		else r=mid-1;
	}
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal3.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(long long i=1;i<=n;i++) bs(i);
	cout<<ans;
	return 0;
} 
