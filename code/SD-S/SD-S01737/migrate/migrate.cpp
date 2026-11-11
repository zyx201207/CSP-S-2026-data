#include<bits/stdc++.h>//1
#define ll long long
using namespace std;
const int N = 300+3;
int c,T,n;
ll a[N],d,dis[N],ans;
vector<int>  g[N];
queue<int>  q;
int num[N];
bool vis[N];
ll bfs(int s){
	for (int i = 1;i < N;i++)  dis[i] = 1e18;
	for (int i = 1;i < N;i++)  num[i] = 0;
	for (int i = 1;i < N;i++)  vis[i] = 0;
	q.push(s);
	dis[s] = 0;
	num[s] = 1;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (auto v : g[u]){
			if (!vis[v]){
				dis[v] = dis[u]+1;
				num[v] = num[u];
				q.push(v);
				vis[v] = 1;
				continue;
			}
			if (dis[v] <= dis[u])  continue;
			if (dis[v] == dis[u]+1)  num[v] += num[u];
		}
	}
	ll ret = 0;
	for (int i = 1;i <= n;i++){
		if (num[i] == 2)  ret++;
	}
	
	return ret;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>c>>T;
	if (c <= 6){
		while (T--){
			cin>>n>>d;
			ans = 0;
			for (int i = 1;i <= n;i++)  cin>>a[i];
			for (int i = 1;i <= n;i++){
				for (int j = i+1;j <= n&&a[j] <= a[i]+d;j++){
					g[i].push_back(j);
	//				cout<<i<<' '<<j<<'\n';
				}
			}
			for (int i = 1;i <= n;i++)  ans += bfs(i);
			cout<<ans<<'\n';
			for (int i = 1;i <= n;i++)  g[i].clear();
		}
	}

	
	return 0;
}
