//subway
#include<bits/stdc++.h>
#define int long long
const int N=650,M=5e5+100;
using namespace std;
int T,n,m,d,qus,g[5][M],w[M];
int mp[1100][1100];
struct node {
	int v,w;

	bool operator <( const node& x)const {
		return x.w<w;
	}
};
vector<node>t[M+N];
int dj(int u,int v) {

	int dis[n+m+100];
	bool flag[n+m+100];
	memset(dis,0x3f,sizeof dis);
	memset(flag,false,sizeof flag);
	priority_queue<node> q;
	q.push({u,0});
	while(!q.empty()) {
		node o=q.top();
		q.pop();
		if(flag[o.v])continue;

		flag[o.v]=true;
		if(T<=11)mp[o.v][u]=mp[u][o.v]=o.w;
		if(o.v==v)return o.w;

		for(int i=0; i<t[o.v].size(); i++) {
			if(flag[t[o.v][i].v])continue;
			if(dis[t[o.v][i].v]>o.w+t[o.v][i].w)dis[t[o.v][i].v]=o.w+t[o.v][i].w,q.push({t[o.v][i].v,dis[t[o.v][i].v]});
		}
	}
	return dis[v];
}

signed main() {

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>T>>n>>m>>d>>qus;

	if(T<=3) { //floyd
		int t[30][30],f[30][30][30];
		memset(t,0x3f,sizeof t);
		memset(f,0x3f,sizeof f);
		for(int i=1; i<=n+m; i++)t[i][i]=0;
		for(int i=1; i<=m; i++)cin>>w[i];
		for(int i=1; i<=n; i++) {
			int q;
			cin>>q;
			for(int j=1; j<=q; j++) {
				int u,v;
				cin>>u>>v;
				t[i+m][u]=t[u][i+m]=v;
			}
		}

		for(int k=1; k<=n+m; k++) {
			for(int i=1; i<=n+m; i++) {
				for(int j=1; j<=n+m; j++) {
					f[i][k][j]=t[i][k]+t[k][j];
					t[i][j]=min(t[i][j],f[i][k][j]);
				}
			}
		}

		for(int i=1; i<=qus; i++) {
			int u,v;
			cin>>u>>v;
			cout<<w[u]+w[v]+t[u][v]<<"\n";
		}
		return 0;
	}
	
	if(T==20||T==21||n<=2) {
		int minn=1e9;
		memset(g,0x3f,sizeof g);
		for(int i=1; i<=m; i++)cin>>w[i];
		for(int i=1; i<=n; i++) {
			int q;
			cin>>q;
			for(int j=1; j<=q; j++) {
				int u,v;
				cin>>u>>v;
				g[i][u]=v;
			}
		}

		if(n==1) {
			for(int i=1; i<=qus; i++) {
				int u,v;
				cin>>u>>v;
				cout<<w[u]+w[v]+g[1][u]+g[1][v]<<"\n";
			}
			return 0;
		}

		for(int i=1; i<=m; i++)minn=min(minn,g[1][i]+g[2][i]);

		for(int i=1; i<=qus; i++) {
			int u,v;
			cin>>u>>v;
			cout<<w[u]+w[v]+min(g[1][u]+g[1][v],min(g[2][u]+g[2][v],minn+min(g[1][u]+g[2][v],g[2][u]+g[1][v])))<<"\n";
		}
		return 0;
	}



	if(T<=11)memset(mp,-1,sizeof mp);

	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1; i<=n; i++) {
		int q;
		cin>>q;
		for(int j=1; j<=q; j++) {
			int u,v;
			cin>>u>>v;
			t[u].push_back({i+m,v});
			t[i+m].push_back({u,v});
		}
	}

	for(int i=1; i<=qus; i++) {
		int u,v;
		cin>>u>>v;
		if(T<=11&&mp[u][v]!=-1) {
			cout<<w[u]+w[v]+mp[u][v]<<"\n";
			continue;
		}
		cout<<w[u]+w[v]+dj(u,v)<<"\n";
	}
	return 0;
}
