#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int c,T;
int n,k,a[N];
vector<int> G[N];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=1000000;i++) G[i].clear();
		for(int i=1;i<n;i++){
			int u,v; cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<ceil((n/2)*1.0/(k+1))<<"\n";
	}
	return 0;
}
