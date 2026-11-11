#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5;
ll n,m;
ll a[N];
ll pre[N];
ll ans;
bool check(ll x){
	for(ll i=1;i<=n-x+1;i++) if(a[i+x-1]*x-pre[i+x-1]+pre[i-1]<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	ll l=1,r=n,mid;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)) ans=max(ans,mid),l=mid+1;
		else r=mid-1; 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//5 8 -3 -1 2 2 7
//4
