#include<bits/stdc++.h>
using namespace std;
const int N=2e6+2;
int c,t,n,k,u,v;
vector<int> g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			
		}
	}
	return 0;
}
