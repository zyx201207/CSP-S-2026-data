#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 5e5 + 10;

int cc, t, n, ans;
long long d;

void solve2(vector<long long> x) {
	long long ans = 0;
	for (int i = 1;i < n;i++) {
		for (int j = i + 1;j <= n;j++) {
			if (x[j] - x[i] > d) ans++;
		}
	}
	cout << ans << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
    cin >> cc >> t;
    while (t--) {
    	cin >> n >> d;
    	vector<long long> x(n + 1);
    	vector<vector<int>> dis(n+1, vector<int>(n+1, 1e9)), c(n+1, vector<int>(n+1));
    	for (int i = 1;i <= n;i++) cin >> x[i], dis[i][i] = 0, c[i][i] = 1;
    	if (cc == 13 || cc == 14) {
    		solve2(x);
    		continue;
		}
    	for (int i = 1;i < n;i++) 
    		for (int j = i + 1;j <= n;j++) 
    			if (x[j] - x[i] <= d) dis[i][j] = 1, c[i][j] = 1;
    			
    	for (int i = 1;i < n;i++) {
    		for (int j = i + 1;j <= n;j++) {
    			if (x[j] - x[i] <= d) dis[i][j] = 1, c[i][j] = 1;
    			else {
    				for (int k = i + 1;k < j;k++) {
    					if (dis[i][k] + dis[k][j] < dis[i][j]) {
    						dis[i][j] = dis[i][k] + dis[k][j];
    						c[i][j] = 1;
						}
						else if (dis[i][k] + dis[k][j] == dis[i][j]) c[i][j]++;
					}
				}
				if (c[i][j] == 2) ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}