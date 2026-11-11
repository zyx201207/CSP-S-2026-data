#include<bits/stdc++.h>
using namespace std;
int c, t, n, d, a[200006];
vector<int> edge[200006];
queue<int> qu;
int dl[500005], vis[500005];
void spfa(int n, int s) {
	for (int i = 1; i <= n; i++) {
		dl[i] = 0x3f;
	}
	vis[s] = 1;
	dl[s] = 0;
	while (qu.size()) {
		int x = qu.front();
		qu.pop();
		vis[x] = 0;
		for (auto al : edge[x]) {
			int y = al, wl = abs(a[x] - a[y]);
			if (dl[y] > dl[x] + wl) {
				dl[y] = dl[x] + wl;
				if (!vis[y]) {
					qu.push(y);
					vis[y] = 1;
				}
			}
		}
	}
}
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; aj++) {
				if (abs(a[i] - a[j]) <= d) {
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			
			cout << spfa(i)
		}
	}
	return 0;
}