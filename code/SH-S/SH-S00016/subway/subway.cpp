#include<bits/stdc++.h>
#define int long long
using namespace std;
int w[500010],g[510][510];
vector<int> t[510],a[500010],d[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	int c,n,m,x,q;
	cin>>c>>n>>m>>x>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(i);
			d[u].push_back(v);
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)g[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=0;k<a[i].size();k++){
				g[a[i][j]][a[i][k]]=g[a[i][k]][a[i][j]]=min(g[a[i][j]][a[i][k]],d[i][j]+d[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=2e18;
		cin>>x>>y;
		for(int j=0;j<a[x].size();j++){
			for(int k=0;k<a[y].size();k++){
				ans=min(ans,w[x]+w[y]+d[x][j]+d[y][k]+g[a[x][j]][a[y][k]]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
