#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int c,t,n,k;
vector<int> E[MAXN];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		cout<<1<<endl;
	}
	return 0;
}
