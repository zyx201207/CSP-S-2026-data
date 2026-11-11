#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int c,t,n,k,mx,ans = INT_MAX;
bool x[N];
vector<int> ve[N];
int dis[35];
bool vis1[35];
void dfs1(int u,int fa){
	vis1[u] = 1;
	for (auto it : ve[u]){
		if (it == fa || x[it] == 0)continue;
		dfs1(it,u);
	}
}

void dfs2(int u,int fa,int s){
	dis[u] = min(dis[u],s);
	for (auto it : ve[u]){
		if (it == fa)continue;
		if (vis1[it] == 1)
			dfs2(it,u,0);
		else
			dfs2(it,u,s+1);
	}
}

void f1(int l,int cnt){
	if (cnt > k)return;
	if (l >= n){
		if (cnt == k){
			memset(vis1,0,sizeof vis1);
			memset(dis,0x7f,sizeof dis);
			int s = 0;
			for (int i = 1 ; i <= n ; i++){
				if (vis1[i] || x[i] == 0)continue;
				s++;
				dfs1(i,-1);
			}
			if (s > 2)return;
			mx = 0;
			for (int i = 1 ; i <= n ; i++){
				if (x[i] == 0)continue;
				dfs2(i,-1,0);
			}
			for (int i = 1 ; i <= n ; i++){
				mx = max(mx,dis[i]);
			}
			ans = min(ans,mx);
		}
		return;
	}
	x[l+1] = 1;
	f1(l+1,cnt+1);
	x[l+1] = 0;
	f1(l+1,cnt);
	
	return;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while (t--){
		ans = INT_MAX;
		cin >> n >> k;
		for (int i = 1 ; i <= n ; i++)ve[i].clear();
		for (int i = 1 ; i < n ; i++){
			int u,v;
			cin >> u >> v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		f1(0,0);
		cout << ans << endl;
	}
	return 0;
}
