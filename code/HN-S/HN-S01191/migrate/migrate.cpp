#include <bits/stdc++.h>
using namespace std;
int c, t;
int cnt = 0;
bool g[5005][5005];
int bfs(int s, int t){
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		if(u == t) return q.size();
		for(int i = u+1;i <= t;i++){
			if(g[u][i]){
				q.push(i);
				if(i != t) g[u][i] = false;
			}
		}
		q.pop();
	}
}
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		int n;
		long long d;
		cin >> n >> d;
		int x[5005];
		for(int i = 1;i <= n;i++){
			cin >> x[i];
		}
		for(int r = n;r > 1;r--){
			for(int i = 1;i < r;i++){
				if(abs(x[i]-x[r]) <= d){
					g[i][r] == true;	
				}
			}
		}
		for(int v = n;v > 1;v--){
			for(int u = 1;u < v;u++){
				if(!g[u][v] && bfs(u, v) == 2){
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}
