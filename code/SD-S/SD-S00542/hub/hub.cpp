#include<bits/stdc++.h>
#define ll long long
#define For(i, j, k) for(int i=j;i<=k;i++)
using namespace std;

const int N = 100;

int n, m, vis[N], dis[N], vis1[N], q[1000005];
vector<int> e[N];
int ans;

void dfs2(int u){
	if(vis1[u]==0)return;
	vis1[u] = 0;
	for(auto v : e[u]){
		dfs2(v);
	}
}

void dfs(int ii,int k){
	if(ii==m+1){
		int l = 1, r = 0;
		memset(dis,0x3f,sizeof dis);
		For(i, 1, n){
			if(vis[i]){
				q[++r] = i;
				dis[i] = 0;
				vis1[i] = vis[i];
			}
		}
		int tot = 0;
		For(i, 1, n){
			if(vis1[i]){
				dfs2(i);
				tot++;
			}
		}
		if(tot>2)return;
		int num = 0;
		while(l<=r){
			for(auto v : e[q[l]]){
				if(dis[v]<0x3f3f3f3f)continue;
				dis[v] = dis[q[l]]+1;
				num = max(num, dis[v]);
				q[++r] = v;
			}
			l++;
		}
//		For(i, 1, n)cout << dis[i] << " ";
//		cout << "\n";
		ans = min(ans, num);
		return;
	}
	For(i, k+1, n-(m-ii)+1){
		vis[i] = 1;
		dfs(ii+1,i);
		vis[i] = 0;
	} 
}

void solve(){
	cin >> n >> m;
	For(i, 1, n)e[i].clear();
	For(i, 1, n-1){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ans = 0x3f3f3f3f;
	dfs(1, 0);
	cout << ans << "\n";
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


*/


