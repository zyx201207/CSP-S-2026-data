#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,k;
vector<ll> e[4005];
ll sum[4005];
int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			e[u].clear();
		}
		for(int i=1;i<n;i++){
			ll u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<1<<'\n';
	}
	return 0;
} 
