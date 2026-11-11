#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
int res, n, k;
bool bk[15];
int vis[15];
vector<int> v[15];
stack<int> st;
void dfs(int u){
	vis[u] = 1;
	for(auto x : v[u]){
		if(bk[x]&&!vis[x])dfs(x);
	}
}
void solve(){
	stack<int> tmp = st;
	queue<int> q;
	memset(bk, 0, sizeof bk);
	memset(vis, 0, sizeof vis);
	while(tmp.size()){
		bk[tmp.top()] = 1;
		q.push(tmp.top());
		tmp.pop();
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(bk[i]&&!vis[i]){
			dfs(i);
			cnt++;
		}
	}
	if(cnt>2){
		return;
	}
	int tres = 0;
	while(q.size()){
		int x = q.front();
		q.pop();
		for(auto g : v[x]){
			if(vis[g])continue;
			vis[g] = vis[x]+1;
			tres = max(tres, vis[g]);
			q.push(g);
		}
	}
	res = min(tres-1, res);
}
void work(int u, int x){
	if(x==k){
		solve();
		return;
	}
	if(u==n+1){
		return;
	}
	work(u+1, x);
	st.push(u);
	work(u+1, x+1);
	st.pop();
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--){
		res = 0x3f3f3f3f;
		cin >> n >> k;
		for(int i = 1; i <= n ;i++)v[i].erase(v[i].begin(), v[i].end());
		for(int i = 1; i < n; i++){
			int u, a;
			cin >> u >> a;
			v[u].push_back(a);
			v[a].push_back(u);
		}
		work(1, 0);
		cout << res <<endl;
	}
	return 0;
}
