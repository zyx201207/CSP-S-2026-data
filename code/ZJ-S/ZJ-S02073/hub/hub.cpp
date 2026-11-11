#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int n, k;
vector<int> tre[N];
pair<int, int> ind[N];

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first > b.first;
}

int main() {
//	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++) ind[i].second = i;
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			tre[u].push_back(v);
			tre[v].push_back(u);
			ind[u].first++;
			ind[v].first++;
		}
		sort(ind+1, ind+n+1, cmp);
		for(int i = 1; i <= n; i++) {
			cout << ind[i].second << " " << ind[i].first << endl;
		}
	}
	return 0;
}
