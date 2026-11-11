#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T,n,k;
vector<int> G[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if(k==n){
			cout<<0<<"\n";
		}else{
			int x=(n+1)/2;
			cout<<(x-1)/(k-1)<<"\n";
		}
	}
	return 0;
}
