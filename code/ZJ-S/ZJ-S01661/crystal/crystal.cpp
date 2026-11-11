#include<bits/stdc++.h>
#define ll long long
#define db double
const int N=1e6+10,inf=0x3f3f3f3f;
using namespace std;
ll n,m,a[N],sum[N],maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[n]-a[i];
	for(ll i=1;i<=n;i++)
	{
		ll l=1,r=i;
		while(l<r)
		{
			int mid=l+r>>1;
			if(sum[i-1]-sum[mid-1]-(a[n]-a[i])*(i-mid)<=m)
				r=mid;
			else
				l=mid+1;
		}
		maxn=max(maxn,i-l+1);
	}
	/*for(int i=1;i<=n;i++)*/
	cout<<maxn;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
