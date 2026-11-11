#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e6 + 10;
int n, d, ans;
int x[N];
vector<int> v[N];
struct node{
	int to, v;
	bool operator < (const node &x) const {
		return v > x.v;
	}
};
priority_queue<node> q;
int dis[N], cnt[N];
bool vis[N];

void Dij(int s){
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	q.push({s, 0});
	dis[s] = 0;
	while(!q.empty()){
		int k = q.top().to; q.pop();
		if(vis[k]) continue ;
		vis[k] = true;
		for(auto i : v[k]){
			if(dis[i] > dis[k] + 1){
				dis[i] = dis[k] + 1;
				cnt[i] = 1;
				q.push({i, dis[i]});
			}
		}
	}
}

void dfs(int k, int p){
	if(p == dis[k]) cnt[k] ++;
	if(p > dis[k]) return ;
	for(int i : v[k]) dfs(i, p + 1);
	return ;
}

void work(){
	cin >> n >> d;
	ans = 0;
	for(int i = 1;i <= n;i ++){
		cin >> x[i];
		v[i].clear();
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i + 1;j <= n;j ++){
			if(x[j] - x[i] <= d){
				v[i].push_back(j);
			} else break;
		}
	}
	for(int i = 1;i <= n;i ++){
		Dij(i);
		memset(cnt, 0, sizeof cnt);
		dfs(i, 0);
		for(int i = 1;i <= n;i ++) ans += (cnt[i] == 2);
	}
	cout << ans << endl;
}

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t --) work();
	return 0;
}