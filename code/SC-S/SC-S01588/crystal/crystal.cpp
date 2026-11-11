#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,sum[N],ans;
bool check(int len)
{
	for(int i=len;i<=n;i++)
	{
		int k=a[i]*len-(sum[i]-sum[i-len]);
		if(k<=m)return 1;
	}
	return 0;
}
main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=a[i]+sum[i-1];
	}
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid;
		}
	}
	cout<<ans;
	return 0;
}//不要挂分口也