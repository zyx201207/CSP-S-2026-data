#include<bits/stdc++.h>
#define int long long
using namespace std;
struct stu{int v,w;};
int c,n,m,d,q,w[500005],dis[505][505],x,y,k[505],a[505][505],ans,t[505][505]; vector<stu> v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>c>>n>>m>>d>>q; //n<=500,m<=5e5
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];for(int j=1;j<=k[i];j++) cin>>x>>y,t[i][j]=y,a[i][j]=x,v[x].push_back({i,j});
	}memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++){
		int len=v[i].size();
		for(int j=0;j<len;j++) for(int k=j+1;k<len;k++){//O(m*d)
			int x=v[i][j].v,y=v[i][k].v; dis[x][y]=min(dis[x][y],t[x][v[i][j].w]+t[y][v[i][k].w]);
	}}for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int K=1;K<=n;K++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)//Floyd O(n^3)
		dis[i][j]=min(dis[i][K]+dis[K][j],dis[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[j][i]);
	while(q--){//O(d^2 q)
		cin>>x>>y,ans=1e18;
		for(int i=0;i<v[x].size();i++) for(int j=0;j<v[y].size();j++)
			ans=min(ans,w[x]+w[y]+t[v[x][i].v][v[x][i].w]+t[v[y][j].v][v[y][j].w]+dis[v[x][i].v][v[y][j].v]);
		cout<<ans<<'\n';
	}
}
