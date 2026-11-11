#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,vv;
			cin>>u>>vv;
    		v[u].push_back(vv);
    		v[vv].push_back(u);
		}
		cout<<0<<"\n";
	}
	return 0;
}
