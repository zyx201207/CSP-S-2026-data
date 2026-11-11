#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;

struct str{
	int a,b;
};

int n,k,ans = 2147483647;
int f[N],fb[N],vis[N];
vector<int> g[N];

void dfs(int u,int fa){
	for (auto v : g[u]){
		if (v == fa){
			continue;
		}
		if (f[v] == 1){
			fb[v] = 1;
			dfs(v,u);
		}
	}
}

int bfs(int u){
	queue<str> q;
	q.push({u,0});
	vis[u] = 1;
	while(q.size()){
		str _ = q.front();
		q.pop();
		if (f[_.a] == 1){
			return _.b;
		}
		for (auto v : g[u]){
			if (vis[v] != 1){
				vis[v] = 1;
				q.push({v,_.b + 1});
			}
		}
	}
	return 0;
}

void ckdfs(int step,int cnt){
	if (k - cnt > step){
		return;
	}
	if (step > n){
		if (cnt != k){
			return;
		}
		int blockcnt = 0;
		memset(fb,0,sizeof(fb));
		for (int i = 1;i <= n;i++){
			if (fb[i] == 0){
				fb[i] = ++blockcnt;
				if (blockcnt > 2){
					return;
				}
				dfs(i,0);
			}
		}
		int maxn = 0;
		for (int i = 1;i <= n;i++){
			memset(vis,0,sizeof(vis));
			maxn = max(maxn,bfs(i));
		}
		ans = min(ans,maxn);
	}
	f[step] = 1;
	dfs(step + 1,cnt + 1);
	f[step] = 0;
	dfs(step + 1,cnt);
}

int notmain(){
	ans = 2147483647;
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		g[i].clear();
	}
	for (int i = 1;i < n;i++){
		int x,y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	memset(f,0,sizeof(f));
	ckdfs(1,0);
	cout << ans << endl;
	return 0;
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--){
		notmain();
	} 
	return 0;
}

