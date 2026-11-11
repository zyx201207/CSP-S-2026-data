#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 3e18 + 100;
const int N = 330;
int x[N];
vector<int> E[N];
int cnt[N];
int dis[N];
struct Node{
	int x,step;
};
int n,d;
int ans = 0;
void BFS(int s){
	for(int i = 1; i <= n; i++) dis[i] = INF;
	for(int i = 1; i <= n; i++) cnt[i] = 0;
	queue<Node> q;
	Node start; start.step = 0,start.x = s;
	cnt[s] = 1;
	dis[s] = 0;
	q.push(start);
	while(!q.empty()){
		Node top = q.front(); q.pop();
		//cout << top.x << ' ' << top.step << '\n';
		for(int i = 0; i < E[top.x].size(); ++i){
			int v = E[top.x][i];
			//cout << "V:" << v << '\n';
			if(top.step + 1 > dis[v]) continue;
			if(top.step+1 < dis[v]){
				cnt[v] = cnt[top.x];
				dis[v] = top.step+1;
				Node news; news.step = dis[v],news.x = v;
				q.push(news);
			}
			else if(top.step+1 == dis[v]) cnt[v] += cnt[top.x];
		}
	} 
	for(int j = 1; j <= n; j++)
		if(cnt[j] == 2 && s != j)
			ans++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//migrate
	int c,t;
	if(!(cin >> c >> t)) return 0;
	while(t--){
		for(int i = 1; i <= n; ++i) E[i].clear();
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) cin >> x[i];
		for(int i = 1; i <= n; ++i){
			for(int j = i+1; j <= n; ++j){
				if(x[j] - x[i] <= d){
					E[j].push_back(i);
					E[i].push_back(j);
				}else break;
			}
		}
		ans = 0;
		for(int i = 1; i <= n; ++i) BFS(i);
		cout << ans/2 << '\n';
	}
}
