#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>

using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N],pre[N];
bool check(int mid)
{
	for(int i=mid;i<=n;i++)
	{
		ll sum=pre[i]-pre[i-mid];
		ll qw=a[i]*(ll)mid;
		ll cz=qw-sum;
		if(cz<=m)return true;
	}
	return false;
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}


