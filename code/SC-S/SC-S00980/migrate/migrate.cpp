#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6 + 5;

int c, t, n, d;
bool f[N];
ll x[N];
vector <int> v;
vector <int> g[N];

inline void dfs(int x, int y, int k) {
	if (x == y) {
		v.push_back(k);
		return ;
	}
	
	for (int i : g[x]) {
		if (!f[i]) {
			f[i] = true;
			dfs(i, y, k + 1);
			f[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		
		for (int i = 1; i <= n; i++) 
			for (int j = i + 1; j <= n; j++) 
				if (abs(x[j] - x[i]) <= d) g[i].push_back(j), g[j].push_back(i);
		
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 2; j <= n; j++) {
				bool fl = false;
				for (int k : g[i]) if (j == k) {fl = true; break;}
				if (fl) continue;
				
				v.clear();
				memset(f, false, sizeof(f));
				f[i] = true;
				
				dfs(i, j, 0);
				
				sort(v.begin(), v.end());
				if (v.size() == 2 && v[1] == v[0]) {
					ans++;
				}
				else if (v.size() > 2 && v[0] == v[1] && v[1] != v[2]) ans++;
			}
		cout << ans << '\n';
	}
	
	return 0;
}