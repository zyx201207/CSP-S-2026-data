#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 520,M = 5e5 + 10,INF = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,pyc[N][N],w[M];
struct PYC{int id,t;};vector<PYC>have[M];
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= n;++i) for(int j = 1;j <= n;++j) pyc[i][j] = (i == j ? 0 : INF);
	for(int i = 1;i <= m;++i) cin >> w[i];
	for(int i = 1,k;i <= n;++i){
		cin >> k;
		for(int j = 1,a,t;j <= k;++j){
			cin >> a >> t;have[a].emplace_back((PYC){i,t});
		}
	}for(int i = 1;i <= m;++i){
		for(int j = 0;j < (int)have[i].size();++j){
			for(int k = j + 1;k < (int)have[i].size();++k){
				pyc[have[i][j].id][have[i][k].id] = pyc[have[i][k].id][have[i][j].id] = min(pyc[have[i][j].id][have[i][k].id],have[i][j].t + have[i][k].t);
			}
		}
	}for(int k = 1;k <= n;++k){
		for(int i = 1;i <= n;++i){
			for(int j = 1;j <= n;++j){
				pyc[i][j] = min(pyc[i][j],pyc[i][k] + pyc[k][j]);
			}
		}
	}for(int i = 1,u,v;i <= q;++i){
		cin >> u >> v;
		if(u == v){
			cout << "0\n";
			continue;
		}int Pyc = INF;
		for(int j = 0;j < (int)have[u].size();++j){
			for(int k = 0;k < (int)have[v].size();++k){
				Pyc = min(Pyc,pyc[have[u][j].id][have[v][k].id] + have[u][j].t + have[v][k].t);
			}
		}cout << w[u] + w[v] + Pyc << "\n";
	}return 0;
}