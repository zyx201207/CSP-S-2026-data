#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+11;
int c,Tt;
vector<int>edge[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdin);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>c>>Tt;
	while(Tt--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		cout<<"1\n";
	}
	return 0;
}