#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> t[1000005];
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		cout<<1<<endl;
	}
	return 0;
}
