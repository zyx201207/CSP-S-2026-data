#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,k,u,v,ans;
vector<int> g[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i) g[i].clear();
		for(int i=1;i<n;++i){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
