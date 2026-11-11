# include <bits/stdc++.h>
# define ll long long
# define cps CLOCKS_PER_SEC
using namespace std;

ll read() {
	ll res = 0, f = 1;
	char ch;
	ch = getchar();
	while (!(ch <= '9' && ch >= '0')) {
		if (ch == '-') f = -1;
		ch = getchar();
	} 
	
	while (ch <= '9' && ch >= '0') {
		res = res * 10 + (ch - '0');
		ch = getchar();
	}
	return f * res;
} 

vector<pair<int, int>> e[1500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ll c = read(), n = read(), m = read(), d = read(), q = read();
	
	for (int i = 1; i <= m; i ++) {
		ll w = read()£»
		e[i + k].push_back({i + 2 * k, w});
		e[i + 2 * k].push_back({i + k, w});
	}
	
	for (int i = 1; i <= n; i ++) {
		ll w = read()£»
		e[i + k].push_back({i + 2 * k, w});
		e[i + 2 * k].push_back({i + k, w});
	}
	
	if (12 <= c && c <= 19) {
		
	}
	return 0;
}
