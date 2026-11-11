#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define ll long long
using namespace std;
const int MAXN = 2e6+2;
ll c, t, n, d, go[302][302][302];
ll ans, x[MAXN];
void Dfs(int st, int pos, int tim)
{
	for (int i = pos+1; i <= n; ++i){
		if (x[i] - x[pos] <= d){
			++go[st][i][tim];
			Dfs(st, i, tim+1);
		} else {
			break;
		}
	}
}
void Solve1()
{
	ans = 0; 
	memset(go, 0, sizeof(go));
	for (int i = 1; i <= n; ++i) Dfs(i, i, 1);
	for (int i = 1; i <= n; ++i){
		for (int j = i+1; j <= n; ++j){
			for (int k = 1; k <= n; ++k){
				if (go[i][j][k] == 2) ++ans;
				if (go[i][j][k]) break;
			}
		}
	}
	cout << ans << "\n";
}
void Solve2()
{
	cout << "pass\n";
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string file = "migrate";
	freopen((file + ".in").c_str(), "r", stdin);
	freopen((file + ".out").c_str(), "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		Solve1();
	}
	return 0;
}
