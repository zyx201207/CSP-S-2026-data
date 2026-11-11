#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,t;
};
int c,t,n,d,a[2000005],dis[2000005],sum[2000005];
bool vis[200005];
void bfs(int x){
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	memset(sum,0,sizeof(sum));
	queue <node> q;
	q.push(node{x,0});
	while (!q.empty()){
		node now = q.front();
		q.pop();
		if (vis[now.x] && dis[now.x] == now.t) sum[now.x]++;
		if (vis[now.x]) continue;
		vis[now.x] = 1;
		dis[now.x] = now.t;
		sum[now.x]++;
		for (int i = 1;i <= n;i++){
			if (i == now.x) continue;
			if (abs(a[now.x]-a[i]) <= d) q.push(node{i,now.t+1}); 
		}
	}
}
signed main(){
	freopen("migrate.in" ,"r" ,stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++) cin >> a[i];
		int ans = 0;
		for (int i = 1;i <= n;i++){
			bfs(i);
			for (int j = i+1;j <= n;j++) if (sum[j] == 2) ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
