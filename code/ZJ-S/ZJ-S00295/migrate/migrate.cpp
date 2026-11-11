#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10,M=5e2+10;
ll n,m,k,ans;
ll a[N];
ll find(ll x,ll y){
	ll last=x,sum=0,op=0;
	for(ll i=x+1;i<=y;++i){
		if(a[i]-a[i-1]>k) return 0;
		if(a[i]-a[last]>k){
			last=i;
			++sum;
		}else op=1;
	}
	if(!op) return 0;
	return sum+1;
//	return ;
}
void solve(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<i;j++){
			ll tmp=find(j,i);
			ans+=(tmp!=0);
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>m>>m;
	while(m--){
		solve();
	}
	return 0;
}
/*
0 2 5 20 2 
4 1 9 2 5 
3 1 5 2 7 4 6 
3 2 3 3 4 5 7 
1 3 
1 2 

*/
