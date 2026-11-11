#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

int __c, T;
int n, k;
vector<int> e[N];
int d[N];
queue<int> q;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &__c, &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if (k == n) {
			puts("1");
		} else if (k == n-1) {
			puts("2");
		} else if (k == 2) {
			for (int i = 1; i <= n; i++)
				d[i] = -1;
			q.push(1);
			d[1] = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v : e[u]) {
					if (d[v] == -1) {
						d[v] = d[u]+1;
						q.push(v);
					}
				}
			}
			int maxx = 0, id = -1;
			for (int i = 1; i <= n; i++)
				if (d[i] > maxx) {
					maxx = d[i];
					id = i;
				}
			// ---
			for (int i = 1; i <= n; i++)
				d[i] = -1;
			q.push(id);
			d[id] = 0;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v : e[u]) {
					if (d[v] == -1) {
						d[v] = d[u]+1;
						q.push(v);
					}
				}
			}
			maxx = 0;
			for (int i = 1; i <= n; i++)
				if (d[i] > maxx)
					maxx = d[i];
			for (int i = 1; i <= n; i++)
				printf("%d ", d[i]);
			puts("");
			printf("%d\n", maxx);
		}
	}
}