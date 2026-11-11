#include<bits/stdc++.h>
#define int long long
using namespace std;

const int Max_N=500+10, Max_M=500000+10;

int T;
int c, n, m, d, q;
int w[Max_M], t[Max_N], f[Max_N][Max_N];
vector<pair<int, int> >V[Max_M];

void solve(){
	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1; i <= m; i++)cin >> w[i];
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n ;j++){
			f[i][j] = 998244353114514123;
		}
		f[i][i]=0;
	}
	
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		for(int j = 1; j <= t[i]; j++){
			int u,c1;
			cin >> u >> c1;
			for(auto x:V[u]){
				int l = x.first, c2 = x.second;
				f[i][l] = f[l][i] = c1+c2;
			}
			V[u].push_back({i,c1});
		}
	}
	
	for(int j = 1; j <= n; j++){
		for(int i = 1; i <= n; i++){
			for(int k = 1; k <= n; k++){
				f[i][k] = min(f[i][k], f[i][j] + f[j][k]);
			}
		}
	}
	
	while(q--){
		int x,y;
		cin >> x >> y;
		
		int ans = 998244353114514123;
		
		for(auto u: V[x]){
			for(auto v: V[y]){
				ans = min (ans,f[u.first][v.first]+u.second+v.second);
			}
		}
		
		cout << ans + w[x] + w[y] << "\n";
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	T=1;
	
	while(T--){
		solve();	
	}
}

