#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500005;
ll m,a[N],sum[N];
int n;
bool check(ll t){
	ll mn=0x3f3f3f3f3f3f3f3f;
	for(int i=t;i<=n;i++){
		ll u=a[i]*t-(sum[i]-sum[i-t]);
		mn=min(mn,u);
	}
	return mn<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	ll l=1,r=n,ans=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';

	return 0;
}
/*
Xterfusion
 
X X XXX

*/
