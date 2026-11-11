#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

const int M = 5e5 + 10, N = 500 + 10;
const ll INF = 1e16; 

int CASE, n, m, d, q, w[M]; int t[M][N]; 
int lbl[M][25]; 
ll g[N][N]; ll dis[N][N]; 

void solve() {
	
	cin >> CASE >> n >> m >> d >> q; 
	for(int i=1;i<=m;i++) cin >> w[i]; 
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			g[i][j] = INF, dis[i][j] = INF; 
			if(i == j) g[i][j] = 0, dis[i][j] = 0; 
		}
	}
	
	for(int i=1;i<=n;i++) {
		int k; cin >> k; 
		for(int j=1;j<=k;j++) {
			int A, T; cin >> A >> T; 
			lbl[A][++lbl[A][0]] = i; 
			t[A][i] = T; 
			for(int p1=1;p1<lbl[A][0];p1++) {
				int s1 = lbl[A][p1], s2 = i; 
				g[s1][s2] = min(g[s1][s2], (ll)t[A][s1] + t[A][s2]); 
				g[s2][s1] = min(g[s2][s1], (ll)t[A][s1] + t[A][s2]); 
			}
		}
	}
	
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(g[i][k] >= INF || g[k][j] >= INF) continue; 
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]); 
			}
		}
	}
	
	while(q--) {
		int x, y; cin >> x >> y; 
		ll mn = INF; 
		for(int i=1;i<=lbl[x][0];i++) {
			for(int j=1;j<=lbl[y][0];j++) {
				int s1 = lbl[x][i], s2 = lbl[y][j]; 
				mn = min(mn, g[s1][s2] + w[x] + w[y] + t[x][s1] + t[y][s2]); 
			}
		}
		cout << mn << endl; 
	}
	
}

signed main() {
	
	faster; 
	
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);

//  int _; cin >> _; while(_--)
	solve();
	
	return 0;
	
}

