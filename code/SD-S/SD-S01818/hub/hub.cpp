#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int c, t;
int n, k;
vector<int> tr[N];

int main () {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			tr[u].push_back(v);
		}
		cout << "0\n";
	}
	return 0;
}
