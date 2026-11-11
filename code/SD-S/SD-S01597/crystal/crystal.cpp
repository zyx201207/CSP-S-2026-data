#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],p[N];
bool check(int mid)
{
	for(int i=1;i<=n-mid;++i) if(mid*a[i+mid-1]-(p[i+mid-1]-p[i-1])<=m) return 1;
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) p[i]=p[i-1]+a[i];
	int l=1,r=n+1;
	while(l+1<r)
	{
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;

	return 0;
}

