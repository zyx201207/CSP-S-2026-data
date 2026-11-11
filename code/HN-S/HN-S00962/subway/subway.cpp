#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+1,M=5e5+1;
int c,n,m,d,q,w[M],k[N],h[N][N],mi;
vector<pair<int,int> > a[M],G[N];
vector<int> t[M];
bool vis[N];
void dfs(int u,int p,int cnt,int y,int sum) {
	if(u==y) {
		mi=min(mi,sum);
		return ;
	}
	for(int i=0; i<t[u].size(); i++) {
		int o=0;
		for(int l=0; l<a[t[u][i]].size(); l++) {
			if(a[t[u][i]][l].first==u){
				o=a[t[u][i]][l].second;
				break;
			}
		}
		for(int l=0; l<a[t[u][i]].size(); l++) {
			if(vis[a[t[u][i]][l].first])continue;
			vis[a[t[u][i]][l].first]=1;
			dfs(a[t[u][i]][l].first,t[u][i],o,y,sum+a[t[u][i]][l].second+o);
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	bool ok=0;
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1,id,p; j<=k[i]; j++) {
			cin>>id>>p;
			a[i].push_back({id,p});
			t[id].push_back(i);
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		mi=1e18;
		for(int i=0; i<t[x].size(); i++) {
			memset(vis,0,sizeof(vis));
			vis[x]=1;
			int p=0;
			for(int j=0;j<a[t[x][i]].size();j++){
				if(a[t[x][i]][j].first==x){
					p=a[t[x][i]][j].second;
					break;
				}
			}
			dfs(x,t[x][i],p,y,0);
		}
		cout<<mi+w[x]+w[y]<<endl;
	}
	return 0;
}
