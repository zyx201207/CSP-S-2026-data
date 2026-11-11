#include<bits/stdc++.h>
using namespace std;

const int M = 2 * 1e4 + 5;
const int N = 505;
const long long INF = 1e15;
int c, n, m, d, q;
int w[M];
int k[N];//route station
int a[N][M];
int t[N][M];
int tt[M][M];
long long ans;
vector<int> rela[M];
bool visited[M] = {0};

void dfs(int pos, int des, int cur){
	if(pos == des){
		if(ans > cur){
			ans = cur;
		}
		return;
	}
	int len = rela[pos].size();
	for(int i = 0; i < len; i++){
		int nxt = rela[pos][i];
		if(visited[nxt] == 0){
			visited[nxt] = 1;
			dfs(nxt, des, cur + tt[pos][nxt]);
			visited[nxt] = 0;
		}
	}
	return;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
			if(j > 1){
				rela[a[i][j - 1]].push_back(a[i][j]);
				rela[a[i][j]].push_back(a[i][j - 1]);
				tt[a[i][j - 1]][a[i][j]] = t[i][j] + t[i][j - 1];
				tt[a[i][j]][a[i][j - 1]] = t[i][j] + t[i][j - 1];
			}
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		ans = INF;
		visited[x] = 1;
		dfs(x, y, w[x] + w[y]);
		visited[x] = 0;
		cout << ans << endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
