#include<bits/stdc++.h>

using namespace std;

queue<int> q;
vector<int> G[5010];

long long a[2000010];
int ru[5010];
long long dp[5010];
int dis[5010];

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t--){
		long long n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			G[i].clear();
			dis[i] = 1e9;
			dp[i] = 0;
			ru[i] = 0;
			cin >> a[i];
		}
		if(c == 11 || c == 12){
			if(n == 1){
				cout << 0;
				continue;
			}
			long long cha = a[2] - a[1];
			long long x = d / cha;
			long long l = x + 1;
			long long r = 2 * x - 1;
			long long ret = 0;
			for(int i = 1; i <= n; i++){
				long long ll = i + l - 1;
				long long rr = i + r - 1;
				rr = min(n, rr);
				ll = min(n + 1, ll);
				if(ll > rr){
					continue;
				}
				ret += rr - ll + 1;
			}
			cout << ret << "\n";
		}else{
			for(int i = 1; i < n; i++){
				long long sum = 0;
				for(int j = i + 1; j <= n; j++){
					sum += a[j] - a[j - 1];
					if(sum > d){
						break;
					}
					G[i].push_back(j);
//					cout << i << " " << j << "N\n";
					ru[j]++;
				}
			}
			long long ret = 0;
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					dp[j] = 0;
					dis[j] = 1e9;
				}
				q.push(i);
				dis[i] = 0;
				dp[i] = 1;
				while(!q.empty()){
					int u = q.front();
					q.pop();
					for(int v : G[u]){
						if(dis[v] > dis[u] + 1){
							dis[v] = dis[u] + 1;
							dp[v] = dp[u];
							q.push(v);
						}else if(dis[v] == dis[u] + 1){
							dp[v] += dp[u];
						}
					}
				}
				for(int j = 1; j <= n; j++){
//					cout << dp[j] << " ";
					if(dp[j] == 2){
						ret++;
					}
				}
//				cout << "\n";
			}
			cout << ret << "\n";
		}
	}
	
	
	return 0;
}