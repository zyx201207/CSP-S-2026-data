#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
bool MP[10010][10010];
bool fun(ll t,ll mx,ll n,bool& m[10010][10010]){
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t,n,k,tmp1,tmp2;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;bool mp=MP;
		for(ll i=1;i<=n;i++){
			cin>>tmp1>>tmp2;
			mp[tmp1][tmp2]=1;mp[tmp2][tmp1]=1;
		}
		ll l=1,r=n,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(fun(mid,k,n,mp)){l=mid+1;}
			else r=mid-1;
		}
	}
	return 0;
}
