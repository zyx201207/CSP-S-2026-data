#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,t,n,k,ans;
vector<int>g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int u,v;
			g[u].push_back(v);
			g[v].push_back(u);
			ans=max(u-v/2,ans);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
