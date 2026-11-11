#include<bits/stdc++.h>
#define pii pair<int, int>
#define int long long
using namespace std;

int n, d;
int a[2000010];
vector<int> G[2000010];

int bfs(int u0){
	queue<pii > q;
	vector<pii > vis(n + 5, make_pair(-1, 1)); 
	q.push({u0, 0});
//	cout << "u0:" << u0 << '\n';
	while(!q.empty()){
		int u = q.front().first, step = q.front().second;q.pop();
		
		if(vis[u].first == -1){
			vis[u].first = step;
		}else{
			if(step == vis[u].first){
				vis[u].second ++;
			}else{
				continue;
			}
		}
//		cout << "{" << u << ", " << step << "}  ";
		for(int v : G[u]){
			q.push(make_pair(v, step + 1));
		}
	}
//	cout << '\n';
//	for(int i = 1;i <= n;i ++) cout << vis[i].second << ' ';
//	cout << '\n';
	int cnt = 0;
	for(int i = 1;i <= n;i ++) if(vis[i].second == 2) cnt ++;
	return cnt;
}

void slove_nn(){//40分 
	cin >> n >> d;
	for(int i = 1;i <= n;i ++) G[i].clear(), cin >> a[i];
//	cout << "xd";
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			if(i == j) continue;
			if(abs(a[i] - a[j]) <= d){
				G[i].push_back(j);
				//G[j].push_back(i);
			}
		}
	}
	int ans = 0;
//	cout << "xd2";
	for(int i = 1;i <= n;i ++){
		ans += bfs(i);
	}
	cout<< ans / 2 << '\n';
	return;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(0), cout.tie(0);
	
	int c, T;
	cin >> c >> T;
	while(T --){
		slove_nn();
	}
	
	return 0;
}