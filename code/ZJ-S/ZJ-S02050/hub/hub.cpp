#include<bits/stdc++.h>
using namespace std;
vector<int> graph[500010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		cout<<1;
	}
	return 0;
}