#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+9;
ll n,k;
vector<ll> to[N];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			to[u].push_back(v);
			to[v].push_back(u);
		}
		if()
	}
	dfs(1); 
	return 0;
}
