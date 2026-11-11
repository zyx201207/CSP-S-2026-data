#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c,t,n,k,u,v;
vector<int> g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		g.clear();
		for(int i = 1;i < n;++i){
			cin >> u >> v;
			g[u].psuh_back(v);
		}
		
	}
}
