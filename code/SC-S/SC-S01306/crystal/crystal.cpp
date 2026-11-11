#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,a[N],ans,d[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=1,sum=0;
	while(r<=n)
	{
		while(l<=r)
		{
			while(r<n&&sum+(a[r+1]-a[r])*(r-l+1)<=m)
			{
				r++;
				sum+=(a[r]-a[r-1])*(r-l);
			}
//			cout<<l<<' '<<r<<' '<<sum<<'\n';
			ans=max(ans,r-l+1);
			sum-=a[r]-a[l];
			l++;
		}
		r=l;
	}
	cout<<ans;
	return 0;
}