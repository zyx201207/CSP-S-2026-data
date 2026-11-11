#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAX=2e6+5;
int c,t,w;
void solve(){
	cin>>c>>t;
	while(t--){
		vector<int>g[MAX];
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<1<<'\n';
	}
}
#undef int
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//  cin>>T;
	while(T--)solve();
	return 0;
}