#include <bits/stdc++.h>
#define pb push_back
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
//using i128 = __int128;
//using u128 = unsigned __int128;
using namespace std;
bool ST;

const int N = 5e5 + 5;
const int M = 5e2 + 5;

struct node{int x,i;};

int tid,n,m,md,q,L[M];
i64 f[M][M],rst[N];
vector<node> D[N];
vector<int> R[M];

bool ED;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	mt19937 rnd(time(0));
	
	cin >> tid >> n >> m >> md >> q;
	memset(f,0x3f,sizeof(f));
	for (int i = 1;i <= m;++i) cin >> rst[i];
	for (int i = 1;i <= n;++i){
		cin >> L[i];R[i].resize(L[i] + 5);
		for (int j = 1;j <= L[i];++j){
			int u;cin >> u >> R[i][j];
			D[u].pb({i,j});
		}
	}for (int i = 1;i <= m;++i){
		for (int j = 0;j < (int)D[i].size();++j){
			for (int k = j + 1;k < (int)D[i].size();++k){
				auto x = D[i][j],y = D[i][k];
				i64 w = R[x.x][x.i] + R[y.x][y.i];
				f[x.x][y.x] = f[y.x][x.x] = w;
			}
		}
	}for (int i = 1;i <= n;++i) f[i][i] = 0;
	for (int k = 1;k <= n;++k){
		for (int i = 1;i <= n;++i){
			for (int j = 1;j <= n;++j) f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
		}
	}while (q--){
		int u,v;cin >> u >> v;
		i64 ans = LLONG_MAX;
		for (int i = 0;i < (int)D[u].size();++i){
			for (int j = 0;j < (int)D[v].size();++j){
				auto x = D[u][i],y = D[v][j];
				ans = min(ans,rst[u] + rst[v] + R[x.x][x.i] + R[y.x][y.i] + f[x.x][y.x]);
			}
		}cout << ans << '\n';
	}
	
//	cerr << "\ntime used: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000.0 << " ms";
//	cerr << "\nmemory used: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB";
	return 0; 
}/*
样例解释t[i][j]->t[i][a[i][j]]真牛大了 
*/
