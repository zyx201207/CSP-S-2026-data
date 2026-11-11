#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
vector<int> walk;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
		
	cin >> c >> n >> m >> d >> q;
	
	walk.assign(m + 1);
	
	for (int i = 1; i <= m; i++) {
		cin >> walk[i];
	}
	
	
	
	return 0;
}
