#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int c,n,m,d,q;
const int M=5e5+10,N=510;
int w[M];
vector<pair<int,int> >g[M];
long long f[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			g[x].push_back(make_pair(i,t));
		}
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++)
		for(int k=j+1;k<g[i].size();k++){
			int u=g[i][j].fi,v=g[i][k].fi;long long cost=g[i][j].se+g[i][k].se;
			f[u][v]=f[v][u]=min(f[u][v],cost);
		}
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	if(i!=k)
	for(int j=1;j<=n;j++)
	if(i!=j&&j!=k) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int x,y;long long ans=1e18;
		cin>>x>>y;
	    for(int i=0;i<g[x].size();i++)
	        for(int j=0;j<g[y].size();j++){
	        	int u=g[x][i].fi,v=g[y][j].fi;long long cost=g[x][i].se+g[y][j].se;
	        	ans=min(ans,w[x]+w[y]+cost+f[u][v]);
			}
		cout<<ans<<'\n';
	}
	return 0;
}