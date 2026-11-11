#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
int c,n,m,d,qq,w[500005],t[500005],x,y,k,dis[500005],f[1001][1001];
struct bian {
	int x;
	int z;
};
vector<bian> G[500005];
struct node {
	int x;
	int z;
	bool operator < (const node rhs) const {
		return z>rhs.z;
	}
};
priority_queue<node> q;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>x>>y;
			G[m+i].push_back({x,y});
			G[x].push_back({m+i,y});
		}
	}
	if(c>=9&&c<=11) {
		memset(f,0x3f,sizeof f);
		for(int i=1;i<=m;i++) {
			f[i][i]=0;
			q.push({i,0});
			while(!q.empty()) {
				node t=q.top();q.pop();
				if(f[i][t.x]<t.z) continue;
				for(auto y:G[t.x]) {
					if(f[i][y.x]>f[i][t.x]+y.z) {
						f[i][y.x]=f[i][t.x]+y.z;
						q.push({y.x,f[i][y.x]});
					}
				}
			}
		}
		for(int i=1;i<=qq;i++) {
			cin>>x>>y;
			cout<<w[x]+w[y]+f[x][y]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=qq;i++) {
		cin>>x>>y;
		memset(dis,0x3f,sizeof dis);
		dis[x]=0;
		q.push({x,0});
		while(!q.empty()) {
			node t=q.top();q.pop();
			if(dis[t.x]<t.z) continue;
			for(auto y:G[t.x]) {
				if(dis[y.x]>dis[t.x]+y.z) {
					dis[y.x]=dis[t.x]+y.z;
					q.push({y.x,dis[y.x]});
				}
			}
		}
		cout<<w[x]+w[y]+dis[y]<<"\n";
	}
	return 0;
}