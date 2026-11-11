/*
LUOGU UID 1208546
*/

#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e2+10,M=5e5+10;
const int INF=0x3f3f3f3f3f3f3f3f;
vector<pair<int,int>> a[M];
int f[N][N];
int w[M];
int c,n,m,q,d;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		f[i][i]=0;
		int siz;
		cin>>siz;
		for(int j=1;j<=siz;j++) {
			int orz1,orz2;
			cin>>orz1>>orz2;
			a[orz1].push_back({i,orz2});
		}
	}
	for(int i=1;i<=m;i++) {
		int siz=a[i].size();
		for(int j=0;j<siz;j++) {
			for(int k=j+1;k<siz;k++) {
				int u=a[i][j].first,v=a[i][k].first,w=a[i][j].second+a[i][k].second;
				f[u][v]=min(f[u][v],w);
				f[v][u]=min(f[v][u],w); 
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--) {
		int u,v;
		cin>>u>>v;
		int ans=INF;
		for(auto x:a[u]) {
			for(auto y:a[v]) {
				int st=x.first,ed=y.first;
				ans=min(ans,w[u]+w[v]+x.second+y.second+f[st][ed]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

