#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> e[maxn];
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--) {
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) {
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
	return 0;
}
