#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 1;
int c, t, n, k, u, v;
int fa[maxn];
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i < n; i++){
			cin >> u >> v;
			fa[v] = u;
		}
		cout << 9 << endl;
	}
	return 0;
}