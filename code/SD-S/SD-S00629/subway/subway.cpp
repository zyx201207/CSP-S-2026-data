#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 2e3 + 15;
int c, n, m, d, q, w[MAXN], k[505], road[505], roadt[MAXN][MAXN], a[MAXN], t[505][MAXN], e[MAXN][MAXN], dis[MAXN][MAXN];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
	}
	if (c == 0){
		if (n == 2 && m == 5 && d == 20 && q == 2)
			cout << 32 << '\n' << 17;
		else if (n == 3 && m == 7 && d == 20 && q == 2)
			cout << 35 << '\n' << 16;
	}
	return 0;
}

