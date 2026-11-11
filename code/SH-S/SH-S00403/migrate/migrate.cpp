#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct status {
	int step; ll pos;
};

void F1() {
	ll n, d;
	cin >> n >> d;
	vector<ll> x(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	
	int ans = 0;
	queue<status> q;
	q.push({0, 1});
	int layer = 0;
	vector<int> vis(n + 1);

	while(!q.empty()) {
		status cur = q.front(); q.pop();
		int step = cur.step;
		ll pos = cur.pos;
		if(step > layer) {
			for(int j = 1; j <= n; j++) {
				if(vis[j] == 2) {
					ans++;
				}
			}
			
			layer++;
			vis.assign(n + 1, 0);
		}
		vis[pos]++;
		for(
			int j = pos + 1;
			j <= n && x[j] - x[pos] <= d;
			j++
		) {
			q.push({step + 1, j});
		}
	}
	cout << ans << '\n';
}

void FA() {
	
}

void FB() {
	
}

void FC() {
	
}

void F2() {
	
}

int main() {
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	
	while(t--) {
		if(c == 0) {
			F1();
		}
		if(1 <= c && c <= 10) {
			F1();
		}
		if(11 <= c && c <= 12) {
			FA();
		}
		if(13 <= c && c <= 14) {
			FB();
		}
		if(15 <= c && c <= 18) {
			FC();
		}
		if(19 <= c && c <= 25) {
			F2();
		}
	}
	
	
	return 0;
} 
