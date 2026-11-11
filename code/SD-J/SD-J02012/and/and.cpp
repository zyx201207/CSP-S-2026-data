#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m;
const int N=2e5+10;
ll a[N];
void solve(){
	ll ans=0;
	for(int i=0; i<(1<<n); i++){
		ll t=(1<<n)-1;
		if(__builtin_popcount(i)!=m) continue;
		for(int j=0; j<n; j++){
			if((i>>j)&1){
				t=(t&a[j+1]);
			}
		}
		ans=max(ans,t);

	}
	cout<<ans;
	return;
}
bool cmp(int x, int y){
	return x>y;
}
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
//	if(n<=20){
//		solve();
//		return 0;
//	}
	if(m==n){
		ll ans=a[1];
		for(int i=2; i<=n; i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		ll ans=0;
		for(int i=1; i<=n; i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		ll ans=0;
		for(ll i=1; i<=n; i++){
			for(ll j=1; j<=n; j++){
				if(i==j) continue;
				ans=max(ans,(a[i]&a[j]) );
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,cmp);	
	int ans=a[1];
	for(int i=2; i<=m; i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

3 2
*/
