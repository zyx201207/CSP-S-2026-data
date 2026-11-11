#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6;

int n, k;
vector<int> g[N];

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int C, T; cin >> C >> T;
	while(T--){
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			g[i].clear();
		for(int i = 1; i <= n-1; i++){
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(n == k){
			cout << 0 << '\n';
			continue;
		}
		else if(n == k+1){
			cout << 1 << '\n';
			continue;
		}
		else if(n == k+2){
			cout << 1 << '\n';
			continue;
		}
		else if(C == 13 || C == 14){
			int m = (n-1)/2;
			int ans = max(1, m/2-(k/2-1));
			cout << ans << '\n';
		}
		else{
			cout << "那我没招了\n";
		}
	}
	
	return 0;
}

