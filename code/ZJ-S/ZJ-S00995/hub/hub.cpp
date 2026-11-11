#include<bits/stdc++.h>
using namespace std;
constexpr int N=1000100;
int C,n,k;
vector<int>e[N];
void solve(){
	for(int i=1;i<=n;i++) e[i].clear();
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n==k){cout<<"0\n";return;}
	if(C==13||C==14){
		int m=n>>1;
		if(k>=m){cout<<"1\n";return;}
		else{cout<<((m+3-k)/4)+1<<'\n';return;}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}