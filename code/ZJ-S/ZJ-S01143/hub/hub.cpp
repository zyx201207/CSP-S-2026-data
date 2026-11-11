#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005],sum[500005],b[500005],s[500005];//原数组，前缀和，差分数组，合并数组
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		s[i]=b[i]*(i-1)+s[i-1];
		sum[i]=sum[i-1]+a[i];
	}
	ll ans=0;
	for(ll l=1,r=2;l<n&&r<=n;){
		ll x=s[r]-(a[r]*(l-1)-sum[l-1]);
		if(x<=m){
			ans=max(ans,r-l+1);
			r++;
		}else l++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}