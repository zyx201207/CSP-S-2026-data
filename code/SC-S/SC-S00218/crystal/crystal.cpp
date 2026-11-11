#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5;
ll n,m,a[N],ans;
ll sum[N];
bool check(int x)
{
	for(int i=1;i+x-1<=n;i++)
	{
		int t=x*a[i+x-1]-(sum[i+x-1]-sum[i-1]);
		if(t<=m)return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=a[i]+sum[i-1];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}