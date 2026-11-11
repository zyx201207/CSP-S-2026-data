#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],pre[N],ans;
bool check(ll x,ll pos){
	if(a[x]*(x-pos)-(pre[x]-pre[pos])<=m){
		ans=max(ans,x-pos);
		return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ll l=i,r=n;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid,i-1))l=mid+1;
			else r=mid-1;
		}
	}
	cout<<ans<<endl;
}
/*heiheihei I am going to finish it*/
