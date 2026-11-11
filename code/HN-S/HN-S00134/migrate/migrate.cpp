#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 1e6 + 5;
const ll M = 5e3 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
struct node{
	ll x,d;
	bool operator < (const node &e) const{
		return d > e.d;
	}
};
ll n,d,a[N],ans,dis[N],cnt[N];
bool vis[N],flag[M][M]; 
vector<int> E[N];
void dijkstra(int s){
	for(int i = 1;i <= n;i++){
		dis[i] = INF,vis[i] = 0;
		cnt[i] = 0;
	}
	priority_queue<node> q;
	q.push({s,0});
	dis[s] = 0;
	cnt[s] = 1;
	while(!q.empty()){
		int u = q.top().x;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto v : E[u]){
			if(dis[u] + 1 < dis[v]){
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push({v,dis[v]});
			}else if(dis[u] + 1 == dis[v]){
				cnt[v] += cnt[u];
			}
		}
	}
	for(int i = 1;i <= n;i++){
		flag[s][i] = (cnt[i] == 2);
	} 
}
void work(){
	ans = 0;
	for(int i = 1;i <= n;i++){
		E[i].clear();
	}
	cin >> n >> d;
	bool flag_A = 1;
	ll mn = INF;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(i >= 2){
			mn = min(mn,a[i] - a[i - 1]);
			if(a[i] - a[i - 1] != a[2] - a[1]){
				flag_A = 0;
			}
		}
	}
	if(mn >= d){
		cout << "0\n";
		return;
	}
	if(n <= 10000){
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				if(a[j] - a[i] <= d){
					E[i].push_back(j);
					E[j].push_back(i);
				}
			}
		}
		for(int i = 1;i <= n;i++){
			dijkstra(i);
		}
		for(int i = 1;i <= n;i++){
			for(int j = i + 1;j <= n;j++){
				ans += flag[i][j];
			}
		}	
		cout << ans << "\n";
		return;
	}
	cout << "0\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int oT_To = 1;
	cin >> oT_To >> oT_To;
	while(oT_To--){ work();}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
