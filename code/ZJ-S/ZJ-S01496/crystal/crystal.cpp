#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010],sum[500010];
bool check(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		if(a[i]*mid-(sum[i]-sum[i-mid])<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=0,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}