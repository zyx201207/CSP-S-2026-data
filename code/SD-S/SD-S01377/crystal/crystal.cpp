#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int N=5e5;
int n;
int l,r;
ll m,a[N+5];
ll sum[N+5];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(a[i]*x-(sum[i]-sum[i-x])<=m)return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l<<"\n";
	return 0;
}
