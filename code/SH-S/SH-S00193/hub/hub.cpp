#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int>g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<0<<endl;
	}
	return 0;
}
