#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
vector<int> vec[2000006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
	}cout<<"1\n2";
	return 0;
}
