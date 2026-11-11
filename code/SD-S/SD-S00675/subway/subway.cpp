#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000 + 10;
int c;
int n;
int m;
int d;
int q;
int a[N];
int k[N];
struct node{
	int x;
	int t;
};
node b[N][N];
int dis[N];
void solve(int s, int e){
	queue<int> q;
	q.push(s);
	for(int i = 1; i <= m; i ++){
		dis[i] = 1e18;
	}
	dis[s] = 0;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i = 1; i <= n; i ++){
			bool ok = 0;
			for(int j = 1; j <= k[i]; j ++){
				//可以通过该铁路到达
				if(b[i][j].x == x){
					ok = 1;
					break;
				}
			}
			if(ok){
				for(int j = 1; j <= k[i]; j ++){
					if(b[i][j].x == x){
						continue;
					}
					if(dis[b[i][j].x] > dis[x] + a[x] + b[i][b[i][j].x].t + b[i][j].t + a[b[i][j].x]){
						dis[b[i][j].x] = dis[x] + a[x] + b[i][b[i][j].x].t + b[i][j].t + a[b[i][j].x];
						q.push(b[i][j].x);
					}
				}
			}
		}
	}
	cout << dis[e] << endl;
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i ++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++){
			cin >> b[i][j].x >> b[i][j].t;
		}
	}
	while(q--){
		int s;
		int e;
		cin >> s >> e;
		solve(s, e);
	}
	return 0;
}


