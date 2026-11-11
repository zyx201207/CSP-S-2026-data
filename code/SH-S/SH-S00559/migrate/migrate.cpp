#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 5010;

int c, t, n, d;
int a[N];
vector<int> v[N];
int ans[N][N][2];
bool vis[N];
void dfs(int s, int x, int fa, int depth){
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i++){
		if (vis[v[x][i]] || v[x][i] == fa) continue;
		if (depth < ans[s][v[x][i]][0]){
			ans[s][v[x][i]][0] = depth;
			ans[s][v[x][i]][1] = 1;
		} else if (depth == ans[s][v[x][i]][0]){
			ans[s][v[x][i]][1]++;
		}
		dfs(s, v[x][i], x, depth + 1);
	}
	vis[x] = 0;
}

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				ans[i][j][0] = 0x3f3f3f3f;
			}
		} 
		for (int j = 1; j <= n; j++){
			v[j].clear();
		}
		for (int i = 1; i <= n; i++){
			int x = lower_bound(a+1, a+1+n, a[i] - d) - a;
			int y = upper_bound(a+1, a+1+n, a[i] + d) - a - 1;
			for (int j = x; j <= y; j++){
				// i -> j
				if (i == j) continue;
				v[i].push_back(j);
			}
			
		}

		
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				vis[j] = 0;
			}
			dfs(i, i, 0, 1);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				//cout << ans[i][j][1] << " "; 
				if (ans[i][j][1] == 2){
					cnt++;
				}
			}
			//cout << endl;
		}
		cout << cnt / 2 << endl;
	}
	
	return 0;
} 
