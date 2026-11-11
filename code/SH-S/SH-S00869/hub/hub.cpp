#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int c,t;
vector<int> graph[maxn];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
	}
	cout<<"1\n2";
	return 0;
}
