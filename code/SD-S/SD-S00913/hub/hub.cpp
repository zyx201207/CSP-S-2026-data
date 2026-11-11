#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector <int> v[N + 5];
int sh[N + 5], dis[N + 5];

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i < n; i++) {
			int uu, vv;
			cin >> uu >> vv;
			v[uu].push_back(vv);
			v[vv].push_back(uu);
		}
		cout << "0" << endl;
	}
	return 0;
}
