#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[5000005],pre[5000005];
bool check(ll l,ll r){
	ll res=a[r]*(r-l+1)-(pre[r]-pre[l-1]);
	return res<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll l=0,r=i;
		while(l+1<r){
			ll mid=(l+r)/2;
			if(check(mid,i)){
				r=mid;
			}else{
				l=mid;
			}
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<"\n";
	return 0;
}
