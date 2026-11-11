#include<bits/stdc++.h>
#define int long long
#define mid (l+r>>1)
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N],maxx;
int erf(int l,int r,int k)
{
	while(l<r)
	{
		if(a[k]*(k-mid)-(sum[k-1]-sum[mid-1])<=m) r=mid;
		else l=mid+1;
	}
	return k-l+1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
		maxx=max(maxx,erf(1,i,i));
	cout<<maxx;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

*/
