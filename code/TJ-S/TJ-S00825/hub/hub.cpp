#include<bits/stdc++.h>
using namespace std;
inline void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C,t;
	cin>>C>>t;
	while(t--){
		solve();
	}
	return 0;
}
//zsy
