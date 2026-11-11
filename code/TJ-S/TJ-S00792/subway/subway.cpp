#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int c,n,m,D,q;
int a[N];
struct Node {
	int id;
	int w;
};
vector<Node> d[N];
ll e[510][510];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1; i<=m; i++) cin>>a[i];
	memset(e,0x3f,sizeof e);

	for(int i=1; i<=n; i++) {
		int t,x,y;
		cin>>t;
		for(int j=1; j<=t; j++) {
			cin>>x>>y;
			for(int ti=0; ti<d[x].size(); ti++) {
				Node tmp=d[x][ti];
				e[i][tmp.id]=e[tmp.id][i]=min(e[tmp.id][i], (long long)tmp.w+y);
			}
			d[x].push_back(Node{i,y});
		}
	}
	for(int i=1; i<=n; i++) e[i][i]=0;
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				ll tmp=e[i][k]+e[k][j];
				if(tmp<e[i][j])
					e[j][i]=e[i][j]=tmp;
			}
		}
	}
	while(q--) {
		int u,v;
		cin>>u>>v;
		ll ans=1e18;
		for(int i=0; i<d[u].size(); i++) {
			Node tmp1=d[u][i];
			for(int j=0; j<d[v].size(); j++) {
				Node tmp2=d[v][j];
				ans=min(ans,e[tmp1.id][tmp2.id]+tmp1.w+tmp2.w);
			}
		}
		cout<<ans+a[u]+a[v]<<endl;
	}
	return 0;
}
