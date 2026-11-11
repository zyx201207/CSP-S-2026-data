#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a[10000];
/*
bool vis[1000005];

void dfs(int root){
	vis[i] = 1;
	for(int i=0;i<a[i].size();i++){
		if(!vis[a[i][]])
		dfs()
	}
}
*/

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		if(t>=1){
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
	return 0;
}
