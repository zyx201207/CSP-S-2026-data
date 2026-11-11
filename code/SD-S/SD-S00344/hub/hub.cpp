#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,k;
void solve(){
	cin>>n>>k;
	vector<int>g[n+1];
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<k-1;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,te=1;
	cin>>c>>te;
	while(te--){
		solve();
	}
	return 0;
}
