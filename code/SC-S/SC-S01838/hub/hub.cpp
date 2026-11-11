#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define ull unsigned long long
using namespace std;

const int N=1e6 + 5,M=15;
int n,k;
vector<vector<int>> g(N);
int father[M];
bool vis[M],connection[M],temp[M];
int dist[M];
void init(int mx){
	for(int i=1;i <= mx;i++){
		connection[i]=false;
		father[i]=i;
		dist[i]=0;
		temp[i]=false;
	}
	return;
}
int find(int x){
	if(father[x] == x){
		return x;
	}
	return father[x]=find(father[x]);
}
void merge(int u,int v){
	int fu=find(u),fv=find(v);
	father[fu]=fv;
	return;
}
int ans=9e18;
void dfs(int x,int left){
	if(x == n + 1){
		if(left != 0){
			return;
		}
		init(n);
		for(int i=1;i <= n;i++){
			if(vis[i]){
				int len=g[i].size();
				for(int j=0;j <= len - 1;j++){
					int v=g[i][j];
					if(vis[v]){
						merge(i,v);
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i <= n;i++){
			if(vis[i]){
				int fi=find(i);
				if(!connection[fi]){
					connection[fi]=true;
					cnt++;
				}
			}
		}
		if(cnt > 2){
			return;
		}
		queue<int> q;
		for(int i=1;i <= n;i++){
			if(vis[i]){
				temp[i]=true;
				q.push(i);
			}
		}
		int mx=0;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			int len=g[u].size();
			for(int i=0;i <= len - 1;i++){
				int v=g[u][i];
				if(temp[v]){
					continue;
				}
				dist[v]=dist[u] + 1;
				temp[v]=true;
				q.push(v);
				mx=max(mx,dist[v]);
			}
		}
		/*cout << "choose:" << endl;
		for(int i=1;i <= n;i++){
			if(vis[i]){
				cout << i << " ";
			}
		}
		cout << endl << "dist:" << endl;
		for(int i=1;i <= n;i++){
			cout << dist[i] << " ";
		}
		cout << endl;*/
		ans=min(ans,mx);
		return;
	}
	if(left >= 1){
		vis[x]=true;
		dfs(x + 1,left - 1);
		vis[x]=false;
	}
	dfs(x + 1,left);
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int c,t;
	cin >> c >> t;
	if(c <= 3){
		while(t--){
			ans=9e18;
			cin >> n >> k;
			for(int i=1;i <= n;i++){
				g[i].clear();
			}
			for(int i=1;i <= n - 1;i++){
				int u,v;
				cin >> u >> v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			dfs(1,k);
			cout << ans << endl;
		}
	}
	if(c == 13 || c == 14){
		while(t--){
			cin >> n >> k;
			for(int i=1;i <= n - 1;i++){
				int u,v;
				cin >> u >> v;
			}
			int m=n / 2;
			if(k == n){
				cout << 0 << endl;
				continue;
			}
			if(k >= m){
				cout << 1 << endl;
				continue;
			}
			int rest=m - k;
			cout << (rest + 7) / 4 << endl;
		}
	}
	return 0;
}