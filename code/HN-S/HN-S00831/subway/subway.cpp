#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
#define fi first
#define se second
int f[505][505];
vector<pr> a[500005];
int b[500005];
int d[505][505];
bool vis[505];
int n;
void dijstra(int st){
	priority_queue<pr, vector<pr>, greater<> > q;
	memset(vis, 0, sizeof vis);
	q.push({0, st});
	d[st][st]=0;
	while(!q.empty()){
		int u=q.top().se;
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int v=1;v<=n;v++){
			if(vis[v]) continue;
			if(d[st][v]>d[st][u]+f[u][v]){
				d[st][v]=d[st][u]+f[u][v];
				q.push({d[st][v], v});
			}
		}
	}
} 
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, m, xrz_like_moya, q;
	cin>>c>>n>>m>>xrz_like_moya>>q;
	memset(d, 0x3f, sizeof d);
	memset(f, 0x3f, sizeof f);
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++){
		int ycat;
		cin>>ycat;
		for(int jcat=1;jcat<=ycat;jcat++){
			int x, y;
			cin>>x>>y;
			for(auto j:a[x])
				f[i][j.fi]=f[j.fi][i]=min(f[i][j.fi], y+j.se);
			a[x].push_back({i, y});
		}
	}
	for(int i=1;i<=n;i++)
		dijstra(i);
	while(q--){
		int x, y;
		cin>>x>>y;
		int mi=LONG_LONG_MAX;
		for(auto i:a[x])
			for(auto j:a[y])
				mi=min(mi, i.se+j.se+b[x]+b[y]+d[i.fi][j.fi]);
		cout<<mi<<'\n';
	}
	return 0;
}

