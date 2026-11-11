#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, k;
int f[105][5], dep[105];
int mxdep[105];
int dp[105][105];
vector<int> v[105];
void dfs(int x){
	for (int i = 0; i < v[x].size(); i++)
		if (v[x][i] != f[x][0]){
			dep[v[x][i]] = dep[x] + 1;
			dfs(v[x][i]);
			mxdep[x] = max(mxdep[x], dep[v[x][i]]);
			
		}
}
void init(){
	
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	if (c <= 6){
		while (t--){
			memset(dp, 0x3f, sizeof(dp));
			cin >> n >> k;
			for (int i = 1; i <= n; i++){
				int a, b;
				cin >> a >> b;
				v[a].push_back(b);
				v[b].push_back(a);
			}
			dfs(1);
		}
	}
	return 0;
}

