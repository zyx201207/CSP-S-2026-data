#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node {
	int sta,tim;
};
const int M=5E5+2;
int w[M],q=M,x,y;
bool vis[M];
vector<Node>lu[52];
vector<int>dll[52];
void dfs(int g,int num) {
	if(g==y) {
		q=min(q,num);
		return;
	}
	vis[g]=1;
	for(auto f:dll[g]) {//找每一个有该站点的路线 
		for(auto d:lu[f]) {//找每一个可以到的站台 
			int dd=d.sta,tt=d.tim;
			if(vis[dd]) continue;
			dfs(dd,num+w[dd]+tt);
		}
	}
	vis[g]=0;
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,T;
	cin>>c>>n>>m>>d>>T;
	for(int i=1; i<=m; i++) cin>>w[i];
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int s,t;
			cin>>s>>t;
			lu[i].push_back(Node {s,t});
			dll[s].push_back(i);
		}
	}
	while(T--) {
		memset(vis,0,sizeof vis);
		cin>>x>>y;
		int ans=w[x]+w[y];
		dfs(x,0);
		cout<<ans+q<<'\n';
		q=M;
	}
	return 0;
}
