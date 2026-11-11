#include<bits/stdc++.h>
using namespace std;
int c, t, n, k;
int s[1100000], a[10100][10100];
int mn = 1e9 + 7;
inline void solve () {

	int ans = -1;
	int mnn = 1e9 + 7;
	for (int i = 0; i < n; i ++ ) {
		mnn = 1e9 + 7;
		for (int j = 0; j < k; j ++ ) {
			mnn = min (mnn, a[i][s[j]]);
		}
//		cout << mnn << "  ";
		ans = max (ans, mnn);
	} 
//	if (ans == 1) {
//		cout <<"sbsbsb";
//		for (int i = 0; i < k; i ++ ) {
//			cout << s[i] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
	mn = min (ans, mn);
	return; 
}
int f[11000];
inline int find (int x) {
	if (x == f[x]) return x;
	return f[x] = find (f[x]);
}
int vis[11000];
inline bool check () {
	for (int i = 0; i < n; i ++ ) {
		f[i] = i;
	}
//	for (int i = 0; i < k; i ++ ) {
//		cout << s[i] << " ";
//	}
//	cout << "ss\n";
	for (int i = 0; i < k; i ++ ) {
		for (int j = 0; j < k; j ++ ) {
			if (a[s[i]][s[j]] == 1 && find (f[s[i]]) != find (f[s[j]])) f[s[i]] = find (s[j]);
		}
	}
//	for (int i = 0; i< k; i ++ ){
//		cout << f[s[i]] <<" "; 
//	}
//	cout << "cc\n";
	for (int i = 0; i < k; i ++ ) {
		vis[i] = 0;
	}
	int cnt = 0;
	for (int i = 0; i < k; i ++ ) {
//		cout << find (s[i]) << " ";
		if (vis[find (s[i])] == 0) {
			vis[find (s[i])] = 1;
		}
	}
	cnt = 0;
	for (int i = 0; i < k; i ++ ) {
		cnt += vis[s[i]]; 
	}
//	cout << "oo\n";
//	cnt = 0;
//	for (int i = 0; i < k; i ++ ) {
//		cout << vis[s[i]] << " " ;
//		cnt += vis[s[i]];
//	}
//	cout << "pp\n";
//	cout << cnt << endl;
	if (cnt > 2) return true;
	return false; 
}
inline void dfs (int x) {
	if (x != 0 && s[x - 1] + k - x >= n) return;
	if (x == k) {
//		for (int i = 0; i < k; i ++ ) {
//			cout << s[i];
//		}
//		cout << endl;
		if (check()) return;
		solve (); 
		return;
	}
	if (x == 0) {
		for (int i = 0; i < n; i ++ ) {
			s[x] = i;
			dfs (x + 1);
		}
		return;
	}
	for (int i = s[x - 1] + 1; i < n; i ++ ) {
		s[x] = i;
		dfs (x + 1);
	}
	return;
}
int main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin >> c >> t;
	while (t -- ) {
		for (int i = 0; i < n; i ++ ) {
			f[i] = -1;
			vis[i] = 0;
		}
		cin >> n >> k; 
		int u, v;
		for (int i = 0; i < n; i ++ ) {
			for (int j = 0; j < n; j ++ ) {
				a[i][j] = 1e9 + 7;
			}
		}
		for (int i = 0; i < n; i ++ ) {
			a[i][i] = 0;
		}
		for (int i = 0; i < n - 1; i ++ ) {
			cin >> u >> v;
			a[u - 1][v - 1] = 1;
			a[v - 1][u - 1] = 1;
		}
		for (int k = 0; k < n; k ++ ) {
			for (int i = 0; i < n; i ++ ) {
				for (int j = 0; j < n; j ++ ) {
					a[i][j] = min (a[i][j], a[i][k] + a[k][j]);
				}
			}
		}
//		for (int i = 0; i < n; i ++ ) {
//			for (int j = 0 ; j < n; j ++ ) {
//				cout << a[i][j] << " ";
//			}
//			cout << endl;
//		}
		mn = 1e9 + 7;
		dfs (0);
		cout << mn << endl;
	}
	return 0;
}
