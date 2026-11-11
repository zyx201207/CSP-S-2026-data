#include<bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int,int>;
const int INF = 0x3f3f3f3f3f3f3f3f;
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		vector<int> x(n + 1);
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		vector<vector<int>> g(n + 1);
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(x[j] - x[i] <= d){
					g[i].push_back(j);
				}
			}
		}
		vector<vector<int>> cnt(n + 1,vector<int>(n + 1,0));
		for(int i = 1;i <= n;i++){
			queue<int> pq;
			vector<int> dist(n + 1,INF),vis(n + 1,0);
			pq.push(i);
			dist[i] = 0;
			while(pq.empty() == false){
				int p = pq.front();
				pq.pop();
				for(int j : g[p]){
					vis[j]++;
					if(vis[j] >= n){
						continue;
					}
					if(dist[j] > dist[p] + 1){
						dist[j] = dist[p] + 1;
						pq.push(j);
					}
					if(dist[j] == dist[p] + 1){
						cnt[i][j]++;
					}
				}
			}
		}
		int count = 0;
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(cnt[i][j] == 2){
					count++;
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}