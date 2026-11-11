#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long

const int N = 5e5 + 5;
int n , m , a[N] , lst[N] , d[N];
int cnt[N] , ans[N];
vector <int> edges[N];
queue <int> q;

inline void Toposort() {
	for (int i = 1;i <= n;i++) cnt[i] = 1;
	for (int i = 1;i <= n;i++) if (!d[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : edges[u]) {
			cnt[v] += cnt[u];
			if (!(--d[v])) q.push(v);
		}
	}
}

int main () {
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	scanf ("%d%d" , &n , &m);
	for (int i = 1;i <= n;i++) scanf ("%d" , &a[i]);
	for (int i = n;i >= 1;i--) {
		lst[a[i]] = max(lst[a[i]] , i);
		if (lst[a[i]] == n) continue;
		edges[i].push_back(lst[a[i]] + 1) , d[lst[a[i]] + 1]++;
	}
	Toposort();
	for (int i = 1;i <= n;i++) ans[a[i]] += cnt[i];
	for (int i = 1;i <= m;i++) printf ("%d " , ans[i]);
	printf ("\n");
}