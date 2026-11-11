#include<bits/stdc++.h>
using ll=long long;
using namespace std;

const int maxn=5e5+10;

ll n,m,a[maxn],sum[maxn],cost;

bool check(ll i,ll x)
{
	if(x*a[i]-(sum[i-1]-sum[i-x-1])<=m)return 1;
	return 0;
}

int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	ll ans=0;
//	for(int i=1;i<=n;i++)cout<<sum[i]<<endl;
	for(int i=2;i<=n;i++)  
	{
		ll lid=1,rid=i-1,anss=1;
		while(lid<=rid)
		{
			int mid=(lid+rid)>>1;
			if(check(i,mid))anss=mid,lid=mid+1;
			else rid=mid-1;
//			if(i==4)
//			{
//				cout<<lid<<" "<<rid<<" "<<mid<<" "<<(i*a[mid]-sum[i-1]+sum[i-mid-1])<<" "<<i-1<<" "<<i-mid<<" "<<check(i,mid)<<" "<<endl;
//			}
		}
//		cout<<i<<" "<<anss<<endl;
		ans=max(ans,anss+1);
	}
	cout<<ans;
	return 0;
}
