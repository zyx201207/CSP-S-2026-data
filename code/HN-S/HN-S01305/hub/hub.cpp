#include<bits/stdc++.h>
using namespace std;
vector<int>E[2000005];
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
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
	}
	return 0;
} 
//
/*
oyy,zryqbfh~,rsjsnzhyfylp,o! 
*/
// 
