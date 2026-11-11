#include <bits/stdc++.h>
using namespace std;
long long n, d;
vector<long long> x(2000010);
vector<bool> vis(2000010,false);
struct node{
	long long u, step;
};
long long bfs(long long u, long long v){
	queue<node> q;
	q.push({u, 0});
	long long xx=0;
	long long mmm=0;
	bool flag=0;
	while(q.size()){
		auto u = q.front().u, step = q.front().step;
		q.pop();
		for(long long i = 1; i <= d; i ++){
			if(!vis[i+u]){
				if(i + u == v && (mmm == step || flag == 0)){
					flag = 1;
					mmm=step;
					xx++;
				}
				else{
					if (i + u < v)q.push({i + u,step+1});
				}
			}
		}
	}
	return xx;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t;
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		long long ans = 0;
		for(long long i = 1; i <= n; i ++){
			cin >> x[i];
			vis[i] = 0;
		}
		for(long long i = 1; i <= n; i ++){
			for(long long j = i + 1; j <= n; j ++){
				if(bfs(i, j) == 2)
					ans++;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
