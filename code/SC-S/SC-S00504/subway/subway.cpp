#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500;
const int inf = 1e18;
int floyd[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m);
	for(int i = 0; i < m; i++){
		cin>>w[i];
	}
	for(int i = 0; i< N; i++){
		for(int j = 0; j < N; j++){
			if(i != j)floyd[i][j] = inf;
			else floyd[i][j] = 0;
		}
	}
	vector<vector<int>> lines(m), dis(m);
	for(int i = 0; i < n; i++){
		int k;
		cin>>k;
		for(int j = 0; j < k; j ++){
			int s,t;
			cin>>s>>t;
			s--;
//			cout<<s<<'	'<<lines.size()<<'	'<<k<<endl;
			lines[s].push_back(i);
			dis[s].push_back(t);
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < lines[i].size(); j++){
			for(int k = 0; k < j; k++){
				int u = lines[i][j], v = lines[i][k];
				floyd[u][v] = min(floyd[u][v], dis[i][j] + dis[i][k]);
				floyd[v][u] = floyd[u][v];
			}
		}
	}
	for(int k = 0; k < n; k++){
		for(int i = 0; i  <n; i++){
			for(int j = 0; j < i; j++){
				floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
				floyd[j][i] = floyd[i][j];
			}
		}
	}
	for(int i = 0; i < q; i++){
		int u, v;
		cin>>u>>v;
		u--;
		v--;
		int ans = inf;
		for(int j = 0; j < lines[u].size(); j++){
			for(int k = 0; k < lines[v].size(); k++){
				int cur = floyd[lines[u][j]][lines[v][k]] + dis[u][j] + dis[v][k];
				ans = min(ans,cur);
			}
		}
		cout<<w[u] + w[v] + ans<<'\n';
	}
}