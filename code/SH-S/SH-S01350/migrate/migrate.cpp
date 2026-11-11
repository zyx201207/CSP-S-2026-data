#include <bits/stdc++.h>
using namespace std;
int c,t;
struct node{
	int idx,stp; 
};
int n,d;
int x[2000005];
int vis[2000005];
queue<node> q;
bool bfs(int begin,int end){
	q.push({begin,0});
	vis[begin] = 2;
	
	while (q.size()){
		node head = q.front();
		if (head.idx == end && vis[end] >= 2){
			return 1;
		}
		if (head.idx == end)continue;
		q.pop();
		int r = head.idx + 1;
		while (x[r] - x[head.idx] <= d && r <= n){
			if (vis[r] >= 2)continue;
			q.push({r,head.stp+1});
			vis[r]++;
		}
	}
	return false;
}
void solve(){
	cin >> n >> d;
	for (int i=1;i<=n;i++)cin >> x[i];
	int ans = 0;
	for (int i=1;i<=n;i++){
		for (int r = i+1;r<=n;r++){
			if (bfs(i,r))ans++;
			while (q.size())q.pop();
			memset(vis,0,sizeof(vis));
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
