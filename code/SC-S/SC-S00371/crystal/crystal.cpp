#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define ll long long
int n,m;
ll ansx,ans;
ll a[maxn],b[maxn];
ll sum[maxn],sumx[maxn];
bool check(int l,int r)
{
	return sumx[r]-sumx[l]-(r-l)*sum[l]<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[n-i+1]=b[i];
	for(int i=2;i<=n;i++)
	{
//		cout<<a[i]<<" ";
		sum[i]=sum[i-1]+a[i-1]-a[i];
	}
	for(int i=1;i<=n;i++)sumx[i]=sumx[i-1]+sum[i];
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(i,mid))ansx=mid-i+1,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,ansx);
	}
	cout<<ans;
	return 0;
}