/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll m;
vector<ll> a, fa;
//vector<ll> g[100005];

struct Edge {
	ll u, v, w;
} edge[500005];

int find(int u) {
	if (fa[u]) return fa[u];
	return fa[u] = find(fa[u]);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	// freopen("crystal.in", "r", stdin);
	// freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	a.reserve(n + 1);
	fa.reserve(n + 1);
	
	ll mina = 1e9;
	for (int i = 1 ;i <= n; i++) {
		cin >> a[i];
		mina = min(mina, a[i]);
	}
	
	sort(a.begin() + 1, a.end());
	
	queue<int> q;
	q.push(1);
	int d = 1;
	for (int i = 1; i <= n - 1; i++) {
		int f = q.front();
		q.pop();
		edge[i] = {f, a[i], a[i] - f};
		q.push(a[i]);  
		i++;
		
		edge[i] = {f, a[i], a[i] - f};
		q.push(a[i]);
	}
	
	
	
	return 0;
} 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n; ll m;
vector<ll> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	a.assign(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	if (a[2] - a[1] == a[3] - a[2]) {
		int d = a[2] - a[1];
		int ans = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += i * d;
			if (sum > m) break;
			ans++;
		}
		cout << ans;
		return 0;
	}
	
	sort(a.begin() + 1, a.end());
	
	int ans = 0;
	for (int l = 1; l <= n - 1; l++) {
		for (int r = l + 1; r <= n; r++) {
			int sum = 0;
			for (int i = l; i <= r - 1; i++) {
				sum += a[r] - a[i];
			}
			if (sum <= m) {
				ans = max(ans, r - l + 1);
			}
		}
	}
	
	cout << ans << "\n";
	
	// for (int i = 1; i <= n; i++) cout << a[i] << " ";
	
	return 0;
} 

/*
5 5
1 2 4 8 9
*/
