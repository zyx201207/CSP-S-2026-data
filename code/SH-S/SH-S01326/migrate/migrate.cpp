#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3+7;
const int INF = 0x3f;

vector <int> x;
int dp[N][N], dis[N][N];

int c, T, n;
ll d;

void solve() {
	for(int u = 1; u <= n; u++) {
		for(int v = u+1; v <= n; v++) {
			bool flag = true;
			if(dis[u][v] == x[v]-x[u]) {
				dp[u][v]++;
				flag = false;
				//cout << "Updated dis[" << u << "][" << v << "] ,count = " << dp[u][v] << "\n";
			} else if(dis[u][v] > x[v]-x[u]) {
				dis[u][v] = x[v]-x[u];
				dp[u][v] = 1;
				flag = false;
				//cout << "Updated dis[" << u << "][" << v << "], to " << dis[u][v] << "\n";
			}
			if(flag) {
				//cout << "Did not update anything at [" << u << "][" << v << "]\n";
			}
		}
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> c >> T;
	while(T--) {
		int ans = 0;
		cin >> n >> d;
		memset(dp, 0, sizeof(dp));
		memset(dis, INF, sizeof(dis));
		x.resize(n+1);
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		solve();
		for(int u = 1; u <= n; u++)
			for(int v = 1; v <= n; v++)
				if(dp[u][v] == 2)
					ans++;
		cout << ans << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
