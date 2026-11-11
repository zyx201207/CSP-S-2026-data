#include <bits/stdc++.h>
using namespace std;

vector<long long> to[2000005];

int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while (t--){
		long long n, k;
		cin >> n >> k;
		for (int i = 1; i <= n - 1; ++i){
			long long u, v;
			cin >> u >> v;
			to[u].push_back(v);
		}
	}
	return 0;
}
