#include <bits/stdc++.h>
using namespace std;
const int MAXN=55;
vector<int>g[MAXN];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
	}
	return 0;
}