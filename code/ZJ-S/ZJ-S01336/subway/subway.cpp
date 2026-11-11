#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int N=5e5+7;
int c,n,m,D,q;
ll dis[507][507];
int w[N],len[N];
struct node{
	int x,w;
}a[N][23];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int l;cin>>l;
		while(l--){
			int u,t;cin>>u>>t;
			a[u][++len[u]]=(node){i,t};
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)dis[i][j]=inf;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=len[i];j++)
		for(int k=j+1;k<=len[i];k++){
			int u=a[i][j].x,v=a[i][k].x;
			dis[u][v]=min(dis[u][v],1ll*a[i][j].w+1ll*a[i][k].w);
			dis[v][u]=dis[u][v];
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
	        for(int j=1;j<=n;j++)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y;cin>>x>>y;
		ll res=inf;
		for(int i=1;i<=len[x];i++)
		for(int j=1;j<=len[y];j++){
			int u=a[x][i].x,v=a[y][j].x;
			res=min(res,dis[u][v]+a[x][i].w+a[y][j].w);
		}
		cout<<res+w[x]+w[y]<<"\n";
	}
}

