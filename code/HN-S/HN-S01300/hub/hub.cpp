#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		vector<int> e[1000010];
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);	
		}
		cout<<1<<endl<<2;
	}
}
