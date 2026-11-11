#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],n,m;
bool check(int x)
{
	int res=0;
	for(int i=1;i<x;i++) res+=a[x]-a[i];
	if(res<=m) return 1;
	for(int i=x+1;i<=n;i++)
	{
		res+=x*(a[i]-a[i-1]);
		res-=a[i]-a[i-x];
		if(res<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}