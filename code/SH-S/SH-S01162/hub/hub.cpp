#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF=1e18;
const ll luck=INF;

void solve(){
	ll n,s;
	cin>>n>>s;
	vector<ll> g[n];
	for (ll i=1;i<n;i++){
		ll p1,p2;
		cin>>p1>>p2;
		g[p1].push_back(p2);
		g[p2].push_back(p1);
	}//ll p[100];
	cout<<n/s/2+((n/s)%2!=0)<<"\n";
	return ;
}

int main(){
	//cout<<"HelloWorld!";
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,q;
	cin>>c>>q;
	while (q--){
		solve();
	}
	
	return 0;
}
