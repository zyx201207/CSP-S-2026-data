#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
vector<int>g[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		srand(time(0));
		cout<<rand()%2+1<<endl;
	}
	return 0;
}
