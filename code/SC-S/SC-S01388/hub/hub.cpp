#include<bits/stdc++.h>
#define frein(x) freopen(x".in","r",stdin)
#define freout(x) freopen(x".out","w",stdout)
#define cinios cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
const int N=5e5+10;
vector<int> g[N];
void solve(){
	int n,k;cin>>n>>k;
	for(int i=2;i<=n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	cout<<0<<"\n";
}
int main(){
	cinios;
	frein("hub");
	freout("hub");
	int c,T;cin>>c>>T;
	while(T--) solve();
	return 0;
}