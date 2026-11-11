#include <bits/stdc++.h>

using namespace std;

int n, k;

vector<int> t[1000006];
void add(int u, int v) {
	t[u].push_back(v);
	t[v].push_back(u);
}

void clear() {
	for (int i = 0; i <= n; i++) {
		t[i].clear();
	}
}

int sz[1000006];
void dfs1(int p, int fa) {
	sz[p] = 1;
	for (int c : t[p]) {
		if (c == fa) continue;
		dfs(c, p);
		sz[p] += sz[c];
	}
}

int d1[1000006];
int d2[1000006];
int dup[1000006];
int part[1000006];

void dfs3(int p, int fa, int pt) {
	part[p] = pt;
	d1[p] = 0;
	d2[p] = 0;
	for (int c : t[p]) {
		if (c == fa) continue;
		dfs3(c, p);
		if (d1[c] + 1 >= d1[p]) {
			d2[p] = d1[p];
			d1[p] = d1[c] + 1
		}
	}
	dup[p] = max(dup[fa], d1[fa]);
}

int cen[2];

struct Pt{
	int v;
	int d;
	bool operator < (Pt x) {
		return x.d < 
	}
};
priority_queue<Pt> pq;

void dfs2(int p, int fa) {
	if (p != 1) {
		dfs3(p, fa, 0);
		int tmp = dup[p];
		dup[p] = 0;
		dfs3(fa, p, 1);
		dup[p] = tmp;
		
		for (int i = 1; i <= n; i++) {
			if (d1[i] + max(dup[i], d2[i]) > d1[cen[part[i]]] + max(dup[cen[part[i]]], d2[cen[part[i]]])) {
				cen[part[i]] = i;
			}
		}
		
		
	}
	
	for (int c : t[p]) {
		if (c == fa) continue;
		dfs2(c, p);
	}
}

void solve() {
	cin >> n >> k;
	clear();
	
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c, t;
	cin >> c >> t;
	
	for (int i = 0; i < t; i++) {
		solve();
	}
}
