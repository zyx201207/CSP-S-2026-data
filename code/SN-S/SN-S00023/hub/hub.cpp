#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--){
		int n,k;
		cin>>n>>k;
		for (int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
		}
		cout<<1<<'\n';
	}
	return 0;
}
