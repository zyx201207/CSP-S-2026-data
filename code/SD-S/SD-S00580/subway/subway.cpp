#include<bits/stdc++.h>
using namespace std;

const int M=5e5+10;
const int N=550;

int c,n,m,d,q;
long long w[M];
long long dist[N][N];
struct Node{
	int id;
	long long w;
};
vector<Node>g[M];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dist,0x3f,sizeof dist);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) {
		dist[i][i]=0;
		int k,u,v;
		cin>>k;
		for(int j=1;j<=k;j++) {
			cin>>u>>v;
			g[u].push_back({i,v});
		}
	}
	for(int i=1;i<=m;i++) {
		for(Node u:g[i]) {
			for(Node v:g[i]) {
				dist[u.id][v.id]=min(dist[u.id][v.id],u.w+v.w);
				dist[v.id][u.id]=min(dist[v.id][u.id],u.w+v.w);
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			for(int k=1;k<=n;k++) {
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(Node u:g[x]) {
			for(Node v:g[y]) {
				ans=min(ans,dist[u.id][v.id]+u.w+v.w);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
} 
