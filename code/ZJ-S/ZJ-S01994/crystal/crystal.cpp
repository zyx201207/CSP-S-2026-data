#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],cf[500005],hz[500005],pre[500005];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		ll now=pre[i]-pre[i-x]-x*hz[i];
		if(now<=m)return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)cf[i]=a[i]-a[i-1];
	for(int i=n-1;i>=1;i--)hz[i]=hz[i+1]+cf[i+1];
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+hz[i];
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
