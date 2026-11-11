#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int c, t, n, d;
int a[N];
vector <int, int> g[N];



void solve1() {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (abs(a[i] - a[j]) >= d) {
				g[i].push_pack(j);
				g[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (j == i) {
				continue;
			}
			q.
		}
	}
}

void S() {
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i<= n; i++) {
			cin >> a[i];
		}
		solve1();
	}
	
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	S();
	
	return 0;
}
