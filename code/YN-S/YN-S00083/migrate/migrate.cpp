#include <bits/stdc++.h>
using namespace std;
vector<int>a[100001];
int x[100001];
int m[100001];
int cnt[100001];
void dfs(int t){
	if()
	for(auto i : a[t]){
		
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T, n, d;
	cin >> c >> T;
	for (int t = 0; t < T; t++) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			cin >> x[i];
			for (int j = i - 1; j >= 1; j--) {
				if (x[i] - x[j] > d)
					break;
				a[j].push_back(i);
			}
		}
		dfs(1,);
	}
	return 0;
}

