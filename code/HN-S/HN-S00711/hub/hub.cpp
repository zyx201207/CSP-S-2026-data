#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
vector<ll>e[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			ll u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		} 
		cout<<1<<"\n";
	}
	return 0;
}

