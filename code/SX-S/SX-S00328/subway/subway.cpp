#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define int long long
using namespace std;
const int N=505,M=1e3+5,K=5e5+5;
int w[M],k[N],a[M],t[M];
int dis[M][M],dist[M][M];
int aa[5][K],ds[5][K];
bool vis[M],is[K][5];
vector<pii>g[M];
int c,n,m,d,q;
int read(){
    int ans=0,f=1;
    char s=getchar();
    if(s=='-'){
        f=-1;
        s=getchar();
    }
    while(s>='0'&&s<='9'){
        ans=ans*10+s-'0';
        s=getchar();
    }
    return ans*f;
}
void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	for(int i=1;i<=m;i++)vis[i]=0,dist[s][i]=0x3f3f3f3f3f3f3f3f;
	dist[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().se;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(pii x:g[u]){
			int v=x.fi,w=x.se;
			if(dist[s][v]>dist[s][u]+w){
				dist[s][v]=dist[s][u]+w;
				q.push({dist[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int x,y;
	cin>>c>>n>>m>>d>>q;
	if(c==20||c==21){
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				cin>>aa[i][j]>>t[j];
				ds[i][aa[i][j]]=t[j];
				is[aa[i][j]][i]=1;
			}
		}
		int mn=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=m;i++)if(is[i][1]&&is[i][2])mn=min(mn,ds[1][i]+ds[2][i]);
		while(q--){
			cin>>x>>y;
			int ans=0x3f3f3f3f3f3f3f3f;
			if(is[x][1]&&is[y][1])ans=ds[1][x]+ds[1][y];
			if(is[x][2]&&is[y][2])ans=min(ans,ds[2][x]+ds[2][y]);
			if(is[x][1]&&is[y][2])ans=min(ans,ds[1][x]+ds[2][y]+mn);
			if(is[x][2]&&is[y][1])ans=min(ans,ds[2][x]+ds[1][y]+mn);
		}
	}
	else{
		for(int i=1;i<=m;i++)cin>>w[i];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++)dis[i][j]=0x3f3f3f3f3f3f3f3f;
		}
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++)cin>>a[j]>>t[j];
			for(int j=1;j<=k[i];j++){
				for(int l=j+1;l<=k[i];l++){
					dis[a[j]][a[l]]=min(dis[a[j]][a[l]],t[j]+t[l]);
					dis[a[l]][a[j]]=min(dis[a[l]][a[j]],t[l]+t[j]);
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(dis[i][j]!=0x3f3f3f3f3f3f3f3f)g[i].push_back({j,dis[i][j]});
			}
		}
		for(int i=1;i<=m;i++){
			dijkstra(i);
		//	for(int j=1;j<=m;j++)cout<<i<<' '<<j<<' '<<dist[i][j]<<'\n';
		}
		while(q--){
			cin>>x>>y;
			cout<<w[x]+w[y]+dist[x][y]<<'\n';
		}
	}

	return 0;
}
/*
20 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



*/