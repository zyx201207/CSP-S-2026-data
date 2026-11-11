#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
long long dis[N][N],lin[N][N];
long long w[M];
vector<int> a[M],t[M];
vector<pair<int,long long> > ll[N];
int c,n,m,d,qt;
priority_queue<pair<long long,int> > q;
bool vis[N];
void dij(int s){
	for(int i=1;i<=n;i++){
		dis[s][i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	dis[s][s]=0;
	q.push({0,s});
	while(!q.empty()){
		auto now=q.top();
		q.pop();
		int x=now.second;
		if(vis[x]){
			continue;
		}
		vis[x]=1;
		for(auto to:ll[x]){
			int y=to.first;
			long long quan=to.second;
			if(dis[s][x]+quan<dis[s][y]){
				dis[s][y]=dis[s][x]+quan;
				q.push({-dis[s][y],y});
			}
		} 
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&qt);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d %d",&x,&y);
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			lin[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		if(a[i].size()>1){
//			printf("%d\n",i);
			for(int x=0;x<a[i].size();x++){
				for(int y=x+1;y<a[i].size();y++){
					int nx=a[i][x];
					int ny=a[i][y];
					long long len=(long long)t[i][x]+t[i][y];
					lin[nx][ny]=min(lin[nx][ny],len);
					lin[ny][nx]=min(lin[ny][nx],len);
				}
			}
		}
	}
//	printf("1");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(lin[i][j]!=0x3f3f3f3f3f3f3f3f){
				ll[i].push_back({j,lin[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%d ",dis[i][j]);
//		}
//		printf("\n");
//	}
	while(qt--){
		int x,y;
		scanf("%d %d",&x,&y);
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				int xx=a[x][i];
				int yy=a[y][j];
				int tx=t[x][i];
				int ty=t[y][j];
				long long now=dis[xx][yy]+tx+ty;
				ans=min(ans,now); 
			}
		}
		ans=(ans+w[x]+w[y]);
		printf("%lld\n",ans);
	}
	return 0;
}

