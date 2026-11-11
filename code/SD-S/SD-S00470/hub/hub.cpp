#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;

int n , k;
vector<int> edge[maxn + 5];

bool check(int x , int m) {
	int r = m - 2 * x - k;
	return r / 2 <= x;
}

inline void solveA() {
	scanf ("%d%d" , &n , &k);
	for (int i = 1; i <= n; i++)
		edge[i].clear();
	for (int i = 1; i < n; i++) {
		int u , v;
		scanf ("%d%d" , &u , &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int m = n / 2;
	if (k == n) {
		puts("0");
		return ;
	}
	if (k >= m) {
		puts("1");
		return ;
	}
	int l = 0 , r = n;
	while (l < r - 1) {
		int mid = l + r >> 1;
		if (check(mid , m)) r = mid;
		else l = mid;
	}
	printf ("%d\n" , r + 1);
}

inline void solve() {
	scanf ("%d%d" , &n , &k);
	for (int i = 1; i <= n; i++)
		edge[i].clear();
	for (int i = 1; i < n; i++) {
		int u , v;
		scanf ("%d%d" , &u , &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	if (k == n) puts("0");
	else puts("1");
}

int main() {
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	int c , t;
	scanf ("%d%d" , &c , &t);
	while (t--)
		if (c == 13 || c == 14) solveA();
		else solve();
}
