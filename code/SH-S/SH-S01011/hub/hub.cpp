#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+10;
int c,T,g[N];
void solve(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
//		g[u].push_back(v);
//		g[v].push_back(u);
	}
	cout<<2*n-k<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
