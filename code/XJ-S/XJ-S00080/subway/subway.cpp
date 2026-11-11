#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>w,a,t,x,y;
ll ss(ll zt){
	bool f=1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		ll t;
		cin>>t;
		w.push_back(t);
	}
	for(ll i=1;i<=n;i++){
		ll t1,t2;
		cin>>t1>>t2;
		a.push_back(t1);
		t.push_back(t2);
	}
	for(ll i=1;i<=q;i++){
		ll t1,t2;
		cin>>t1>>t2;
		x.push_back(t1);
		y.push_back(t2);
	}
	return 0;
}
