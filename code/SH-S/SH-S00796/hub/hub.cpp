#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
vector<int> edg[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edg[u].push_back(v);
			edg[v].push_back(u);
		}
	}
	return 0;
} 
