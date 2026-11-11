#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,a[500010],dis[500010],sum[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) dis[i]=a[n]-a[i];
	for(ll i=1;i<=n;i++) sum[i]=sum[i-1]+dis[i];
	ll p=1,ans=1;
	for(ll i=1;i<=n;i++){
		while(sum[i]-(i-p+1)*dis[i]-sum[p-1]>m) p++;
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
