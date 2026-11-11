#include <iostream>
#include <vector>
#define maxn 2000100
using namespace std;
int c,t;
int n,k;
vector<int> adj[maxn];
int main() {
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	
}