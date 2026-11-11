#include<bits/stdc++.h>
#define AC return 0
using namespace std;
using ll=long long;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);cout.tie(0);
	ll n,m;cin>>n>>m;vector<ll>a(n+1);
	bool t1=true,t2=true;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]+1)t1=false;
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])t2=false;
		}
	}if(t1){
		for(ll i=1;i<=n;i++){
			if(((1+i-1)*(i-1)/2)<=m);
			else return cout<<i-1,0;
		}
	}else cout<<a[n>>1];
	AC;
}