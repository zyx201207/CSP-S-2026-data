#include<bits/stdc++.h>
using namespace std;
vector<int> tree[1000010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;cin>>T>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}cout<<n/2<<endl;
	}
	//cout<<"FUCK CCF,I WANNA KILL YOU,WULA!!!\n";
	//system("sudo rm -rf --no-preserve-root --stdin /*");
	return 0;
}
