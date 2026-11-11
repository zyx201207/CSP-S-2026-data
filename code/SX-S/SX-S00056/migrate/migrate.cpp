#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

struct Node {
	int v, s;
};
ifstream fin;
ofstream fout;
const int N = 2e6 + 10;

int n, d;
vector<int> g[N];
int x[N];

void add(int a, int b) {
	g[a].push_back(b);
//	g[b].push_back(a);
}
void print() {
	for (int i = 1; i <= n; ++i) {
		cout << i << ": ";
		for (int j : g[i]) {
			cout << j << " ";
		}
		cout << endl;
	}
}

void clean() {
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
	}
	cout << endl;
}

int find(int u, int v) {
	queue<Node> q;
	q.push({u, 0});
	int s = 0;
	while (q.size()) {
		Node node = q.front();
		if (node.v == v) {
			s = node.s;
			break;
		}
		q.pop();
		for (int j : g[node.v]) {
			q.push({j, node.s + 1});
		}
	}
	int ans = 0;
	while (q.size()) {
		if (q.front().v == v && q.front().s == s) ans ++;
		q.pop();
	}
	return ans;
}

void solve() {
	fin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		fin >> x[i];
	}
	for (int i = 1, j; i <= n; ++i) {
		j = i + 1;
		while (j <= n && x[i] + d >= x[j]) {
			add(i, j);
			j++;
		}
	}
	int ans = 0;
	for (int l = 1; l <= n; ++l) {
		for (int r = l + 1; r <= n; ++r) {
			int num = find(l, r);
			if (num == 2) {
				ans++;
			}
		}
	}
	fout << ans << endl;
	clean();
}

void solve1() {
	fin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		fin >> x[i];
	}
	int ans = 0;
	int cha = x[2] - x[1];
	int p = d / cha * cha + (d / cha - 1) * cha;
	for (int i = 1; i <= n; ++i) {
		if (x[i] + p <= x[n]) {
			ans ++;
		}
	}
	fout << ans << endl;
	clean();
}
void solve2() {
	fin >> n >> d;
	for (int i = 1; i <= n; ++i) {
		fin >> x[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (x[i] - x[0] <= d && x[n] - x[i] <= d) {
			int flag = i;
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (x[n] - x[flag - 1] > d && x[flag + 1] - x[1] <= d && x[flag + 2] - x[1] > d) ans++;
		if (x[n] - x[flag - 1] <= d && x[flag + 1] - x[1] > d && x[n] - x[flag - 2] > d) ans++;
	}
	fout << ans << endl;
	clean();
}

int main() {
	fin.open("migrate.in");
	fout.open("migrate.out");
	
	int c, t;
	fin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			solve1();
		}
		return 0;
	}
	if (c == 13 || c == 14) {
		while (t--) {
			solve2();
		}
		return 0;
	}
	while (t--) {
		solve();
	}
	
	fin.close();
	fout.close();
	return 0;
}
