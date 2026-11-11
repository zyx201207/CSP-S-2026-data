#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn = 1e5  + 5;
int n, d;
int res, ans, s;
int a[Maxn];
bool vis[Maxn];
void bfs(int st, int ed){
	queue < pair<int, int> > que;
	que.push(make_pair(st, 0));
	while(!que.empty()){
		pair <int, int> p = que.front();
		que.pop();
		if(p.first == ed && (s == 0 || s == p.second)){
			res++;
			s = p.second;
			if(res == 3){
				return;
			}
		}
		if(p.second > s && s != 0){
			return;
		}
		for(int i = 1; i <= n; i++){
			if(i == p.first)continue;
			if(abs(a[i] - a[p.first]) <= d){
				que.push(make_pair(i, p.second + 1));
			}
		}
	}
}
void solve(){
	cin >> n >> d;
	ans = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){ 
			s = 0;
			bfs(i, j);
			if(res == 2){
				ans++;
			}
			res = 0;
		}
	}
	cout << ans << endl;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int _, __;
	cin >> _ >> __;
	while(__--){
		solve();
	}
	return 0;
}
