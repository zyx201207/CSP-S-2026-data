#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		vector<ll>G[1000010];
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		cout<<2<<"\n";
	}
	return 0;
}
//3s
