#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int LOG=20;
int dep[1000005];
vector<int> a[1000005];
int up[LOG][1000005];
int n;
void bfs(int r) {
	queue<int> q;
	dep[r]=0;
	up[0][r]=0;
	q.push(r);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for (int i=0;i<a[u].size();i++) {
			if (up[0][u] != a[u][i]){
				up[0][a[u][i]]=u;
				dep[a[u][i]]=dep[u]+1;
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=0;j<LOG;j++) {
			up[j][i] = up[j-1][up[j-i][i]];
		}
	}
}
int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	int dis=dep[x]-dep[y];
	for (int i=0;i<LOG;i++) {
		if (dis&(1<<i)) {
			x = up[i][x];
		}
	}
	if (x==y) return x;
	for (int i=LOG-1;i>=0;i--) {
		if (up[i][x]!=up[i][y]) {
			x = up[i][x];
			y = up[i][y];
		}
	}
	return up[0][x];
}
int c,t,k;
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--) {
		memset(up,0,sizeof(up));
		memset(dep,0,sizeof(dep));
		for (int i=0;i<=1000003;i++) {
			a[i].clear();
		}
		cin >> n >> k;
		for (int i=1;i<=n-i;i++) {
			int u,v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		bfs(1);
		int maxn=-1;
			for (ll i=1;i<=(1<<n);i++) {
				int cnt=0;
				for (int j=0;j<=62;j++) {
					if (i&(1<<j)) {
						cnt++;
					}
				}
				if (cnt==k) {
					for(int j=1;j<=n;j++) {
						int minn=1000005;
						for (int k=1;k<=62;k++) {
							if (i&(1<<k)) {
								int dis=2*dep[lca(k,j)]-dep[j]-dep[k];
								if (dis<minn) {
									minn=dis;
								}
							}
						}
						if (minn>maxn) {
							maxn=minn;
						}
					}
				
				}
			}
			cout << maxn << "\n";
		
	}
	return 0;
}
