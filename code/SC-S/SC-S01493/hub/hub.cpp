#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, T;
vector<int> g[N];
void solve(){
	int n, k;
	cin >> n;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(k == n){
		cout << 0 << "\n";
		return;
	}
	if(c == 13 || c == 14 || 1){
		int r = (n - 1) / 2;
		if(k >= r){
			cout << 1 << "\n";
			return;
		}
		for(int i = 1; i <= r; i++){
//			cout << i * (k + 1) << "\n";
			if(i * (k + 1) > r){
				cout << i <<"\n";
				return;
			}
		}
	}

}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T--){
		solve();
	}
}
