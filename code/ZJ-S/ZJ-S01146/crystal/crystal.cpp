#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],pre[N],ans,m,n;
bool check(ll x,ll y){
	if((y-x+1)*a[y]-pre[y]+pre[x-1]<=m){
		ans=max(ans,y-x+1);
		return 1;
	}else{
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	for(ll i=1;i<=n;i++){
		ll l=1,r=i;
		if(check(1,i)){
			ans=max(ans,i);
			continue;
		}
		while(l<r){
			ll mid=(l+r)/2;
			if(check(mid,i))r=mid-1;
			else l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}