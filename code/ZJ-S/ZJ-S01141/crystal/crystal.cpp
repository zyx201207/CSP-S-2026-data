#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m;
int n,ans;
vector<ll> a;
bool check(ll nd){
	ll tot=0;
	int cnt=0;
	for(ll i:a){
		if(i>nd) continue;
		tot+=nd-i;
		if(tot<=m) cnt++;
	}
	ans=max(ans,cnt);
	return tot<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	a.resize(n);
	for(ll &i:a) cin>>i;
	sort(a.begin(),a.end(),greater<ll>());
	ll l=a[n-1],r=a[0];
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	cout<<ans;
}