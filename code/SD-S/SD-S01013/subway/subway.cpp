#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,c,m,dd,qq;
vector< pair<int,long long>  > v[N],d[N];
int a[505][N],k[505],t[505][N],tot;
bool vis[N];
long long dis[1005][1005],w[N];
priority_queue< pair<int,long long> ,vector< pair<int,long long> > ,greater< pair<int ,long long> > > q;
void dj(int x){
	q.push({0,x});
	memset(dis[x],0x7f,sizeof(dis[x]));
	dis[x][x]=0;
	memset(vis,0,sizeof(vis));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<v[u].size();i++){
			int xx=v[u][i].first;
			long long w=v[u][i].second;
			if(!vis[xx]&&dis[x][u]+w<dis[x][xx]){
				dis[x][xx]=dis[x][u]+w;
				q.push({dis[x][xx],xx});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0,sizeof(dis));
	scanf("%d %d %d %d %d",&c,&n,&m,&dd,&qq);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
			d[a[i][j]].push_back({++tot,t[i][j]});
			a[i][j]=tot;
			if(j>1){
				v[a[i][j]].push_back({a[i][j-1],0});
				v[a[i][j-1]].push_back({a[i][j],0});
			}
		}
	}
	for(int i=1;i<=n;i++){
		int l=d[i].size();
		for(int j=0;j<l;j++){
			int u=d[i][j].first;
			for(int p=j+1;p<l;p++){
				int uu=d[i][p].first;
				long long w=d[i][p].second+d[i][j].second;
				v[u].push_back({uu,w});
				v[uu].push_back({u,w});
			}
		}
	}
	while(qq--){
		int x,y;
		scanf("%d %d",&x,&y);
		long long minn=-1;
		for(int i=0;i<d[x].size();i++){
			int xx=d[x][i].first;
			long long wx=d[x][i].second;
			for(int j=0;j<d[y].size();j++){
				int yy=d[y][j].first;
				long long wy=d[y][j].second;
				if(!dis[xx][yy]) dj(xx);
				long long tmp=wy+wx+dis[xx][yy];
				if(minn==-1) minn=tmp;
				else minn=min(minn,tmp);
			}
		}
		minn+=w[x]+w[y];
		printf("%lld\n",minn);
	}
	return 0;
}
