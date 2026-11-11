#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vel;
typedef string sig;
ll n,m;
vel v;
bool check(ll x){
	ll sum=0;
	for(int i=1;i<x;i++){
		sum+=v[x]-v[i];
	}
	if(sum<=m)return 1;
	for(int i=x+1;i<=n;i++){
		sum+=(x-1)*(v[i]-v[i-1]);
		sum-=v[i]-v[i-x+1];
		if(sum<=m)return 1;
	}
	return 0;
}
void slv(){
	cin>>n>>m;
	v=vel(n+3);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v.begin()+1,v.begin()+1+n);
	ll l=2,r=n,ans=1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll T=1;
//	cin>>T;
	while(T--){
		slv();
	}
	return 0;
}